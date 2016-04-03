void setupHardwareSerial() {
  Serial.begin(9600);
}

void setupBluetoothSerial() {
  bluetoothSerial.begin(115200);// default baud of smirf is 115200
  bluetoothSerial.print("$"); // enter command mode and set baud rate
  bluetoothSerial.print("$");
  bluetoothSerial.print("$");  
  delay(100);  // delay for the smirf to send back CMD
  bluetoothSerial.println("U,9600,N");  // temporarily Change the baudrate to 9600, no parity
  bluetoothSerial.begin(9600);  // Start bluetooth serial at 9600
}
