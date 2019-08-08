#define RED 11
#define YELLOW 9
#define BLUE 6
#define SWITCH 12 
#define DELAY 50

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(SWITCH, INPUT);
}

void loop() {
  if(digitalRead(SWITCH) == HIGH){
    fire();
  }
  while(digitalRead(SWITCH) == HIGH){
    delay(DELAY);
  }
  delay(DELAY);
}

void fire(){
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, LOW);
  delay(DELAY);

  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
  delay(DELAY);

  digitalWrite(BLUE, HIGH);
  digitalWrite(YELLOW, LOW);
  delay(DELAY);
  
  digitalWrite(BLUE, LOW);
}
