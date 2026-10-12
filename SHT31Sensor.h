#ifndef SHT31SENSOR_H
#define SHT31SENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include <SHT31.h>

class SHT31Sensor {
private:
    SHT31 sensor;

    float temperature;
    float humidity;

public:
    SHT31Sensor();

    bool begin();
    bool read();

    float getTemperature();
    float getHumidity();

    void printMeasurements();
};

#endif