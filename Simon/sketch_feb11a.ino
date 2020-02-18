/*
 * Simon The Game Version 1.0
 * v2 Joystick_Alpha
 */
const int ib_1 = 1;
int ib_1_state;
const int ib_2 = 2;//input button
int ib_2_state;
const int ib_3 = 3;
int ib_3_state;
const int ib_4 = 4;
int ib_4_state;

const int rgb_1 = 10;
const int rgb_2 = 11;
const int rgb_3 = 12;

const int ol_1 = 5;
const int ol_2 = 6;//output light
const int ol_3 = 7;
const int ol_4 = 8;

const int buzzer_1 = 9;

const int joystick_1 = A4;//joystick
const int joystick_2 = A5;

int randomInt = 0;
boolean start = false;
int diff = 500;


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

    switch(randomInt)
    {
      case 0:
      digitalWrite(ol_1,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_1_state = analogRead(joystick_1);
        ib_2_state = analogRead(joystick_2);//y
      
      if(ib_1_state>=700&&ib_2_state>=511)
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

      case 1:
      digitalWrite(ol_2,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_1_state = analogRead(joystick_1);
        ib_2_state = analogRead(joystick_2);
      
      if(ib_1_state>=511&&ib_2_state>=700)
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

      case 2://red
      digitalWrite(ol_3,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_1_state = analogRead(joystick_1);
        ib_2_state = analogRead(joystick_2);//y
      
      if(ib_1_state<=500&&ib_2_state>=500)
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

      case 3:
      digitalWrite(ol_4,HIGH);
      delay(diff);
      for(int i=0;i<diff;i++)
      {
        ib_1_state = analogRead(joystick_1);
        ib_2_state = analogRead(joystick_2);
      
      if(ib_2_state<=500&&ib_1_state>=500)
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
        digitalWrite(ol_1,LOW);
        digitalWrite(ol_2,LOW);
        digitalWrite(ol_3,LOW);
        digitalWrite(ol_4,LOW);
        ib_1_state = 0;
        ib_2_state = 0;
  }

  
}
