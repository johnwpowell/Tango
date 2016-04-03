void setupHumiditySensor() {
  humiditySensor.begin();
}

float readHumidity() {
  return humiditySensor.readHumidity();
}

