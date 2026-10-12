#ifndef BODEMVOCHT_SENSOR_H
#define BODEMVOCHT_SENSOR_H

#include <Arduino.h>

class BodemvochtSensor {
private:
    int pin;

public:
    BodemvochtSensor(int pin);
    int read();
};

#endif