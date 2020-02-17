//libraries
#include "pitches.h"
#include "SevSeg.h"

SevSeg sevseg; 

// notes in the melody:
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int melodyStart[] = {NOTE_DS6, NOTE_DS5, NOTE_AS5, NOTE_GS5, NOTE_DS5, NOTE_DS6, NOTE_AS6, NOTE_AS5};

int melodyRed = NOTE_DS3;
int melodyBlue = NOTE_DS4;
int melodyGreen = NOTE_DS5;
int melodyYellow = NOTE_DS6;


// note durations: 4=1/4 note, 8=1/8 note
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

// length of the timer
int timerLength = 5;

void setup()
{
 startUpMelody();

  //set up for the singular digit display
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() 
{
  //Timer counting down from whatever value it is given
  for(int i = timerLength; i > -1; i--)
  {
    sevseg.setNumber(i, i%2);
    delay(1000);
    sevseg.refreshDisplay(); 
  }
}

//note when red is lit up
void redMelody()
{
    int noteDuration = 750;
    tone(10, melodyRed, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(10);
}

//note when green is lit up
void greenMelody()
{
    int noteDuration = 750;
    tone(10, melodyGreen, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(10);
}

//note when blue is lit up
void blueMelody()
{
    int noteDuration = 750;
    tone(10, melodyBlue, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(10);
}

//note when yellow is lit up
void yellowMelody()
{
    int noteDuration = 750;
    tone(10, melodyYellow, noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(10);
}

//plays the start up melody/winning the game
void startUpMelody()
{
  tone(10, melodyStart[1]);
  delay(833);
  noTone(10);

  tone(10, melodyStart[2]);
  delay(333);
  noTone(10);

  tone(10, melodyStart[3]);
  delay(333);
  noTone(10);

  tone(10, melodyStart[4]);
  delay(333);
  noTone(10);

  tone(10, melodyStart[5]);
  noTone(10);

  tone(10, melodyStart[6]);
  noTone(10);
}

//melody for failing the game
void failMelody()
{
  // iterates over the notes in the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) 
  {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(10, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(10);
  }
}
