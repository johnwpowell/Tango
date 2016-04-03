void setupPressureSensor() {
  pressureSensor.begin(); // Get sensor online
  pressureSensor.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  pressureSensor.setOversampleRate(128); // Set Oversample to the recommended 128
  pressureSensor.enableEventFlags(); // Enable all three pressure and temp event flags
  pressureSensor.setModeActive(); // Go to active mode and start measuring
}

float readPressure() {
  return pressureSensor.readPressure();
}

