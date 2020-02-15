/*
 * Simon The Game Version 1.0
 * Currently this game can use up 4 LEDS and 4 Buttons. Due to limitations in available hardware no other input sources are available
 * v1.0 Sameer Al Harbi 15/02/2020
 */
const int ib_1 = 1;
int ib_1_state;
const int ib_2 = 2;//input button
int ib_2_state;
const int ib_3 = 3;
int ib_3_state;
const int ib_4 = 4;
int ib_4_state;

const int ol_1 = 5;
const int ol_2 = 6;//output light
const int ol_3 = 7;
const int ol_4 = 8;

const int buzzer_1 = 9;

const int joystick_1 = A0;//joystick

int randomInt = 0;
boolean start = false;
int diff = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(ib_1,INPUT);
  pinMode(ib_2,INPUT);
  pinMode(ib_3,INPUT);
  pinMode(ib_4,INPUT);

  pinMode(joystick_1,INPUT);

  pinMode(ol_1,OUTPUT);
  pinMode(ol_2,OUTPUT);
  pinMode(ol_3,OUTPUT);
  pinMode(ol_4,OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

  ib_1_state = digitalRead(ib_1);
  if(ib_1_state==HIGH)
  {
    start = true;
  }

  if(start==true)
  {
    randomInt = random(0,3);

    switch(randomInt)
    {
      case 0:
      digitalWrite(ol_1,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_1_state = digitalRead(ib_1);
      
      if(ib_1_state==HIGH)
      {
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;

      case 1:
      digitalWrite(ol_2,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_2_state = digitalRead(ib_2);
      
      if(ib_2_state==HIGH)
      {
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;

      case 2:
      digitalWrite(ol_3,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_3_state = digitalRead(ib_3);
      
      if(ib_3_state==HIGH)
      {
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;

      case 3:
      digitalWrite(ol_4,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_4_state = digitalRead(ib_4);
      
      if(ib_4_state==HIGH)
      {
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;
    }
        digitalWrite(ol_1,LOW);
        digitalWrite(ol_2,LOW);
        digitalWrite(ol_3,LOW);
        digitalWrite(ol_4,LOW);
  }

  
}