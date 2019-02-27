#include <SoftwareSerial.h>
#define RX 11
#define TX 10
SoftwareSerial Jouraille(RX, TX);
const int Pas = 3; 
const int Dir = 2; 
int i=0;
char Bouton;
int vitesse = 0;

void setup() {
   Serial.begin(115200);
  pinMode(Pas,OUTPUT); 
  pinMode(Dir,OUTPUT); 
  digitalWrite(Dir,HIGH); 
  Jouraille.begin(9600);
}

void loop() {
  if (Jouraille.available()) {
    Bouton = Jouraille.read();
    if ((Bouton == 'F')) {
      delay(1000);
      for(int x = 0; x < 200/6; x++) {
        digitalWrite(Dir,HIGH); 
        digitalWrite(Pas,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(10000);
      for(int x = 0; x < 200/6; x++) {
        digitalWrite(Pas,HIGH); 
        digitalWrite(Dir,LOW); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(1000);
    }
    
    else if ((Bouton == 'L')) {
      delay(1000);
      for(int x = 0; x < 200/3; x++) {
        digitalWrite(Dir,HIGH); 
        digitalWrite(Pas,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(10000);
      for(int x = 0; x < 200/3; x++) {
        digitalWrite(Pas,HIGH); 
        digitalWrite(Dir,LOW); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(1000);
    }
    
    else if ( (Bouton == 'M')) {
      delay(1000);
      for(int x = 0; x < 200/2; x++) {
        digitalWrite(Dir,HIGH); 
        digitalWrite(Pas,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(10000);
      for(int x = 0; x < 200/2; x++) {
        digitalWrite(Pas,HIGH); 
        digitalWrite(Dir,LOW); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(1000);
    }

    else if ( (Bouton == 'E')) {
      delay(1000);
      for(int x = 0; x < 200*2/3; x++) {
        digitalWrite(Dir,HIGH); 
        digitalWrite(Pas,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(10000);
      for(int x = 0; x < 200*2/3; x++) {
        digitalWrite(Pas,HIGH); 
        digitalWrite(Dir,LOW); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(1000);
    }


    else if ( (Bouton == 'G')) {
      delay(1000);
      for(int x = 0; x < 200*5/6; x++) {
        digitalWrite(Dir,HIGH); 
        digitalWrite(Pas,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(10000);
      for(int x = 0; x < 200*5/6; x++) {
        digitalWrite(Pas,HIGH); 
        digitalWrite(Dir,LOW); 
        delayMicroseconds(500); 
        digitalWrite(Pas,LOW); 
        delay(50);
      }
      delay(1000);
    }
  }
}


/* L LEMON JAUNE
M MENTHE VERT
C COLA BLEU
F FRAISE ROUGE
G GAZ ROND
E EAU CARRE */
