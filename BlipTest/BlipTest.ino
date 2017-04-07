// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      50

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.

  Serial.begin(115200);
}

void StarBlip(int startPixel, int endPixel, int speed){

int brightnessDestination = random(0, 255);


  for (int brightness=0; brightness<=brightnessDestination;++brightness)
  {
    for(int i=startPixel;i<endPixel;i++)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      
  
    if(brightness > brightnessDestination)
    {
      brightness = brightness - 1;
    }

    pixels.setPixelColor(i, pixels.Color(brightness, brightness, brightness));
  }
  
  
  pixels.show(); // This sends the updated pixel color to the hardware.
  
  delay(speed); // Delay for a period of time (in milliseconds);
}
  }


int StarBlipStayOn(int startBrightness, int startPixel, int endPixel, int speed){

int brightnessDestination = random(0, 255);


 for (int brightness=startBrightness; brightness!=brightnessDestination;)
  {
    for(int i=startPixel;i<endPixel;i++)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      
      pixels.setPixelColor(i, pixels.Color(brightness, brightness, brightness));
    }
    
    if(brightness > brightnessDestination)
    {
      brightness = brightness - 1;
    }
    else
    {
      brightness = brightness + 1;
    }
  
  
  pixels.show(); // This sends the updated pixel color to the hardware.
  
  delay(speed); // Delay for a period of time (in milliseconds);
}
return brightnessDestination;
  }  


  

int lastBrightness = 0;
void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  Serial.println(lastBrightness);
lastBrightness = StarBlipStayOn(lastBrightness, 22, 50, 10);

  //This is where the code actually starts. I just needed some room to think and not have to look at the ugly code.


}
