//Define all pins for the tarot cards in order
//We avoid using pins 1 and 2 since it messes with program upload to the arduino
int cardOne = 2;
int cardTwo = 3;
int cardThree = 4;
int cardFour = 5;
int cardFive = 6;
int magLock = 7;
int resetButton = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(cardOne, INPUT_PULLUP);
  pinMode(cardTwo, INPUT_PULLUP);
  pinMode(cardThree, INPUT_PULLUP);
  pinMode(cardFour, INPUT_PULLUP);
  pinMode(cardFive, INPUT_PULLUP);
  pinMode(magLock, OUTPUT);
  pinMode (resetButton, INPUT_PULLUP);
  Serial.begin(9600);
  //We start by turning our mag lock on, by ensuring the signal to the 5V relay is OFF
  //We put this line of code up here since we dont want it to reset the lock every time the loop occurs, only at startup
  digitalWrite(magLock,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Then we simply check if all switches are active at the same time.
  if(digitalRead(cardOne)== LOW)
  {
    Serial.println("Card One");
    }
    if(digitalRead(cardTwo)== LOW)
  {
    Serial.println("Card Two");
    }
    if(digitalRead(cardThree)== LOW)
  {
    Serial.println("Card Three");
    }
    if(digitalRead(cardFour)== LOW)
  {
    Serial.println("Card Four");
    }
    if(digitalRead(cardFive)== LOW)
  {
    Serial.println("Card Five");
    }
  if(digitalRead(cardOne) == LOW
  && digitalRead(cardTwo) == LOW
  && digitalRead(cardThree) == LOW
  && digitalRead(cardFour) == LOW
  && digitalRead(cardFive) == LOW)
  {
    //If they are, we toggle the mag lock off, by switching ON the signal to the 5V relay
    digitalWrite(magLock, HIGH); 
    while(digitalRead(resetButton)==HIGH)
    {
      }
      digitalWrite(magLock, LOW);   
    }
    //We dont have an ELSE statement here since we do NOT want this lock to re-lock itself after the cards have been put in place
    //Afterwards, we simply add in a reset button somewhere in the room that we can press that will re-engage the mag lock by turning OFF the signal to the 5V relay

}
