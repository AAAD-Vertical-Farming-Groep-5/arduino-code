// Adapted from https://developer.mbed.org/teams/myDevicesIoT/code/Cayenne-LPP/

// Copyright © 2017 The Things Network
// Use of this source code is governed by the MIT license that can be found in the LICENSE file.
// 
// This library is enhanced with extra environment types

#include "AaadLPP.h"

// ----------------------------------------------------------------------------

AaadLPP::AaadLPP(uint8_t size) : _maxsize(size) {
  _buffer = (uint8_t *)malloc(size);
  _cursor = 0;
}

AaadLPP::~AaadLPP(void) {
  free(_buffer);
}

void AaadLPP::reset(void) {
  _cursor = 0;
}

uint8_t AaadLPP::getSize(void) {
  return _cursor;
}

uint8_t *AaadLPP::getBuffer(void) {
  return _buffer;
}

uint8_t AaadLPP::copy(uint8_t *dst) {
  memcpy(dst, _buffer, _cursor);
  return _cursor;
}

uint8_t AaadLPP::getError() {
  uint8_t error = _error;
  _error = LPP_ERROR_OK;
  return error;
}

// ----------------------------------------------------------------------------

bool AaadLPP::isType(uint8_t type) {
  if (LPP_DIGITAL_INPUT == type) return true;
  if (LPP_DIGITAL_OUTPUT == type) return true;
  if (LPP_ANALOG_INPUT == type) return true;
  if (LPP_ANALOG_OUTPUT == type) return true;
  if (LPP_GENERIC_SENSOR == type) return true;
  if (LPP_LUMINOSITY == type) return true;
  if (LPP_PRESENCE == type) return true;
  if (LPP_TEMPERATURE == type) return true;
  if (LPP_RELATIVE_HUMIDITY == type) return true;
  if (LPP_ACCELEROMETER == type) return true;
  if (LPP_BAROMETRIC_PRESSURE == type) return true;
  if (LPP_VOLTAGE == type) return true;
  if (LPP_CURRENT == type) return true;
  if (LPP_FREQUENCY == type) return true;
  if (LPP_PERCENTAGE == type) return true;
  if (LPP_ALTITUDE == type) return true;
  if (LPP_POWER == type) return true;
  if (LPP_DISTANCE == type) return true;
  if (LPP_ENERGY == type) return true;
  if (LPP_DIRECTION == type) return true;
  if (LPP_UNIXTIME == type) return true;
  if (LPP_GYROMETER == type) return true;
  if (LPP_GPS == type) return true;
  if (LPP_SWITCH == type) return true;
  if (LPP_CONCENTRATION == type) return true;
  if (LPP_COLOUR == type) return true;
  // AAAd specific types
  if (LPP_CO2 == type) return true;
  if (LPP_NOISE == type) return true;
  if (LPP_LIGHT == type) return true;
  if (LPP_CONDUCTIVITY == type) return true;
  if (LPP_WEIGHT == type) return true;
  if (LPP_TDS == type) return true;
  if (LPP_ANGLE == type) return true;
  return false;
}

const char * AaadLPP::getTypeName(uint8_t type) {
  if (LPP_DIGITAL_INPUT == type) return "digital_in";
  if (LPP_DIGITAL_OUTPUT == type) return "digital_out";
  if (LPP_ANALOG_INPUT == type) return "analog_in";
  if (LPP_ANALOG_OUTPUT == type) return "analog_out";
  if (LPP_GENERIC_SENSOR == type) return "generic";
  if (LPP_LUMINOSITY == type) return "luminosity";
  if (LPP_PRESENCE == type) return "presence";
  if (LPP_TEMPERATURE == type) return "temperature";
  if (LPP_RELATIVE_HUMIDITY == type) return "humidity";
  if (LPP_ACCELEROMETER == type) return "accelerometer";
  if (LPP_BAROMETRIC_PRESSURE == type) return "pressure";
  if (LPP_VOLTAGE == type) return "voltage";
  if (LPP_CURRENT == type) return "current";
  if (LPP_FREQUENCY == type) return "frequency";
  if (LPP_PERCENTAGE == type) return "percentage";
  if (LPP_ALTITUDE == type) return "altitude";
  if (LPP_POWER == type) return "power";
  if (LPP_DISTANCE == type) return "distance";
  if (LPP_ENERGY == type) return "energy";
  if (LPP_DIRECTION == type) return "direction";
  if (LPP_UNIXTIME == type) return "time";
  if (LPP_GYROMETER == type) return "gyrometer";
  if (LPP_GPS == type) return "gps";
  if (LPP_SWITCH == type) return "switch";
  if (LPP_CONCENTRATION == type) return "concentration";
  if (LPP_COLOUR == type) return "colour";
  // AAAd specific types
  if (LPP_CO2 == type) return "co2";
  if (LPP_NOISE == type) return "noise";
  if (LPP_LIGHT == type) return "light";
  if (LPP_CONDUCTIVITY == type) return "conductivity";
  if (LPP_WEIGHT == type) return "weight";
  if (LPP_TDS == type) return "tds";
  if (LPP_ANGLE == type) return "angle";
  return 0;
}

uint8_t AaadLPP::getTypeSize(uint8_t type) {
  if (LPP_DIGITAL_INPUT == type) return LPP_DIGITAL_INPUT_SIZE;
  if (LPP_DIGITAL_OUTPUT == type) return LPP_DIGITAL_OUTPUT_SIZE;
  if (LPP_ANALOG_INPUT == type) return LPP_ANALOG_INPUT_SIZE;
  if (LPP_ANALOG_OUTPUT == type) return LPP_ANALOG_OUTPUT_SIZE;
  if (LPP_GENERIC_SENSOR == type) return LPP_GENERIC_SENSOR_SIZE;
  if (LPP_LUMINOSITY == type) return LPP_LUMINOSITY_SIZE;
  if (LPP_PRESENCE == type) return LPP_PRESENCE_SIZE;
  if (LPP_TEMPERATURE == type) return LPP_TEMPERATURE_SIZE;
  if (LPP_RELATIVE_HUMIDITY == type) return LPP_RELATIVE_HUMIDITY_SIZE;
  if (LPP_ACCELEROMETER == type) return LPP_ACCELEROMETER_SIZE;
  if (LPP_BAROMETRIC_PRESSURE == type) return LPP_BAROMETRIC_PRESSURE_SIZE;
  if (LPP_VOLTAGE == type) return LPP_VOLTAGE_SIZE;
  if (LPP_CURRENT == type) return LPP_CURRENT_SIZE;
  if (LPP_FREQUENCY == type) return LPP_FREQUENCY_SIZE;
  if (LPP_PERCENTAGE == type) return LPP_PERCENTAGE_SIZE;
  if (LPP_ALTITUDE == type) return LPP_ALTITUDE_SIZE;
  if (LPP_POWER == type) return LPP_POWER_SIZE;
  if (LPP_DISTANCE == type) return LPP_DISTANCE_SIZE;
  if (LPP_ENERGY == type) return LPP_ENERGY_SIZE;
  if (LPP_DIRECTION == type) return LPP_DIRECTION_SIZE;
  if (LPP_UNIXTIME == type) return LPP_UNIXTIME_SIZE;
  if (LPP_GYROMETER == type) return LPP_GYROMETER_SIZE;
  if (LPP_GPS == type) return LPP_GPS_SIZE;
  if (LPP_SWITCH == type) return LPP_SWITCH_SIZE;
  if (LPP_CONCENTRATION == type) return LPP_CONCENTRATION_SIZE;
  if (LPP_COLOUR == type) return LPP_COLOUR_SIZE;
   // AAAd specific types
  if (LPP_CO2 == type) return LPP_CO2_SIZE;
  if (LPP_NOISE == type) return LPP_NOISE_SIZE;
  if (LPP_LIGHT == type) return LPP_LIGHT_SIZE;
  if (LPP_CONDUCTIVITY == type) return LPP_CONDUCTIVITY_SIZE;
  if (LPP_WEIGHT == type) return LPP_WEIGHT_SIZE;
  if (LPP_TDS == type) return LPP_TDS_SIZE;
  if (LPP_ANGLE == type) return LPP_ANGLE_SIZE;
  return 0;
}

uint32_t AaadLPP::getTypeMultiplier(uint8_t type) {
  if (LPP_DIGITAL_INPUT == type) return LPP_DIGITAL_INPUT_MULT;
  if (LPP_DIGITAL_OUTPUT == type) return LPP_DIGITAL_OUTPUT_MULT;
  if (LPP_ANALOG_INPUT == type) return LPP_ANALOG_INPUT_MULT;
  if (LPP_ANALOG_OUTPUT == type) return LPP_ANALOG_OUTPUT_MULT;
  if (LPP_GENERIC_SENSOR == type) return LPP_GENERIC_SENSOR_MULT;
  if (LPP_LUMINOSITY == type) return LPP_LUMINOSITY_MULT;
  if (LPP_PRESENCE == type) return LPP_PRESENCE_MULT;
  if (LPP_TEMPERATURE == type) return LPP_TEMPERATURE_MULT;
  if (LPP_RELATIVE_HUMIDITY == type) return LPP_RELATIVE_HUMIDITY_MULT;
  if (LPP_ACCELEROMETER == type) return LPP_ACCELEROMETER_MULT;
  if (LPP_BAROMETRIC_PRESSURE == type) return LPP_BAROMETRIC_PRESSURE_MULT;
  if (LPP_VOLTAGE == type) return LPP_VOLTAGE_MULT;
  if (LPP_CURRENT == type) return LPP_CURRENT_MULT;
  if (LPP_FREQUENCY == type) return LPP_FREQUENCY_MULT;
  if (LPP_PERCENTAGE == type) return LPP_PERCENTAGE_MULT;
  if (LPP_ALTITUDE == type) return LPP_ALTITUDE_MULT;
  if (LPP_POWER == type) return LPP_POWER_MULT;
  if (LPP_DISTANCE == type) return LPP_DISTANCE_MULT;
  if (LPP_ENERGY == type) return LPP_ENERGY_MULT;
  if (LPP_DIRECTION == type) return LPP_DIRECTION_MULT;
  if (LPP_UNIXTIME == type) return LPP_UNIXTIME_MULT;
  if (LPP_GYROMETER == type) return LPP_GYROMETER_MULT;
  if (LPP_SWITCH == type) return LPP_SWITCH_MULT;
  if (LPP_CONCENTRATION == type) return LPP_CONCENTRATION_MULT;
  if (LPP_COLOUR == type) return LPP_COLOUR_MULT;
  // AAAd specific data types
  if (LPP_CO2 == type) return LPP_CO2_MULT;
  if (LPP_NOISE == type) return LPP_NOISE_MULT;   
  if (LPP_LIGHT == type) return LPP_LIGHT_MULT;   
  if (LPP_CONDUCTIVITY == type) return LPP_CONDUCTIVITY_MULT; 
  if (LPP_WEIGHT == type) return LPP_WEIGHT_MULT;
  if (LPP_TDS == type) return LPP_TDS_MULT;
  if (LPP_ANGLE == type) return LPP_ANGLE_MULT;
  return 0;
}

bool AaadLPP::getTypeSigned(uint8_t type) {
  if (LPP_ANALOG_INPUT == type) return true;
  if (LPP_ANALOG_OUTPUT == type) return true;
  if (LPP_TEMPERATURE == type) return true;
  if (LPP_ACCELEROMETER == type) return true;
  if (LPP_ALTITUDE == type) return true;
  if (LPP_GYROMETER == type) return true;
  if (LPP_GPS == type) return true;
  if (LPP_ANGLE == type) return true;
  return false;
}

// ----------------------------------------------------------------------------

template <typename T> uint8_t AaadLPP::addField(uint8_t type, uint8_t channel, T value) {

  // Check type
  if (!isType(type)) {
    _error = LPP_ERROR_UNKOWN_TYPE;
    return 0;
  }

  // Type definition
  uint8_t size = getTypeSize(type);
  uint32_t multiplier = getTypeMultiplier(type);
  bool is_signed = getTypeSigned(type);

  // check buffer overflow
  if ((_cursor + size + 2) > _maxsize) {
    _error = LPP_ERROR_OVERFLOW;
    return 0;
  }

  // check sign  
  bool sign = value < 0;
  if (sign) value = -value;

  // get value to store
  uint32_t v = value * multiplier;

  // format an uint32_t as if it was an int32_t
  if (is_signed & sign) {
    uint32_t mask = (1 << (size * 8)) - 1;
    v = v & mask;
    if (sign) v = mask - v + 1;
  }

  // header
  _buffer[_cursor++] = channel;
  _buffer[_cursor++] = type;

  // add bytes (MSB first)
  for (uint8_t i=1; i<=size; i++) {
    _buffer[_cursor + size - i] = (v & 0xFF);
    v >>= 8;
  }

  // update & return _cursor
  _cursor += size;
  return _cursor;

}

uint8_t AaadLPP::addDigitalInput(uint8_t channel, uint32_t value) {
  return addField(LPP_DIGITAL_INPUT, channel, value);
}

uint8_t AaadLPP::addDigitalOutput(uint8_t channel, uint32_t value) {
  return addField(LPP_DIGITAL_OUTPUT, channel, value);
}

uint8_t AaadLPP::addAnalogInput(uint8_t channel, float value) {
  return addField(LPP_ANALOG_INPUT, channel, value);
}

uint8_t AaadLPP::addAnalogOutput(uint8_t channel, float value) {
  return addField(LPP_ANALOG_OUTPUT, channel, value);
}

uint8_t AaadLPP::addGenericSensor(uint8_t channel, float value)  {
  return addField(LPP_GENERIC_SENSOR, channel, value);
}

uint8_t AaadLPP::addLuminosity(uint8_t channel, uint32_t value) {
  return addField(LPP_LUMINOSITY, channel, value);
}

uint8_t AaadLPP::addPresence(uint8_t channel, uint32_t value) {
  return addField(LPP_PRESENCE, channel, value);
}

uint8_t AaadLPP::addTemperature(uint8_t channel, float value) {
  return addField(LPP_TEMPERATURE, channel, value);
}

uint8_t AaadLPP::addRelativeHumidity(uint8_t channel, float value) {
  return addField(LPP_RELATIVE_HUMIDITY, channel, value);
}

uint8_t AaadLPP::addVoltage(uint8_t channel, float value) {
  return addField(LPP_VOLTAGE, channel, value);
}

uint8_t AaadLPP::addCurrent(uint8_t channel, float value) {
  return addField(LPP_CURRENT, channel, value);
}

uint8_t AaadLPP::addFrequency(uint8_t channel, uint32_t value) {
  return addField(LPP_FREQUENCY, channel, value);
}

uint8_t AaadLPP::addPercentage(uint8_t channel, uint32_t value) {
  return addField(LPP_PERCENTAGE, channel, value);
}

uint8_t AaadLPP::addAltitude(uint8_t channel, float value) {
  return addField(LPP_ALTITUDE, channel, value);
}

uint8_t AaadLPP::addPower(uint8_t channel, uint32_t value) {
  return addField(LPP_POWER, channel, value);
}

uint8_t AaadLPP::addDistance(uint8_t channel, float value) {
  return addField(LPP_DISTANCE, channel, value);
}

uint8_t AaadLPP::addEnergy(uint8_t channel, float value) {
  return addField(LPP_ENERGY, channel, value);
}

uint8_t AaadLPP::addBarometricPressure(uint8_t channel, float value) {
  return addField(LPP_BAROMETRIC_PRESSURE, channel, value);
}

uint8_t AaadLPP::addUnixTime(uint8_t channel, uint32_t value) {
  return addField(LPP_UNIXTIME, channel, value);
}

uint8_t AaadLPP::addDirection(uint8_t channel, float value) {
  return addField(LPP_DIRECTION, channel, value);
}

uint8_t AaadLPP::addSwitch(uint8_t channel, uint32_t value) {
  return addField(LPP_SWITCH, channel, value);
}

uint8_t AaadLPP::addConcentration(uint8_t channel, uint32_t value) {
  return addField(LPP_CONCENTRATION, channel, value);
}

uint8_t AaadLPP::addColour(uint8_t channel, uint8_t r, uint8_t g, uint8_t b)
{
  // check buffer overflow
  if ((_cursor + LPP_COLOUR_SIZE + 2) > _maxsize) {
    _error = LPP_ERROR_OVERFLOW;
    return 0;
  }
  _buffer[_cursor++] = channel;
  _buffer[_cursor++] = LPP_COLOUR;
  _buffer[_cursor++] = r;
  _buffer[_cursor++] = g;
  _buffer[_cursor++] = b;

  return _cursor;
}

uint8_t AaadLPP::addAccelerometer(uint8_t channel, float x, float y, float z) {
  
  // check buffer overflow
  if ((_cursor + LPP_ACCELEROMETER_SIZE + 2) > _maxsize) {
    _error = LPP_ERROR_OVERFLOW;
    return 0;
  }

  int16_t vx = x * LPP_ACCELEROMETER_MULT;
  int16_t vy = y * LPP_ACCELEROMETER_MULT;
  int16_t vz = z * LPP_ACCELEROMETER_MULT;

  _buffer[_cursor++] = channel;
  _buffer[_cursor++] = LPP_ACCELEROMETER;
  _buffer[_cursor++] = vx >> 8;
  _buffer[_cursor++] = vx;
  _buffer[_cursor++] = vy >> 8;
  _buffer[_cursor++] = vy;
  _buffer[_cursor++] = vz >> 8;
  _buffer[_cursor++] = vz;

  return _cursor;

}

uint8_t AaadLPP::addGyrometer(uint8_t channel, float x, float y, float z) {

  // check buffer overflow
  if ((_cursor + LPP_GYROMETER_SIZE + 2) > _maxsize) {
    _error = LPP_ERROR_OVERFLOW;
    return 0;
  }

  int16_t vx = x * LPP_GYROMETER_MULT;
  int16_t vy = y * LPP_GYROMETER_MULT;
  int16_t vz = z * LPP_GYROMETER_MULT;

  _buffer[_cursor++] = channel;
  _buffer[_cursor++] = LPP_GYROMETER;
  _buffer[_cursor++] = vx >> 8;
  _buffer[_cursor++] = vx;
  _buffer[_cursor++] = vy >> 8;
  _buffer[_cursor++] = vy;
  _buffer[_cursor++] = vz >> 8;
  _buffer[_cursor++] = vz;

  return _cursor;

}

uint8_t AaadLPP::addGPS(uint8_t channel, float latitude, float longitude, float altitude) {
  
  // check buffer overflow
  if ((_cursor + LPP_GPS_SIZE + 2) > _maxsize) {
    _error = LPP_ERROR_OVERFLOW;
    return 0;
  }

  int32_t lat = latitude * LPP_GPS_LAT_LON_MULT;
  int32_t lon = longitude * LPP_GPS_LAT_LON_MULT;
  int32_t alt = altitude * LPP_GPS_ALT_MULT;

  _buffer[_cursor++] = channel;
  _buffer[_cursor++] = LPP_GPS;
  _buffer[_cursor++] = lat >> 16;
  _buffer[_cursor++] = lat >> 8;
  _buffer[_cursor++] = lat;
  _buffer[_cursor++] = lon >> 16;
  _buffer[_cursor++] = lon >> 8;
  _buffer[_cursor++] = lon;
  _buffer[_cursor++] = alt >> 16;
  _buffer[_cursor++] = alt >> 8;
  _buffer[_cursor++] = alt;

  return _cursor;

}

// AAAd specific data types
uint8_t AaadLPP::addCo2(uint8_t channel, uint32_t value) {
  return addField(LPP_CO2, channel, value);
}

uint8_t AaadLPP::addNoise(uint8_t channel, uint32_t value) {
  return addField(LPP_NOISE, channel, value);
}

uint8_t AaadLPP::addLight(uint8_t channel, uint32_t value) {
  return addField(LPP_LIGHT, channel, value);
}

uint8_t AaadLPP::addConductivity(uint8_t channel, uint32_t value) {
  return addField(LPP_CONDUCTIVITY, channel, value);
}

uint8_t AaadLPP::addWeight(uint8_t channel, uint32_t value) {
  return addField(LPP_WEIGHT, channel, value);
}

uint8_t AaadLPP::addTDS(uint8_t channel, uint32_t value) {
  return addField(LPP_TDS, channel, value);
}

uint8_t AaadLPP::addAngle(uint8_t channel, uint32_t value) {
  return addField(LPP_ANGLE, channel, value);
}



// ----------------------------------------------------------------------------

float AaadLPP::getValue(uint8_t * buffer, uint8_t size, uint32_t multiplier, bool is_signed) {

    uint32_t value = 0;
    for (uint8_t i=0; i<size; i++) {
      value = (value << 8) + buffer[i];
    }

    int sign = 1;
    if (is_signed) {
      uint32_t bit = 1ul << ((size * 8) - 1);
      if ((value & bit) == bit) {
        value = (bit << 1) - value;
        sign = -1;
      }
    }

    return sign * ((float) value / multiplier);

}

uint32_t AaadLPP::getValue32(uint8_t * buffer, uint8_t size) {

    uint32_t value = 0;
    for (uint8_t i=0; i<size; i++) {
      value = (value << 8) + buffer[i];
    }

    return value;

}

uint8_t AaadLPP::decode(uint8_t *buffer, uint8_t len, JsonArray& root) {

  uint8_t count = 0;
  uint8_t index = 0;

  while ((index + 2) < len) {

    count++;

    // Get channel #
    uint8_t channel = buffer[index++];
    
    // Get data type
    uint8_t type = buffer[index++];
    if (!isType(type)) {
      _error = LPP_ERROR_UNKOWN_TYPE;
      return 0;
    }

    // Type definition
    uint8_t size = getTypeSize(type);
    uint32_t multiplier = getTypeMultiplier(type);
    bool is_signed = getTypeSigned(type);

    // Check buffer size
    if (index + size > len) {
      _error = LPP_ERROR_OVERFLOW;
      return 0;
    }

    // Init object
    JsonObject data = root.createNestedObject();
    data["channel"] = channel;
    data["type"] = type;
    data["name"] = String(getTypeName(type));

    // Parse types
	if (LPP_COLOUR == type) {

      JsonObject object = data.createNestedObject("value");
      object["r"] = getValue(&buffer[index], 1, multiplier, is_signed);
      object["g"] = getValue(&buffer[index+1], 1, multiplier, is_signed);
      object["b"] = getValue(&buffer[index+2], 1, multiplier, is_signed);

    } else if (LPP_ACCELEROMETER == type || LPP_GYROMETER == type) {

      JsonObject object = data.createNestedObject("value");
      object["x"] = getValue(&buffer[index], 2, multiplier, is_signed);
      object["y"] = getValue(&buffer[index+2], 2, multiplier, is_signed);
      object["z"] = getValue(&buffer[index+4], 2, multiplier, is_signed);

    } else if (LPP_GPS == type) {

      JsonObject object = data.createNestedObject("value");
      object["latitude"] = getValue(&buffer[index], 3, 10000, is_signed);
      object["longitude"] = getValue(&buffer[index+3], 3, 10000, is_signed);
      object["altitude"] = getValue(&buffer[index+6], 3, 100, is_signed);

    } else if (LPP_GENERIC_SENSOR == type || LPP_UNIXTIME == type) {

      data["value"] = getValue32(&buffer[index], size);

    } else {

      data["value"] = getValue(&buffer[index], size, multiplier, is_signed);

    }

    index += size;

  }

  return count;

}

uint8_t AaadLPP::decodeTTN(uint8_t *buffer, uint8_t len, JsonObject& root) {

  uint8_t count = 0;
  uint8_t index = 0;

  while ((index + 2) < len) {

    count++;

    // Get channel #
    uint8_t channel = buffer[index++];
    
    // Get data type
    uint8_t type = buffer[index++];
    if (!isType(type)) {
      _error = LPP_ERROR_UNKOWN_TYPE;
      return 0;
    }

    // Type definition
    uint8_t size = getTypeSize(type);
    uint32_t multiplier = getTypeMultiplier(type);
    bool is_signed = getTypeSigned(type);

    // Check buffer size
    if (index + size > len) {
      _error = LPP_ERROR_OVERFLOW;
      return 0;
    }

    // Init object
    String name = String(getTypeName(type)) + "_" + channel;

    // Parse types
	if (LPP_COLOUR == type) {
      JsonObject object = root.createNestedObject(name);
      object["r"] = getValue(&buffer[index], 1, multiplier, is_signed);
      object["g"] = getValue(&buffer[index+1], 1, multiplier, is_signed);
      object["b"] = getValue(&buffer[index+2], 1, multiplier, is_signed);

    } else if (LPP_ACCELEROMETER == type || LPP_GYROMETER == type) {

      JsonObject object = root.createNestedObject(name);
      object["x"] = getValue(&buffer[index], 2, multiplier, is_signed);
      object["y"] = getValue(&buffer[index+2], 2, multiplier, is_signed);
      object["z"] = getValue(&buffer[index+4], 2, multiplier, is_signed);

    } else if (LPP_GPS == type) {

      JsonObject object = root.createNestedObject(name);
      object["latitude"] = getValue(&buffer[index], 3, 10000, is_signed);
      object["longitude"] = getValue(&buffer[index+3], 3, 10000, is_signed);
      object["altitude"] = getValue(&buffer[index+6], 3, 100, is_signed);

    } else if (LPP_GENERIC_SENSOR == type || LPP_UNIXTIME == type) {

      root[name] = getValue32(&buffer[index], size);

    } else {

      root[name] = getValue(&buffer[index], size, multiplier, is_signed);

    }

    index += size;

  }

  return count;

}