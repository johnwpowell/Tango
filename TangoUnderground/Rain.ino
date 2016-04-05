long lastRainCheck = 0;
long rainHour = 0;
long rainAccum = 0;
byte rainSeconds = 0;
volatile long lastRainInterrupt = 0;
volatile byte rainClicks = 0;

void setupRainSensor() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, rainInterrupt, FALLING);
}

float readRain() {
  float deltaTime = millis() - lastRainCheck;
  deltaTime /= 1000.0; //Convert to seconds
  rainSeconds += deltaTime;
  float rain = (float)rainClicks / deltaTime;
  rainClicks = 0; //Reset and start watching for new rain
  lastRainCheck = millis();
  rain *= 0.011;
  rainAccum += rain; // keep track of the rain accumulated over the past hour
  if(rainSeconds >= 60) {
    rainHour = rainAccum;
    rainAccum = 0;
    rainSeconds = 0;
  }
  return rainHour;
}

void rainInterrupt()
{
  if (millis() - lastRainInterrupt > 10) // ignore switch-bounce glitches less than 10ms
  {
    lastRainInterrupt = millis(); // grab the current time
    rainClicks++; // there is 0.011" rain for each click
  }
}

