#include <Servo.h>
const int ledPin = 13;      

int ANGLE = 0  ; 
bool systemOn = false;

int buttonState = LOW;   

int LEDON = LOW;    
int LEDOFF = HIGH; 

int lastButtonState = LOW;

unsigned long debounceDelay = 50;    

Servo S;

void setup() {
  // set up all the LEDs as OUTPUT
 
 S.write(0);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  
  digitalWrite(10,LEDON);
  digitalWrite(11,LEDOFF);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  
  S.attach(A0);
  Serial.begin(9600);         

  
}

void loop() {
  int reading = digitalRead(7); 
  
  
  
  if (reading != lastButtonState) {
   
  
  
  
    
    lastButtonState = reading;  
    delay(debounceDelay);      
    reading = digitalRead(7);  

    if (reading != buttonState) {
      buttonState = reading;    

      if (buttonState == HIGH) {
        
        digitalWrite(10, !digitalRead(10));  
        digitalWrite(11, !digitalRead(11));
        systemOn =!systemOn;
        Serial.println("Button pressed!");
      }
    }
  }
  int X1 = digitalRead(4);
  int X2 = digitalRead(2);
  int Y1 , Y2 ;
  
  if( X1 != LOW && systemOn )
  {
    
for (ANGLE ; ANGLE <= 180 ; ANGLE++) {
    Y1 = map(ANGLE , 0 , 180 ,0 ,255);
  if(Y1>=0 && Y1 <=60)
  {
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);

  }
  else if (Y1>=61 && Y1<=120)
  {
 digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  else if (Y1>=121 && Y1<=180)
  {
 digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }
  else if (Y1>=181 && Y1<=255)
  {
 digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
  }

  
  
    S.write(ANGLE);   
    delay(50);   
  if ( digitalRead(4) == LOW ) break;
  }

  }
  
   if( X2 && systemOn )
  {
for (ANGLE  ; ANGLE >= 0 && digitalRead(2) ; ANGLE--) {
   Y2 = map(ANGLE , 0 , 180 ,0 ,255);
  if(Y2>=0 && Y2 <=60)
  {
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);

  }
  else if (Y2>=61 && Y2<=120)
  {
 digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  else if (Y2>=121 && Y2<=180)
  {
 digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }
  else if (Y2>=181 && Y2<=255)
  {
 digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
  }
  
  S.write(ANGLE);   
    delay(50);   
  
}}
  
}