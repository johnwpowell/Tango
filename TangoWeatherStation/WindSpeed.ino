long lastWindCheck = 0;
volatile long lastWindInterrupt = 0;
volatile byte windClicks = 0;

void setupWindSpeedSensor() {
  pinMode(3, INPUT_PULLUP); // input from wind meters windspeed sensor
  attachInterrupt(1, windSpeedInterrupt, FALLING);
}

float readWindSpeed() {
  float deltaTime = millis() - lastWindCheck;
  deltaTime /= 1000.0; //Convert to seconds
  float windSpeed = (float)windClicks / deltaTime;
  windClicks = 0; //Reset and start watching for new wind
  lastWindCheck = millis();
  windSpeed *= 1.492; //There is 1.492MPH for each click per second
  return windSpeed;
}

// Activated by the magnet in the anemometer (2 ticks per rotation), attached to input D3
void windSpeedInterrupt()
{
  if (millis() - lastWindInterrupt > 10) // Ignore switch-bounce glitches less than 10ms
  {
    lastWindInterrupt = millis(); // grab the current time
    windClicks++;
  }
}

