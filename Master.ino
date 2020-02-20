/*
 * Simon The Game Version 1.0
 * v2.2 Pre-Release Version
 * Daniel Jakubek
 */
//Arduino wire library
#include <Wire.h>

//include queue library
#include <QueueArray.h>

//include elapsedMillies library
#include <elapsedMillis.h>

// Include Slave I2C address
#define SLAVE_ADDR 9

// variable used for the timer
int interval = 10000; 
boolean timerOut = false;
elapsedMillis timeElapsed;

//variables for the buttons and their states
const int ib_1 = 1;
int ib_1_state;
const int ib_2 = 2;
int ib_2_state;
const int ib_3 = 3;//Start Button
int ib_3_state;
const int ib_4 = 4;
int ib_4_state;

//variables for all of the LEDs
const int redLed = 5;
const int blueLed = 6;//output lights
const int greenLed = 7;
const int yellowLed = 8;

//variables for the joystick
const int joystick_1 = A4;//joystick x
int joyState_x;
const int joystick_2 = A5;//joystick y
int joyState_y;

//Setting the value of the random number to 0 as default
int randomInt = 0;
boolean start = false;
int diff = 650;

//queue that stores the led order
QueueArray <int> queue;

// The value that will be sent to the slave
int blop =  0;

//============

void setup() 
{
  // Initialize I2C communications as master
  Wire.begin();
  
  //Sets up the buttons
  pinMode(ib_1,INPUT);
  pinMode(ib_2,INPUT);
  pinMode(ib_3,INPUT);
  pinMode(ib_4,INPUT);

  //Sets up the LEDs
  pinMode(redLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);

}

//============

void loop() 
{
  if(timeElapsed == 10000) 
  {
    //local varaible that is transmitted to the slave to tell it that start button was pressed
    blop = 6;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(blop);
    Wire.endTransmission();
  }
  else if (timeElapsed > interval) 
  {       
    timerOut = true;
  }
  
  //starts the game
  startGame();
}

//============

// Checks if the start button is pressed and then sends a boolean value to the slave if
// the button has been pressed.
void startSound()
{
  ib_3_state = digitalRead(ib_3);

  //starts to communicate with the slave and sends boolean value it's way
  if(ib_3_state == HIGH)
  {
     start = true;
     Wire.beginTransmission(SLAVE_ADDR);
     Wire.write(start);
     Wire.endTransmission();
  }
  else
  {
    //nothing
  }
}

//============

//simon says game
void startGame()
{
  int levels = 1; //sets the user's level to 1
  startSound(); //plays start up melody
  
  while(start == true)
  {
    start == false;
  
    //loops for the number of level the player is on
    for(int i = 0; i < levels; i++)
    {
      //creates a random number
      randomInt = random(0,4);
  
      switch(randomInt)
      {
        case 0: //red LED
        {
          digitalWrite(redLed,HIGH);//turn on red LEDs
          redBeep(); // turns on buzzer
          queue.enqueue(0); //adds number to queue
        }
        case 1: //green LED
        {
          digitalWrite(greenLed,HIGH);//turn on green LEDs
          greenBeep(); // turns on buzzer
          queue.enqueue(1); //adds number to queue
        }
        case 2: //blue LED
        {
          digitalWrite(blueLed,HIGH);//turn on blue LEDs
          blueBeep(); // turns on buzzer
          queue.enqueue(2); //adds number to queue
        }
        case 3: //yellow LED
        {
          digitalWrite(yellowLed,HIGH);//turn on yellow LEDs
          yellowBeep(); // turns on buzzer
          queue.enqueue(3); //adds number to queue
        }
      }
    }

    //sets guessLoop to the size of the queue 
    int guessLoop = queue.count();

    timeElapsed = 0; // reset the counter to 0 so the counting starts over
    
    for(int i = 0; i < guessLoop; i++)
    {
      if(joystickMovement() == queue.dequeue())
      {
        switch(joystickMovement())
        {
          case 0:
          {
            digitalWrite(redLed,HIGH);//turn on red LEDs
            redBeep();
          }
          case 1:
          {
            digitalWrite(greenLed,HIGH);//turn on green LEDs
            greenBeep();
          }
          case 2:
          {
            digitalWrite(blueLed,HIGH);//turn on blue LEDs
            blueBeep();
          }
          case 3:
          {
            digitalWrite(yellowLed,HIGH);//turn on yellow LEDs
            yellowBeep();
          }
        }

        //removes item from the queue
        queue.dequeue();
        //the player has succeded
        start = true;
      }
      //if the queue us empty the player has completed that level
      else if(queue.isEmpty())
      {
        startSound(); // plays happy melody, letting the player know they one that level
        digitalWrite(yellowLed,HIGH);//turn on yellow LEDs
        digitalWrite(blueLed,HIGH);//turn on blue LEDs
        digitalWrite(greenLed,HIGH);//turn on green LEDs
        digitalWrite(redLed,HIGH);//turn on red LEDs
        delay(750);
        digitalWrite(yellowLed,LOW);//turn on yellow LEDs
        digitalWrite(blueLed,LOW);//turn on blue LEDs
        digitalWrite(greenLed,LOW);//turn on green LEDs
        digitalWrite(redLed,LOW);//turn on red LEDs
      }
      //condition when timer runs out
      else if(timerOut == true)
      {
        // sad beep plays, the player has failed, the loop is exited
        failBeep();
        break;
      }
      //condition when wrong input
      else
      {
        // sad beep plays, the player has failed, the loop is exited
        failBeep();
        break;
      }
    }
      //adds one to levels. This means the user will have to deal with guessing more colours
      levels++;
      delay(3000);
    }
}

//============

//returns a value corresponding to the player's movement
int joystickMovement()
{
  joyState_x = analogRead(joystick_1);//x
  joyState_y = analogRead(joystick_2);//y

  if(joyState_x>=700&&joyState_y>=511)
  {
    return 0; //red led
  }
  else if(joyState_x>=511&&joyState_y>=700)
  {
    return 1; //green led
  }
  else if(joyState_x<=500&&joyState_y>=500)
  {
    return 2; //blue led
  }
  else if(joyState_x<=500&&joyState_y>=500)
  {
    return 3; //yellow led
  }
}

//============

//Communicates with the slave. Tells it the value of blop
void startBeep ()
{
  //local varaible that is transmitted to the slave to tell it that start button was pressed
  blop = 0;
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(blop);
  Wire.endTransmission();
}

//============

//Communicates with the slave. Tells it the value of blop
void redBeep()
{
  //local varaible that is transmitted to the slave to tell it that the red light has went on
  blop = 1;
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(blop);
  Wire.endTransmission();
}

//============

//Communicates with the slave. Tells it the value of blop
void greenBeep()
{
  //local varaible that is transmitted to the slave to tell it that the green light has went on
  blop = 2;
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(blop);
  Wire.endTransmission();
}

//============

//Communicates with the slave. Tells it the value of blop
void blueBeep()
{
  //local varaible that is transmitted to the slave to tell it that the blue light has went on
  blop = 3;
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(blop);
  Wire.endTransmission();
}

//============

//Communicates with the slave. Tells it the value of blop
void yellowBeep()
{
  //local varaible that is transmitted to the slave to tell it that the yellow light has went on
  blop = 4;
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(blop);
  Wire.endTransmission();
}

//============

//Communicates with the slave. Tells it the value of blop
void failBeep()
{
  //local varaible that is transmitted to the slave to tell it that the yellow light has went on
  blop = 5;
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(blop);
  Wire.endTransmission();
}

//============END
