#define SENSOR A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int readVal = analogRead(SENSOR);
  Serial.print("Sensor val: ");
  Serial.print(readVal);

  float voltage = readVal/1024.0*5.0;
  Serial.print(", Voltage: ");
  Serial.print(voltage);

  float temp = (voltage-0.5)*100;
  Serial.print(", Temperature: ");
  Serial.println(temp);

  delay(1000);
}
