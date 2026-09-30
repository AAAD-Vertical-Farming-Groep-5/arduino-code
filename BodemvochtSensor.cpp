#include "BodemvochtSensor.h"

BodemvochtSensor::BodemvochtSensor(int pin) {
    this->pin = pin;
}

int BodemvochtSensor::read() {
    int sensorValue = analogRead(pin);

    Serial.print("Bodemvocht: ");
    Serial.println(sensorValue);

    delay(1000);

    return sensorValue;
}