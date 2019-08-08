#define GATE_PIN 3
#define SWITCH_PIN 10

void setup() {
  // put your setup code here, to run once:
  pinMode(GATE_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);
}

void loop() {
  digitalWrite(GATE_PIN, digitalRead(SWITCH_PIN));
  delay(10);
}
