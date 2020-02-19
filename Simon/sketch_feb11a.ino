/*
 * Simon The Game Version 1.0
 * v2.1 Pre-Release Versio
 * Sameer Al Harbi
 */
const int ib_1 = 1;
int ib_1_state;
const int ib_2 = 2;
int ib_2_state;
const int ib_3 = 3;//Start Button
int ib_3_state;
const int ib_4 = 4;
int ib_4_state;

const int ol_1 = 5;
const int ol_2 = 6;//output lights
const int ol_3 = 7;
const int ol_4 = 8;

const int buzzer_1 = 9;

const int joystick_1 = A4;//joystick x
int joyState_x;
const int joystick_2 = A5;//joystick y
int joyState_y;


int randomInt = 0;
boolean start = false;
int diff = 650;


void setup() {
  // put your setup code here, to run once:
  pinMode(ib_1,INPUT);
  pinMode(ib_2,INPUT);
  pinMode(ib_3,INPUT);
  pinMode(ib_4,INPUT);

  pinMode(ol_1,OUTPUT);
  pinMode(ol_2,OUTPUT);
  pinMode(ol_3,OUTPUT);
  pinMode(ol_4,OUTPUT);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  
  ib_3_state = digitalRead(ib_3);
  if(ib_3_state==HIGH)
  {
    start = true;
  }

  if(start==true)
  {
    randomInt = random(0,4);

    switch(randomInt)//check random value
    {
      case 0://led 1
      digitalWrite(ol_1,HIGH);//turn on led
      delay(diff);
      for(int i=0;i<diff;i++)//get user input for diff milisecs
      {
        joyState_x = analogRead(joystick_1);//x
        joyState_y = analogRead(joystick_2);//y
      
      if(joyState_x>=700&&joyState_y>=511)//analog vale check
      {
        i = diff;//stop for loop
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;

      case 1://led 2
      digitalWrite(ol_2,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
         joyState_x = analogRead(joystick_1);//x
         joyState_y = analogRead(joystick_2);//y
         
      if(joyState_x>=511&&joyState_y>=700)
      {
        i = diff;
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;

      case 2://led 3
      digitalWrite(ol_3,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        joyState_x = analogRead(joystick_1);//x
        joyState_y = analogRead(joystick_2);//y
      
      if(joyState_x<=500&&joyState_y>=500)
      {
        i = diff;
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;

      case 3://led 4
      digitalWrite(ol_4,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        joyState_x = analogRead(joystick_1);//x
        joyState_y = analogRead(joystick_2);//y
      
      if(joyState_x<=500&&joyState_y>=500)
      {
        i = diff;
        digitalWrite(ol_1,HIGH);
        digitalWrite(ol_2,HIGH);
        digitalWrite(ol_3,HIGH);
        digitalWrite(ol_4,HIGH);
        delay(diff*2);
      }
      }
      break;
    }
        //clear all
        digitalWrite(ol_1,LOW);
        digitalWrite(ol_2,LOW);
        digitalWrite(ol_3,LOW);
        digitalWrite(ol_4,LOW);
        ib_1_state = 0;
        ib_2_state = 0;
  }

  
}
