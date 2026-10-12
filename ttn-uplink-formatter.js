function decodeUplink(input) {
  var bytes = input.bytes;
  var data = {};
  var i = 0;

  while (i < bytes.length) {
    var channel = bytes[i++];
    var type = bytes[i++];

    // Temperature
    if (type === 103) {
      var raw = (bytes[i] << 8) | bytes[i + 1];
      i += 2;

      if (raw & 0x8000) {
        raw -= 0x10000;
      }

      data.temperature = raw / 10.0;
    }

    // Humidity
    else if (type === 104) {
      var rawHumidity = bytes[i++];
      data.humidity = rawHumidity / 2.0;
    }

    else {
      return {
        data: data,
        errors: ["Unknown AaadLPP type: " + type]
      };
    }
  }

  return {
    data: data
  };
}