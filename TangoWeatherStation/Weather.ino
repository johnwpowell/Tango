void transmitWeather() {
  setStatusTransmit(true);
  String weather = readWeather();
  bluetoothSerial.println(weather);
  //Serial.println(weather);
  setStatusTransmit(false);
}

String readWeather() {
  String weather = "";
  weather.concat("{");
  concatJson(weather, "temperature", readTemperature(), true);
  concatJson(weather, "humidity", readHumidity(), true);
  concatJson(weather, "pressure", readPressure(), true);
  concatJson(weather, "windSpeed", readWindSpeed(), true);
  concatJson(weather, "windDirection", readWindDirection(), true);
  concatJson(weather, "rain", readRain(), true);
  concatJson(weather, "light", readLight(), false);
  weather.concat("}");
  return weather;
}

void concatJson(String &json, String key, float value, bool seperator) {
  json.concat("\"");
  json.concat(key);
  json.concat("\":");
  json.concat("\"");
  json.concat(value);
  json.concat("\"");
  if(seperator) {
    json.concat(",");
  }
}

