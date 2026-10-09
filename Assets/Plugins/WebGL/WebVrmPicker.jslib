mergeInto(LibraryManager.library, {
  WebPwaSettings_SetAvatarStatus: function (messagePtr) {
    window.dispatchEvent(new CustomEvent('webvrm-status', { detail: UTF8ToString(messagePtr) }));
  },

  WebVrmPicker_Open: function (gameObjectNamePtr) {
    var gameObjectName = UTF8ToString(gameObjectNamePtr);
    var picker = document.createElement('input');
    picker.type = 'file';
    picker.accept = '.vrm,application/octet-stream';
    picker.style.display = 'none';
    document.body.appendChild(picker);
    picker.onchange = function () {
      var file = picker.files && picker.files[0];
      if (!file) {
        document.body.removeChild(picker);
        return;
      }
      var reader = new FileReader();
      reader.onload = function () {
        window.__webVrmPickerBytes = new Uint8Array(reader.result);
        window.__webVrmPickerName = file.name;
        SendMessage(gameObjectName, 'OnVrmFilePicked', file.name);
        document.body.removeChild(picker);
      };
      reader.onerror = function () {
        window.__webVrmPickerBytes = null;
        SendMessage(gameObjectName, 'OnVrmFilePicked', '');
        document.body.removeChild(picker);
      };
      reader.readAsArrayBuffer(file);
    };
    picker.click();
  },

  WebVrmPicker_GetSelectedSize: function () {
    return window.__webVrmPickerBytes ? window.__webVrmPickerBytes.length : 0;
  },

  WebVrmPicker_ClearSelected: function () {
    window.__webVrmPickerBytes = null;
    window.__webVrmPickerName = null;
  },

  WebVrmPicker_ReadChunk: function (offset, length) {
    var bytes = window.__webVrmPickerBytes;
    if (!bytes || offset < 0 || length < 0 || offset + length > bytes.length) return stringToNewUTF8('');
    var end = offset + length;
    var parts = [];
    for (var start = offset; start < end; start += 0x8000) {
      var chunk = bytes.subarray(start, Math.min(start + 0x8000, end));
      parts.push(String.fromCharCode.apply(null, chunk));
    }
    return stringToNewUTF8(btoa(parts.join('')));
  }
});
