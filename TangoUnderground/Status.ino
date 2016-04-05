void setupStatus() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void setStatusOnline(bool isOnline) {
  digitalWrite(8, isOnline?HIGH:LOW);
}

void setStatusTransmit(bool isTransmitting) {
  digitalWrite(7, isTransmitting?HIGH:LOW);
}

