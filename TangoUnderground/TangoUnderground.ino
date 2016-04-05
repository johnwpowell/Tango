#include <SoftwareSerial.h> // software serial used by imp
#include <Wire.h> // I2C needed for sensors
#include "SparkFunMPL3115A2.h" // pressure sensor
#include "SparkFunHTU21D.h" // humidity sensor

// RX, TX into Imp pin 7
const int TX = 8;
const int RX = 9;

SoftwareSerial impSerial(TX, RX);
MPL3115A2 pressureSensor;
HTU21D humiditySensor;

void setup() {
  setupStatus();
  setupHardwareSerial();
  setupImpSerial();
  setupPressureSensor();
  setupHumiditySensor();
  setupWindSpeedSensor();
  setupRainSensor();
  interrupts(); // turn on interrupts (for wind speed and rain)
  setStatusOnline(true);
}

void loop() {
  transmitWeather();
  delay(1000);
}
