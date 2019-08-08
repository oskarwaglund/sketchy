#define BLUE_SENS A0
#define RED_PIN 11
#define BLUE_PIN 3
#define GREEN_PIN 6 
#define PIN_STR 80

void setup() {
  int pins[] = {BLUE_PIN, RED_PIN, GREEN_PIN};
  for(int i = 0; i < 3; i++){
    pinMode(pins[i], OUTPUT);
    analogWrite(pins[i], PIN_STR);
  }
}

void loop() {
  delay(10000);
}
