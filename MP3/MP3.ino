#include <LiquidCrystal.h>

#undef F

#define P 0 //Pause

#define C 523
#define C_ 554
#define D 587
#define D_ 622
#define E 659
#define F 698
#define F_ 740
#define G 784
#define G_ 831
#define A 880
#define A_ 932
#define B 988
#define HC 1047


#define SOUND_PIN 8
#define NEXT_PIN 9
#define PLAY_PIN 10

#define BEAT 400

LiquidCrystal lcd(12, 11, 3, 4, 5, 6);

int currentIndex = 0;

const int nSongs = 4;

void playSong(int index){
  switch(index){
    case 0: twinkle(); break;
    case 1: paris(); break;
    case 2: cScale(); break;
    case 3: swedishAnthem(); break;
  }
}

void getSongName(int index, char *songName){
  switch(index){
    case 0: sprintf(songName, "Twinkle twinkle"); break;
    case 1: sprintf(songName, "Till Paris"); break;
    case 2: sprintf(songName, "The C scale"); break;
    case 3: sprintf(songName, "Swedish anthem"); break;
    default: sprintf(songName, "Unknown");
  }
}

void setup() {
  Serial.begin(9600);
  Serial.write(nSongs);
  tone(SOUND_PIN, 440, 100);
  lcd.begin(16, 2);
  lcd.print("Welcome to the");
  lcd.setCursor(0,1);
  lcd.print("Oskar music box");
  delay(2000);
}

void loop() {
  char songName[17];
  getSongName(currentIndex, songName);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select a song!");
  lcd.setCursor(0, 1);
  lcd.print(songName);
  
  while(digitalRead(PLAY_PIN) == LOW && digitalRead(NEXT_PIN) == LOW){
    delay(100);
  }

  if(digitalRead(PLAY_PIN) == HIGH){
    while(digitalRead(PLAY_PIN) == HIGH) delay(100);
    playSong(currentIndex);
  } else{
    currentIndex = (currentIndex + 1)%nSongs;
    while(digitalRead(NEXT_PIN) == HIGH) delay(100);
  }
}

//Melodies
void twinkle(){
  int melody[] = {C, C, G, G, A, A, G, P, F, F, E, E, D, D, C, P, G, G, F, F, E, E, D, P, G, G, F, F, E, E, D, P, C, C, G, G, A, A, G, P, F, F, E, E, D, D, C}; 
  playMelody(melody, sizeof(melody)/sizeof(int), BEAT);
}

void paris(){
  int melody[] = {E, D, C, P, E, D, C, P, D, D, G, F, E, D, C, P}; 
  playMelody(melody, sizeof(melody)/sizeof(int), BEAT);
}

void cScale() {
  int melody[] = {C, D, E, F, G, A, B, HC}; 
  playMelody(melody, sizeof(melody)/sizeof(int), BEAT);
}

void swedishAnthem() {
  const int t = 300;
  play(E, t);
  play(E, 2*t);
  play(C, t);
  play(C, t);
  play(C, 2*t);
  play(D, t);
  play(E, t);
  play(E, 2*t);
  play(D, t);
  play(C, t);
  play(B/2, 2*t);
  play(P, t);
  
  play(D, t);
  play(D, 2*t);
  play(B/2, t);
  play(C, t);
  play(D, t);
  play(B/2, t);
  play(E, 3*t/2);
  play(C, t/2);
  play(A/2, 4*t);
  play(G/2, 3*t);
  
  play(G/2, t);
  play(C, 2*t);
  play(C, t);
  play(D, t);
  play(B/2, 2*t);
  play(B/2, t);
  play(C, t);
  play(A/2, 3*t/2);
  play(G/2, t/2);
  play(A/2, t);
  play(B/2, t);
  play(G/2, 3*t);
  
  play(G/2, t);
  play(C, 3*t/2);
  play(B/2, t/2);
  play(C, t);
  play(D, t);
  play(E, t);
  play(C, t);
  play(F, t);
  play(E, t);
  play(D, 4*t);
  play(C, 3*t);
}

//Functions for playing

void playMelody(int tones[], int len, int tempo){
  for(int i = 0; i < len; i++){
    play(tones[i], tempo);
  }
}

void play(int pitch, int len){
  char toneName[3];
  toneString(pitch, toneName); 
  lcd.clear();
  lcd.setCursor(7, 0);

  lcd.write(toneName);
  
  if(pitch == P){
    delay(len);
    return;
  }
  
  tone(SOUND_PIN, pitch, len-10);
  delay(len);
}

void toneString(int pitch, char *out){
  switch(pitch){
    case G/2: sprintf(out, "G"); break;
    case A/2: sprintf(out, "A"); break;
    case B/2: sprintf(out, "B"); break;
    case C: sprintf(out, "C"); break;
    case D: sprintf(out, "D"); break;
    case E: sprintf(out, "E"); break;
    case F: sprintf(out, "F"); break;
    case G: sprintf(out, "G"); break;
    case A: sprintf(out, "A"); break;
    case B: sprintf(out, "B"); break;
    case C*2: sprintf(out, "C"); break;
    default: sprintf(out, "");
  }
}
