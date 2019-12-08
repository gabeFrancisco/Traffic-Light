/*Project by Gabriel Francisco*/

int pinButton = 7;
int pinGreen = 8;
int pinYellow = 9;
int pinRed = 10;

int pinGreen2 = 3;
int pinRed2 = 2;

int lightStateGreen;
int buttonPress;
int buzzer = 4; //Reference to buzzer pin

int light = 11;

void setup() {
  //This is the pin that lead to the button of the pedestrian request to close the light and cross
  pinMode(pinButton, INPUT); 

  //The main traffic lights pins
  pinMode(pinGreen, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinRed, OUTPUT);

  //Now the pedestrian lights pins
  pinMode(pinRed2, OUTPUT);
  pinMode(pinGreen2, OUTPUT);

  //The buzzer pinout
  pinMode(buzzer, OUTPUT);

  //The light that's turn on programmaticaly...
  pinMode(light, OUTPUT);
}

void loop() {
  
  /*JUST FOR TEST PURPOSES========================
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinYellow, HIGH);
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinRed2, HIGH);
  digitalWrite(pinGreen2, HIGH);
  /*JUST FOR TEST PURPOSES======================*/

    //Programatic light
    digitalWrite(light, HIGH);
    
  
    lightStateGreen = 1;
    buttonPress = digitalRead(pinButton);
    
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, HIGH);

    digitalWrite(pinRed2, HIGH);
    digitalWrite(pinGreen2, LOW);
    
    if(buttonPress == HIGH){

      lightStateGreen++;
      tone(buzzer, 1900);
      delay(80);
      noTone(buzzer);

      //First turn for yellow light
      
      delay(10000);
      
      digitalWrite(pinRed, LOW);
      digitalWrite(pinYellow, HIGH);
      digitalWrite(pinGreen, LOW);

      //Second turn for the red light to cars, then pedestrian crosses :)

      delay(2000);

      digitalWrite(pinRed, HIGH);
      digitalWrite(pinYellow, LOW);
      digitalWrite(pinGreen, LOW);

      digitalWrite(pinRed2, LOW);
      digitalWrite(pinGreen2, HIGH);
      
      delay(15000);

      int i;
      int c = 3;

      for(i = 0; i <= c; i++){
        
        digitalWrite(pinRed2, HIGH);
        digitalWrite(pinGreen2, LOW);
        
        tone(buzzer, 1900);
        delay(800);
        noTone(buzzer);

        digitalWrite(pinRed2, LOW);
        delay(800);
            
      }  
    }
}
