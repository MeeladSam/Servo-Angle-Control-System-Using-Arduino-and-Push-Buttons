https://www.tinkercad.com/things/l3Ve6uS0mdI-editing-components?sharecode=2w4BvqeMzRWcw4iwMU0o9MNHo7BcTigtnb4S5MTlBC0

This project is a simple Arduino system that controls a servo motor using push buttons and LEDs.
There is an Enable button that turns the system ON and OFF. When you press it once, the system starts working. When you press it again, the system stops. The state changes only after releasing the button.

There are two other buttons: one moves the servo to the right and the other moves it to the left. The servo keeps moving as long as you keep pressing the button, and it stops when you release it.

The final angle of the servo is converted to a value from 0 to 255. Based on this value, four LEDs turn on to show the servo position:
from 0–60 → first LED on
from 60–120 → first and second LEDs on
from 120–180 → first, second, and third LEDs on
from 180–255 → all LEDs on

The system uses three push buttons, one servo motor, and LEDs with 100 Ω resistors.

<img width="861" height="653" alt="image" src="https://github.com/user-attachments/assets/bb0ddd2f-b12a-4de4-a9b1-a2ab9e50057d" />

# Releasing Code

const int buttonPin = 2;  
const int ledPin = 13;      

int buttonState = LOW;      
int lastButtonState = LOW;  
unsigned long debounceDelay = 50;    
void setup() {
  pinMode(buttonPin, INPUT);        
  pinMode(ledPin, OUTPUT);          
  digitalWrite(ledPin, LOW);        
  Serial.begin(9600);                
}

void loop() {
  int reading = digitalRead(buttonPin);  

  if (reading != lastButtonState) {
    lastButtonState = reading;  
    delay(debounceDelay);      
    reading = digitalRead(buttonPin);  

    if (reading != buttonState) {
      buttonState = reading;    

      if (buttonState == HIGH) {
        digitalWrite(ledPin, !digitalRead(ledPin));  
        Serial.println("Button pressed!");
      }
    }
  }
}

# On the board
<img width="1255" height="784" alt="image" src="https://github.com/user-attachments/assets/bb74be04-bd33-445c-b1bf-1a9757d4ecc8" />
