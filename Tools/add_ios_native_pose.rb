require 'fileutils'
require 'xcodeproj'

project_path, source_path = ARGV
abort 'usage: add_ios_native_pose.rb Unity-iPhone.xcodeproj NativePoseBridge.mm' unless project_path && source_path

# Adding Objective-C++ cannot update Unity's compiled C# player.
generated = Dir.glob(File.join(File.dirname(project_path), '**', '*.cpp'))
required = %w[OnNativePoseJson IOSDebugOverlay]
generated.each do |file|
  text = File.read(file)
  required.reject! { |symbol| text.include?(symbol) }
  break if required.empty?
end
abort "Outdated Unity export (missing #{required.join(', ')}). Run Unity: Build > Export updated iOS project, then commit Builds/iOS." unless required.empty?

project = Xcodeproj::Project.open(project_path)
target = project.targets.find { |item| item.name == 'UnityFramework' }
abort 'UnityFramework target not found' unless target

destination_dir = File.join(File.dirname(project_path), 'Libraries', 'Plugins', 'iOS')
FileUtils.mkdir_p(destination_dir)
destination = File.join(destination_dir, File.basename(source_path))
FileUtils.cp(source_path, destination)

relative = destination.delete_prefix(File.dirname(project_path) + File::SEPARATOR).tr('\\', '/')
reference = project.files.find { |item| item.path == relative }
reference ||= project.main_group.new_file(relative)
target.add_file_references([reference]) unless target.source_build_phase.files_references.include?(reference)
project.save
raw = File.join(File.dirname(project_path), 'Data', 'Raw')
FileUtils.mkdir_p(raw)
%w[pose_landmarker_full.bytes hand_landmarker.task face_landmarker.task].each do |name|
  source = File.join('Assets', 'StreamingAssets', name)
  abort "Missing model: #{source}" unless File.file?(source) && File.size(source) > 1024
  FileUtils.cp(source, File.join(raw, name))
end
