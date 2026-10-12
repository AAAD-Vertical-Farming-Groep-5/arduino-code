#include "SHT31Sensor.h"

SHT31Sensor::SHT31Sensor() {
    temperature = 0.0;
    humidity = 0.0;
}

bool SHT31Sensor::begin() {
    Wire.begin();
    Wire.setClock(100000);

    if (!sensor.begin()) {
        return false;
    }

    delay(100);

    return true;
}

bool SHT31Sensor::read() {
    sensor.read();

    temperature = sensor.getTemperature();
    humidity = sensor.getHumidity();

    return true;
}

float SHT31Sensor::getTemperature() {
    return temperature;
}

float SHT31Sensor::getHumidity() {
    return humidity;
}

void SHT31Sensor::printMeasurements() {
    Serial.print(F("Temperature: "));
    Serial.print(temperature, 1);
    Serial.println(F(" C"));

    Serial.print(F("Humidity: "));
    Serial.print(humidity, 1);
    Serial.println(F(" %"));
}