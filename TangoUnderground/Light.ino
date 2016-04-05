float readLight()
{
  float operatingVoltage = analogRead(A3); // reference voltage is 3.3V
  float light = analogRead(A1); //analog value from 0 to 1023
  operatingVoltage = 3.3 / operatingVoltage; 
  light = operatingVoltage * light;
  return light;
}
