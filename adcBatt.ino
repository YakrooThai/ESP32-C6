void setup() {

  Serial.begin(9600);
  analogReadResolution(12);
}

void loop() {

  int analogValue = analogRead(0);
  int analogVolts = analogReadMilliVolts(0);

  // print out the values you read:
  Serial.print("ADC analog value = ");
  Serial.println(analogValue);
  Serial.print("ADC millivolts value = ");
  Serial.println(analogVolts);
  Serial.println("mV");
  // Please adjust the calculation coefficient according to the actual measurement.
  Serial.print("BAT millivolts value = ");
  Serial.print(analogVolts * 2.1218 + 1000);
  Serial.println("mV");
  Serial.println("--------------");
  delay(1500);
}
