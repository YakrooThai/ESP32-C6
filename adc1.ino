void setup() {

  Serial.begin(9600);
  analogReadResolution(12);
}

void loop() {

  int analogValue = analogRead(2);
  int analogVolts = analogReadMilliVolts(2);

  Serial.print("ADC analog value = ");
  Serial.println(analogValue);

  Serial.print("ADC millivolts value = ");
  Serial.print(analogVolts);
  Serial.println(" mV");

  Serial.print("ADC Volts value = ");
  Serial.print((analogVolts) /1000.0);
  Serial.println(" V");
  Serial.println("-------------------------------------");
  delay(1000);
}
