void setupHardwareSerial() {
  Serial.begin(9600);
}

void setupImpSerial() {
  impSerial.begin(57600);
}

void readImpSerial() {
  if(impSerial.available() > 0) {
    Serial.println(impSerial.readString());
  }
}

