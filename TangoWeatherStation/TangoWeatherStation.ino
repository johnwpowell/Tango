#include <SoftwareSerial.h> // software serial used by bluetooth
#include <Wire.h> // I2C needed for sensors
#include "SparkFunMPL3115A2.h" // pressure sensor
#include "SparkFunHTU21D.h" // humidity sensor

const int BT_TX = 13;  // TX-O pin of bluetooth smirf
const int BT_RX = 12;  // RX-I pin of bluetooth smirf

SoftwareSerial bluetoothSerial(BT_TX, BT_RX);
MPL3115A2 pressureSensor;
HTU21D humiditySensor;

void setup() {
  setupStatus();
  setupHardwareSerial();
  setupBluetoothSerial();
  setupPressureSensor();
  setupHumiditySensor();
  setupWindSpeedSensor();
  setupRainSensor();
  interrupts(); // turn on interrupts (for wind speed and rain)
  setStatusOnline(true);
}

void loop() {
  if(bluetoothSerial.available() > 0) {
    while(bluetoothSerial.read() > 0) {
      
    }
    transmitWeather();
  }
  delay(1000);
}
