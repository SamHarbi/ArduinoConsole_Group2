//include pitches library
#include "pitches.h"
//include queue library
#include <QueueArray.h>

//variables for the buttons and their states
int redButton = 4; //Start Button
int redButtonState = 0;

int yellowButton = 1;//Start Button
int yellowButtonState = 0;

int greenButton = 3;//Start Button
int greenButtonState = 0;

int blueButton = 2;//Start Button
int blueButtonState = 0;

int startButton = 0;//Start Button
int startButtonState = 0;

//variables for all of the LEDs
const int redLed = 5;
const int blueLed = 6;//output lights
const int greenLed = 7;
const int yellowLed = 8;

//delay for the led's turning on and off
int ledDelay = 1000;

//Setting the value of the random number to 0 as default
int randomInt = 0;

//queue that stores the LED order
QueueArray <int> queue;

// notes in the melody:
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int melodyStart[] = {NOTE_DS6, NOTE_DS5, NOTE_AS5, NOTE_GS5, NOTE_DS5, NOTE_DS6, NOTE_AS6, NOTE_AS5};
int winMelody[] = {NOTE_G4, NOTE_G4, NOTE_A4};

//notes for each colour led
int melodyRed = NOTE_DS3;
int melodyBlue = NOTE_DS4;
int melodyGreen = NOTE_DS5;
int melodyYellow = NOTE_DS6;

//Boolean value that start's the game/ends
boolean start = false;

//buzzer pin
int buzzerPin = 9;

// note durations: 4=1/4 note, 8=1/8 note
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

//=============================================================================================

void setup() 
{
  //Sets up the buttons
  pinMode(yellowButton,INPUT_PULLUP);
  pinMode(redButton,INPUT_PULLUP);
  pinMode(greenButton,INPUT_PULLUP);
  pinMode(blueButton,INPUT_PULLUP);
  pinMode(startButton,INPUT_PULLUP);

  //Sets up the LEDs
  pinMode(redLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  //serial
  Serial.begin(9600);
}

//=============================================================================================

int buttonPressReturn()
{
  //value of the button's state
  yellowButtonState = digitalRead(yellowButton);  
  redButtonState = digitalRead(redButton);
  greenButtonState = digitalRead(greenButton);
  blueButtonState = digitalRead(blueButton);

  //checks if the button has been pressed
  if(redButtonState == HIGH)
  {
    return 0;
  }
  if(greenButton == HIGH)
  {
    return 1;
  }
  if(blueButtonState == HIGH)
  {
    return 2;
  }
  if(yellowButtonState == HIGH)
  {
    return 3;
  }
}

void startButtonPress()
{
  //value of the button's state
  startButtonState = digitalRead(startButton);

  //checks if the button has been pressed
  if(startButtonState == HIGH)
  {
    //send a string and return the length of the string. This checks if button is working correcly
    int bytesSent = Serial.write("Button is working"); 
    //allows the game to start
    start = true;
  }
}

//=============================================================================================

void loop()
{
  startButtonPress();
//  startGame();

}


//=============================================================================================

//
//void startGame()
//{
//  //sets player's level
//  int level = 1;
//
//  //loops the game aslong as the player is winning
//  while(start == true)
//  {
//    //does not allow the player to continue
//    start = false;
//
//    //plays start up melody on first level
//    if(level == 1)
//    {
//      //plays on start up
//      startUpMelody();
//    }
//  
//    //waits 1.5 seconds before continuing
//    delay(1500);
//
//    //Flashes random LEDs depending. The amount flashed depends on user's current level
//    for(int i = 0; i < level; i++)
//    {
//      //creates a random number
//      randomInt = random(0,4);
//  
//      //switch that turns on the corresponding LED
//      switch(randomInt)
//      {
//        case 0: //red LED
//        {
//          digitalWrite(redLed,HIGH);//turn off red LEDs
//          redBeep(); // turns on buzzer
//          queue.push(0); //adds number to queue
//          digitalWrite(redLed,LOW);//turn on red LEDs
//          delay(ledDelay);
//          int bytesSent = Serial.write("RED ");
//          break;
//        }
//        case 1: //green LED
//        {
//          digitalWrite(greenLed,HIGH);//turn on green LEDs
//          greenBeep(); // turns on buzzer
//          queue.push(2); //adds number to queue
//          digitalWrite(greenLed,LOW);//turn off green LEDs
//          delay(ledDelay);
//          int bytesSent = Serial.write("GREEN ");
//          break;
//        }
//        case 2: //blue LED
//        {
//          digitalWrite(blueLed,HIGH);//turn on blue LEDs
//          blueBeep(); // turns on buzzer
//          queue.push(1); //adds number to queue
//          digitalWrite(blueLed,LOW);//turn off blue LEDs
//          delay(ledDelay);
//          int bytesSent = Serial.write("BLUE  ");
//          break;
//        }
//        case 3: //yellow LED
//        {
//          digitalWrite(yellowLed,HIGH);//turn on yellow LEDs
//          yellowBeep(); // turns on buzzer
//          queue.push(3); //adds number to queue
//          digitalWrite(yellowLed,LOW);//turn off yellow LEDs
//          delay(ledDelay);
//          int bytesSent = Serial.write("YELLOW  ");
//          break;
//        }
//      }
//    }
//
//
//  int queueSize = queue.count();
//  
//  for(int i = 0; i < queueSize; i++)
//  {
//      int choice = 4;
//      
//      while(choice >3)
//      {
//      }
//      
//        switch(buttonPressReturn())
//        { 
//          //top LED
//          case 0:
//          {
//            digitalWrite(redLed,HIGH);//turn on red LEDs
//            redBeep(); // plays the red note
//            digitalWrite(redLed,LOW);//turn off red LEDs
//            delay(ledDelay);
//            choice = 0;
//            break;
//          }
//          //Bottom LED
//          case 1:
//          {          
//            digitalWrite(greenLed,HIGH);//turn on green LEDs
//            greenBeep(); // plays the green note
//            digitalWrite(greenLed,LOW);//turn off green LEDs
//            delay(ledDelay);
//            choice = 1;
//            break;
//          }
//          //Left LED
//          case 2:
//          {
//            digitalWrite(blueLed,HIGH);//turn on blue LEDs
//            blueBeep(); // plays the blue note
//            digitalWrite(blueLed,LOW);//turn off blue LEDs
//            delay(ledDelay);
//            choice = 2;
//            break;
//          }
//          //Right LED
//          case 3:
//          {
//            digitalWrite(yellowLed,HIGH);//turn on yellow LEDs
//            yellowBeep(); // plays the yellow note
//            digitalWrite(yellowLed,LOW);//turn off yellow LEDs
//            delay(ledDelay);
//            choice = 3;
//            break;
//          }
//          default:
//          {
//            clearQueue();
//            failMelody();
//            return;
//          }
//        }
//        
//        if(choice == queue.front())
//        {
//          //removes item from the queue
//          queue.pop();
//          start = true;
//        }
//        //checks if queue us empty
//        if(queue.count() == 0)
//        {
//        digitalWrite(yellowLed,HIGH);//turn on yellow LEDs
//        digitalWrite(blueLed,HIGH);//turn on blue LEDs
//        digitalWrite(greenLed,HIGH);//turn on green LEDs
//        digitalWrite(redLed,HIGH);//turn on red LEDs
//        winningMelody();
//        delay(750);
//        digitalWrite(yellowLed,LOW);//turn on yellow LEDs
//        digitalWrite(blueLed,LOW);//turn on blue LEDs
//        digitalWrite(greenLed,LOW);//turn on green LEDs
//        digitalWrite(redLed,LOW);//turn on red LEDs
//        //lets the player advance to the next level
//        start = true;
//        break;
//        }
//
//        
//      }
//    }
//    winningMelody();
//    //adds one to levels. This means the user will have to deal with guessing more colours
//    level++;
//    delay(3000);
//  }
//=============================================================================================

//clears the queue
void clearQueue()
{
  int queueSize = queue.count();

  for(int i; i< queueSize; i++)
  {
    queue.pop();
  }
}

//=============================================================================================

//****************MUSIC SECTION****************

//note when red is lit up
void redBeep()
{
    int noteDuration = 750;
    tone(buzzerPin, melodyRed, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
}

//=============================================================================================

//note when green is lit up
void greenBeep()
{
    int noteDuration = 750;
    tone(buzzerPin, melodyGreen, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
}

//=============================================================================================

//note when blue is lit up
void blueBeep()
{
    int noteDuration = 750;
    tone(buzzerPin, melodyBlue, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
}

//=============================================================================================

//note when yellow is lit up
void yellowBeep()
{
    int noteDuration = 750;
    tone(buzzerPin, melodyYellow, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
}

//=============================================================================================

//plays the start up melody/winning the game
void startUpMelody()
{
  tone(buzzerPin, melodyStart[1]);
  delay(833);
  noTone(buzzerPin);

  tone(buzzerPin, melodyStart[2]);
  delay(333);
  noTone(10);

  tone(buzzerPin, melodyStart[3]);
  delay(333);
  noTone(buzzerPin);

  tone(buzzerPin, melodyStart[4]);
  delay(333);
  noTone(buzzerPin);

  tone(buzzerPin, melodyStart[5]);
  noTone(buzzerPin);

  tone(buzzerPin, melodyStart[6]);
  noTone(buzzerPin);
}

void winningMelody()
{
  for(int thisNote = 0; thisNote < 3; thisNote++)
  {
    int noteDuration = 1200 / noteDurations[thisNote];
    tone(buzzerPin, winMelody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.05;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}

//=============================================================================================

//melody for failing the game
void failMelody()
{
  // iterates over the notes in the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) 
  {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
}
//***************MUSIC SECTION END**************

//=============================================================================================
