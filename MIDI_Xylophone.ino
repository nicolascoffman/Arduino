//All the things
#include "FastLED.h"
#define NUM_LEDS 56
#define DATA_PIN 1
#define MIDI_Channel 1
#define NOTE_LENGTH 4000
int threshold = 475;
int programNo = 2;


//MIDI Notes

int scale[8] = {
  36, 37, 38, 39, 40, 41, 42, 43
};



// Define the array of leds
CRGB leds[NUM_LEDS];

int numberedLEDS [8][7] = {
  {0,1,2,3,4,5,6} 
  ,
  {13,12,11,10,9,8,7} 
  ,
  {14,15,16,17,18,19,20} 
  ,
  {27,26,25,24,23,22,21} 
  ,
  {28,29,30,31,32,33,34} 
  ,
  {41,40,39,38,37,36,35} 
  ,
  {42,43,44,45,46,47,48} 
  ,
  {55,54,53,52,51,50,49}
};

//int infoLEDS [4] = {56, 57, 58, 59};

int barTimer [8];


//FUNctions

//LED Stuff
class allLEDs
{
public:
  void setBarColor(int barNumber, int red, int green, int blue){
    for(int q=0; q<7; q++){
      leds[numberedLEDS[barNumber-1][q]].setRGB(green, red, blue);
    }
    FastLED.show();
  }

  /*  void setInfoColor(int ledNumber, int red, int green, int blue){
   leds[infoLEDS[ledNumber-1]].setRGB(green, red, blue);
   FastLED.show();
   }
   */
  void setAllBars(int red, int green, int blue){
    for(int a=0; a<8; a++){
      for(int b=0; b<7; b++){
        leds[numberedLEDS[a][b]].setRGB(green, red, blue);
      }
    }
    FastLED.show();
  }
void setBarLED(int bar, int led, int red, int green, int blue){
    leds[numberedLEDS[bar-1][led-1]].setRGB(green, red, blue);
    FastLED.show();
  }
};
allLEDs myLEDs;


// color scenes


void sceneColor(int program, int bar){
  switch(program){
    case 1:
        rainbowPent(bar);
      break;
    case 2:
         colorLength(bar);
        break;
     case 3:
         drumRack(bar);
      break;
      case 4:
        screenSaver(bar);
        break;
  }
}


   void rainbowPent(int bar){
        switch(bar){
          case 1:
        myLEDs.setBarColor(1, 150, 0, 150);
          break;
          case 2:
        myLEDs.setBarColor(2, 80, 0, 200);
          break;
          case 3:
        myLEDs.setBarColor(3, 50, 0, 255);
          break;
          case 4:
        myLEDs.setBarColor(4, 0, 0, 255);
          break;
          case 5:
        myLEDs.setBarColor(5, 0, 150, 150);
          break;
          case 6:
        myLEDs.setBarColor(6, 150, 0, 150);
          break;
          case 7:
        myLEDs.setBarColor(7, 80, 0, 200);
          break;
          case 8:
        myLEDs.setBarColor(8, 50, 0, 255);
          break;
      };
   }
       void drumRack(int bar){
         switch(bar){ 
         case 1:
            myLEDs.setBarColor(1, 150, 0, 255);
          break;
          case 2:
            myLEDs.setBarColor(2, 255, 0, 150);
            break;
          case 3:
            myLEDs.setBarColor(3, 200, 200, 0);
            break;
          case 4:
            myLEDs.setBarColor(4, 200, 200, 10);
            break;
          case 5:
            myLEDs.setBarColor(5, 0, 0, 0);
            break;
          case 6:
            myLEDs.setBarColor(6, 0, 0, 255);
            break;
          case 7:
            myLEDs.setBarColor(7, 0, 120, 240);
            break;
          case 8:
            myLEDs.setBarColor(8, 0, 120, 240);
            break;
      };
       } 
      void colorLength(int bar){
          switch(bar){
          case 1:
          myLEDs.setBarLED(1, 1, 0, 0, 255);
          myLEDs.setBarLED(1, 2, 0, 0, 255);
          myLEDs.setBarLED(1, 3, 70, 0, 50);
          myLEDs.setBarLED(1, 4, 255, 0, 0);
          myLEDs.setBarLED(1, 5, 70, 0, 50);
          myLEDs.setBarLED(1, 6, 0, 0, 255);
          myLEDs.setBarLED(1, 7, 0, 0, 255);
          break;
          case 2:
          myLEDs.setBarLED(2, 1, 0, 0, 255);
          myLEDs.setBarLED(2, 2, 0, 0, 255);
          myLEDs.setBarLED(2, 3, 70, 0, 50);
          myLEDs.setBarLED(2, 4, 255, 0, 0);
          myLEDs.setBarLED(2, 5, 70, 0, 50);
          myLEDs.setBarLED(2, 6, 0, 0, 255);
          myLEDs.setBarLED(2, 7, 0, 0, 255);
          break;
          case 3:
          myLEDs.setBarLED(3, 1, 0, 0, 255);
          myLEDs.setBarLED(3, 2, 0, 0, 255);
          myLEDs.setBarLED(3, 3, 120, 40, 0);
          myLEDs.setBarLED(3, 4, 240, 80, 0);
          myLEDs.setBarLED(3, 5, 120, 40, 0);
          myLEDs.setBarLED(3, 6, 0, 0, 255);
          myLEDs.setBarLED(3, 7, 0, 0, 255);
          break;
          case 4:
          myLEDs.setBarLED(4, 1, 0, 0, 255);
          myLEDs.setBarLED(4, 2, 0, 0, 255);
          myLEDs.setBarLED(4, 3, 120, 40, 0);
          myLEDs.setBarLED(4, 4, 240, 80, 0);
          myLEDs.setBarLED(4, 5, 120, 40, 0);
          myLEDs.setBarLED(4, 6, 0, 0, 255);
          myLEDs.setBarLED(4, 7, 0, 0, 255);
          break;
          case 5:
          myLEDs.setBarLED(5, 1, 0, 0, 255);
          myLEDs.setBarLED(5, 2, 0, 0, 255);
          myLEDs.setBarLED(5, 3, 120, 192, 0);
          myLEDs.setBarLED(5, 4, 159, 255, 0);
          myLEDs.setBarLED(5, 5, 120, 192, 0);
          myLEDs.setBarLED(5, 6, 0, 0, 255);
          myLEDs.setBarLED(5, 7, 0, 0, 255);
          break;
          case 6:
          myLEDs.setBarLED(6, 1, 0, 0, 255);
          myLEDs.setBarLED(6, 2, 0, 0, 255);
          myLEDs.setBarLED(6, 3, 120, 192, 0);
          myLEDs.setBarLED(6, 4, 159, 255, 0);
          myLEDs.setBarLED(6, 5, 120, 192, 0);
          myLEDs.setBarLED(6, 6, 0, 0, 255);
          myLEDs.setBarLED(6, 7, 0, 0, 255);
          break;
          case 7:
          myLEDs.setBarLED(7, 1, 0, 0, 255);
          myLEDs.setBarLED(7, 2, 0, 0, 255);
          myLEDs.setBarLED(7, 3, 0, 180, 0);
          myLEDs.setBarLED(7, 4, 0, 255, 0);
          myLEDs.setBarLED(7, 5, 0, 180, 0);
          myLEDs.setBarLED(7, 6, 0, 0, 255);
          myLEDs.setBarLED(7, 7, 0, 0, 255);
          break;
          case 8:
          myLEDs.setBarLED(8, 1, 0, 0, 255);
          myLEDs.setBarLED(8, 2, 0, 0, 255);
          myLEDs.setBarLED(8, 3, 0, 180, 0);
          myLEDs.setBarLED(8, 4, 0, 255, 0);
          myLEDs.setBarLED(8, 5, 0, 180, 0);
          myLEDs.setBarLED(8, 6, 0, 0, 255);
          myLEDs.setBarLED(8, 7, 0, 0, 255);
          break;
        };
      }
      
    void screenSaver(int bar){
      for(int z = 0; z<4; z++){
      for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		leds[i].setRGB(255, 0, 0);
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i].setRGB(0, 0, 0);
		// Wait a little bit before we loop around and do it again
		delay(30);
	}

	// Now go in the other direction.  
	for(int i = NUM_LEDS-1; i >= 0; i--) {
		// Set the i'th led to red 
		leds[i].setRGB(255, 0, 0);
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i].setRGB(0, 0, 0);
		// Wait a little bit before we loop around and do it again
		delay(30);
	}
      }
      for(int y = 0; y<4; y++){
       myLEDs.setBarColor(1, 255, 0, 0);
  myLEDs.setBarColor(2, 200, 70, 0);
  myLEDs.setBarColor(3, 150, 150, 0);
  myLEDs.setBarColor(4, 0, 255, 0);
  myLEDs.setBarColor(5, 0, 200, 70);
  myLEDs.setBarColor(6, 0, 70, 200);
  myLEDs.setBarColor(7, 0, 0, 255);
  myLEDs.setBarColor(8, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(2, 255, 0, 0);
  myLEDs.setBarColor(3, 200, 70, 0);
  myLEDs.setBarColor(4, 150, 150, 0);
  myLEDs.setBarColor(5, 0, 255, 0);
  myLEDs.setBarColor(6, 0, 200, 70);
  myLEDs.setBarColor(7, 0, 70, 200);
  myLEDs.setBarColor(8, 0, 0, 255);
  myLEDs.setBarColor(1, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(3, 255, 0, 0);
  myLEDs.setBarColor(4, 200, 70, 0);
  myLEDs.setBarColor(5, 150, 150, 0);
  myLEDs.setBarColor(6, 0, 255, 0);
  myLEDs.setBarColor(7, 0, 200, 70);
  myLEDs.setBarColor(8, 0, 70, 200);
  myLEDs.setBarColor(1, 0, 0, 255);
  myLEDs.setBarColor(2, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(4, 255, 0, 0);
  myLEDs.setBarColor(5, 200, 70, 0);
  myLEDs.setBarColor(6, 150, 150, 0);
  myLEDs.setBarColor(7, 0, 255, 0);
  myLEDs.setBarColor(8, 0, 200, 70);
  myLEDs.setBarColor(1, 0, 70, 200);
  myLEDs.setBarColor(2, 0, 0, 255);
  myLEDs.setBarColor(3, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(4, 255, 0, 0);
  myLEDs.setBarColor(5, 200, 70, 0);
  myLEDs.setBarColor(6, 150, 150, 0);
  myLEDs.setBarColor(7, 0, 255, 0);
  myLEDs.setBarColor(8, 0, 200, 70);
  myLEDs.setBarColor(1, 0, 70, 200);
  myLEDs.setBarColor(2, 0, 0, 255);
  myLEDs.setBarColor(3, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(5, 255, 0, 0);
  myLEDs.setBarColor(6, 200, 70, 0);
  myLEDs.setBarColor(7, 150, 150, 0);
  myLEDs.setBarColor(8, 0, 255, 0);
  myLEDs.setBarColor(1, 0, 200, 70);
  myLEDs.setBarColor(2, 0, 70, 200);
  myLEDs.setBarColor(3, 0, 0, 255);
  myLEDs.setBarColor(4, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(6, 255, 0, 0);
  myLEDs.setBarColor(7, 200, 70, 0);
  myLEDs.setBarColor(8, 150, 150, 0);
  myLEDs.setBarColor(1, 0, 255, 0);
  myLEDs.setBarColor(2, 0, 200, 70);
  myLEDs.setBarColor(3, 0, 70, 200);
  myLEDs.setBarColor(4, 0, 0, 255);
  myLEDs.setBarColor(5, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(7, 255, 0, 0);
  myLEDs.setBarColor(8, 200, 70, 0);
  myLEDs.setBarColor(1, 150, 150, 0);
  myLEDs.setBarColor(2, 0, 255, 0);
  myLEDs.setBarColor(3, 0, 200, 70);
  myLEDs.setBarColor(4, 0, 70, 200);
  myLEDs.setBarColor(5, 0, 0, 255);
  myLEDs.setBarColor(6, 128, 0, 128);
  delay(250);
  myLEDs.setBarColor(8, 255, 0, 0);
  myLEDs.setBarColor(1, 200, 70, 0);
  myLEDs.setBarColor(2, 150, 150, 0);
  myLEDs.setBarColor(3, 0, 255, 0);
  myLEDs.setBarColor(4, 0, 200, 70);
  myLEDs.setBarColor(5, 0, 70, 200);
  myLEDs.setBarColor(6, 0, 0, 255);
  myLEDs.setBarColor(7, 128, 0, 128);
  delay(250);
      }
      
    } 




//MIDI In
void OnNoteOn(byte channel, byte note, byte velocity){
  switch(note){
  case 36:
    myLEDs.setBarColor(1, 255, 0, 0);
    break;
  case 37:
    myLEDs.setBarColor(2, 255, 0, 0);
    break;
  case 38:
    myLEDs.setBarColor(3, 255, 0, 0);
    break;
  case 39:
    myLEDs.setBarColor(4, 255, 0, 0);
    break;
  case 40:
    myLEDs.setBarColor(5, 255, 0, 0);
    break;
  case 41:
    myLEDs.setBarColor(6, 255, 0, 0);
    break;
  case 42:
    myLEDs.setBarColor(7, 255, 0, 0);
    break;
  case 43:
    myLEDs.setBarColor(8, 255, 0, 0);
    break;
  }
}


void OnNoteOff(byte channel, byte note, byte velocity){
  switch(note){
  case 36:
    myLEDs.setBarColor(1, 0, 0, 255);
    break;
  case 37:
    myLEDs.setBarColor(2, 0, 0, 255);
    break;
  case 38:
    myLEDs.setBarColor(3, 0, 0, 255);
    break;
  case 39:
    myLEDs.setBarColor(4, 0, 0, 255);
    break;
  case 40:
    myLEDs.setBarColor(5, 0, 0, 255);
    break;
  case 41:
    myLEDs.setBarColor(6, 0, 0, 255);
    break;
  case 42:
    myLEDs.setBarColor(7, 0, 0, 255);
    break;
  case 43:
    myLEDs.setBarColor(8, 0, 0, 255);
    break;
  }
}


void OnProgramChange(byte channel, byte program){
  for(int j=0; j<8; j++){
sceneColor(program+1, j);
};
programNo = program+1;

}


//barCounter   paired with array barTimer
void barCounter(int barz){   
  if(barTimer[barz] > 1){
    barTimer[barz]--;
  }
  else if(barTimer[barz] == 1){    
    sceneColor(programNo, barz+1);
    usbMIDI.sendNoteOff(scale[barz], 0, MIDI_Channel);
    barTimer[barz] = 0;
  }
};

//Sensor read

class strike
{
public:
  int pitch;
  int volume;
  int count = 0;

  void go(int note, int velocity){
    usbMIDI.sendNoteOn(scale[note], velocity, MIDI_Channel);
    barTimer[note] = NOTE_LENGTH;
    myLEDs.setBarColor(note+1, 0, 255, 0);
  }             

  void sense(){
    for(int z = 0; z<8; z++){
      int bump = analogRead(z);
      pitch = z;
      if(bump > threshold){          
        volume = (bump - threshold)*127/(1023-threshold);
        strike::go(pitch, volume);
        delay(25);
      }

    }
  }

};
strike barStrike; 





//Ready... Set...
void setup() { 

  //FastLED necessary
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  //usbMIDI necessary
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn) ;
  usbMIDI.setHandleProgramChange(OnProgramChange);


  //Hello World!  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(13, HIGH);




  //Setup LEDs for initial
  myLEDs.setAllBars(0, 0, 255);
  //   myLEDs.setInfoColor(4, 0, 255, 0);
  delay(500);


}





//GO!
void loop() {
  usbMIDI.read();

  barStrike.sense();

  for(int m=0; m<8; m++){
    barCounter(m);
  }
}

