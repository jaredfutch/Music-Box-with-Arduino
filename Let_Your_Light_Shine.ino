int trigPin = 13;
int echoPin = 12;

int speakerPin = 9;
int ledPin = 8;
int length = 46;

char notes[] = "ccccdfaaaagfddddefffdfdcccccdfaaaagffgavagagf ";
int beats[] = {2,1,1,1,2,5,2,1,1,1,2,5,2,1,1,1,2,5,2,1,1,1,2,5,2,1,1,1,2,5,2,1,1,1,2,3,1,2,3,1,2,3,1,2,8,8};
int tempo = 150;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 's', 'g', 'a', 'v', 'b', 'C', 'D', 'E' };
int tones[] = { 1915, 1700, 1519, 1432, 1352, 1275, 1136, 1073, 1014, 956, 852, 758 };
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  pinMode(speakerPin, OUTPUT);
   pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 20) {    
    for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); 
    } else {
      playNote(notes[i], beats[i] * tempo);
    }    
    delay(tempo / 2); 
  }
   }
  else {
    digitalWrite(ledPin,HIGH);
    
  } 
}
