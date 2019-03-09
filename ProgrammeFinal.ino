#include <SoftwareSerial.h>
#include <Servo.h>
#define RX 11
#define TX 10
SoftwareSerial Jouraille(RX, TX);
Servo ServoMoteur;
const int Pas = 3;
const int Dir = 2;
const int tps = 1000;
int x;
float r;
char Bouton;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  pinMode(Pas,OUTPUT); 
  pinMode(Dir,OUTPUT); 
  digitalWrite(Dir,HIGH); 
  Jouraille.begin(9600);
  ServoMoteur.attach(4);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  if (Jouraille.available()) {
    Bouton = Jouraille.read();
    
    if ( (Bouton == 'F')) {
      delay(1000);
      rotation(1, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(3, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(2, 1000);
    }

    if ( (Bouton == 'L')) {
      delay(1000);
      rotation(2, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(2, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(2, 1000);
    }

    if ( (Bouton == 'M')) {
      delay(1000);
      rotation(3, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(1, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(2, 1000);
    }

    if ( (Bouton == 'E')) {
      delay(1000);
      rotation(4, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(2, 1000);
    }

    if ( (Bouton == 'G')) {
      delay(1000);
      rotation(5, tps);
      cremaillere(10, 10);
      delay(1000);
      rotation(1, 1000);
    }

    if ( (Bouton == 'C')) {
      delay(1000);
      cremaillere(10, 10);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rotation(int tour, int delai) {
  r = tour/6;
  for(x=0; x<200*r; x++) {
    digitalWrite(Dir, HIGH); 
    digitalWrite(Pas, HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Pas, LOW); 
    delay(50);
  }
  delay(delai);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cremaillere(int av, int delai) {
  for(x=2400; x>500; x-=av) {
    ServoMoteur.writeMicroseconds(x);
    delay(delai);
  }
  
  for(x=500; x<2400; x+=av) {
    ServoMoteur.writeMicroseconds(x);
    delay(delai);
  }
}


/*
Bouton Bleu => Coca => C
Bouton Rouge => Sirop de Fraise => F
Bouton Jaune => Sirop de Citron => L
Bouton Vert => Sirop de Menthe => M
Bouton Carré => Eau plate => E
Bouton Rond => Eau gazeuse => G
*/
