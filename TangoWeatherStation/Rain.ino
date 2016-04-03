long lastRainCheck = 0;
volatile long lastRainInterrupt = 0;
volatile byte rainClicks = 0;

void setupRainSensor() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, rainInterrupt, FALLING);
}

float readRain() {
  float deltaTime = millis() - lastRainCheck;
  deltaTime /= 1000.0; //Convert to seconds
  float rain = (float)rainClicks / deltaTime;
  rainClicks = 0; //Reset and start watching for new rain
  lastRainCheck = millis();
  rain *= 0.011;
  return rain;
}

void rainInterrupt()
{
  if (millis() - lastRainInterrupt > 10) // ignore switch-bounce glitches less than 10ms
  {
    lastRainInterrupt = millis(); // grab the current time
    rainClicks++; // there is 0.011" rain for each click
  }
}

