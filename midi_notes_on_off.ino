#include <MIDI.h>

/*
 * A simple programme that will change the intensity of
 * an LED based  * on the amount of light incident on 
 * the photo resistor.
 * 
 */

//PhotoResistor Pin
int lightPin = 0; //the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)
//LED Pin
int micha = 9;
int ledMIDIOut = 3;   
int ledMIDIIn1 = 1;
int ledMIDIIn2 = 2;
int i;

void setup()
{
  pinMode(ledMIDIOut, OUTPUT); //sets the led pin to output
  MIDI.begin();
  Serial.begin(115200);
  
}
 /*
 * loop() - this function will start after setup 
 * finishes and then repeat
*/
void loop(){
  
  //Low pitch noteon, light on .5'
  MIDI.sendNoteOn(38, 60, 1);
  delay(2);
  for(i=51;i--; i<=0){
  analogWrite(ledMIDIOut, i*5);
    delay(4);     
  }
 delay(2);
 
 
 //low pitch noteoff, light fade out
  MIDI.sendNoteOff(38, 0, 1);
 delay(2);
 
   //High pitch noteon, light on .5'
  MIDI.sendNoteOn(41, 60, 1);
  delay(2);
  for(i=51;i--; i<=0){
  analogWrite(micha, i*5);
    delay(4);     
  }
 delay(2);
 
 
 
  //High pitch noteoff, light fade out
  MIDI.sendNoteOff(41, 0, 1);
 
 delay(2);

}

 /*
 int i;
 int j;
 
 void loop(){
   for(i=0; i++; i>128){
     MIDI.sendControlChange(1, i, 1);
     delay(200);
   }
   delay(500);
   for(j=128; j--; j>0){
     MIDI.sendControlChange(1, j, 1);
     delay(200);
   }
     delay(500);
 }
 */
