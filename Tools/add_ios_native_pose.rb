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

# The Homuler Unity package embeds a full MediaPipe runtime. Loading it beside
# MediaPipeTasksVision registers the same GPU buffer types twice and crashes in
# dyld initializers before Unity starts.
legacy_refs = project.files.select { |item| item.path.to_s.end_with?('MediaPipeUnity.framework') }
project.targets.each do |item|
  item.build_phases.each do |phase|
    phase.files.select { |build_file| legacy_refs.include?(build_file.file_ref) }.each(&:remove_from_project)
  end
end
legacy_refs.each(&:remove_from_project)
FileUtils.rm_rf(File.join(File.dirname(project_path), 'Frameworks', 'com.github.homuler.mediapipe', 'Runtime', 'Plugins', 'iOS', 'MediaPipeUnity.framework'))

%w[Metal OpenGLES UIKit].each do |name|
  path = "System/Library/Frameworks/#{name}.framework"
  reference = project.files.find { |item| item.path == path }
  reference ||= project.frameworks_group.new_file(path)
  target.frameworks_build_phase.add_file_reference(reference, true) unless target.frameworks_build_phase.files_references.include?(reference)
end

destination_dir = File.join(File.dirname(project_path), 'Libraries', 'Plugins', 'iOS')
FileUtils.mkdir_p(destination_dir)
destination = File.join(destination_dir, File.basename(source_path))
FileUtils.cp(source_path, destination)

relative = destination.delete_prefix(File.dirname(project_path) + File::SEPARATOR).tr('\\', '/')
reference = project.files.find { |item| item.path == relative }
reference ||= project.main_group.new_file(relative)
target.add_file_references([reference]) unless target.source_build_phase.files_references.include?(reference)
project.save
abort 'Legacy MediaPipeUnity.framework is still linked' if project.files.any? { |item| item.path.to_s.end_with?('MediaPipeUnity.framework') }
raw = File.join(File.dirname(project_path), 'Data', 'Raw')
FileUtils.mkdir_p(raw)
%w[pose_landmarker_full.bytes hand_landmarker.task face_landmarker.task].each do |name|
  source = File.join('Assets', 'StreamingAssets', name)
  abort "Missing model: #{source}" unless File.file?(source) && File.size(source) > 1024
  FileUtils.cp(source, File.join(raw, name))
end
