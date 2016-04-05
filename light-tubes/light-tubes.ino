#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NEOPIN          6
#define NUMPIXELS      27

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIN, NEO_GRB + NEO_KHZ800);

AudioInputAnalog         adc1;
AudioAnalyzePeak         peak1;
AudioAnalyzeRMS          rms1;
AudioAnalyzeFFT256       fft1;
AudioConnection          patchCord1(adc1, peak1);
AudioConnection          patchCord2(adc1, fft1);
AudioConnection          patchCord3(adc1, rms1);

int rgbColour[3];
int mode = 0; //default mode
int modes = 6; //num modes

const int buttonPin = 2;     // button pin
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
bool pressed = false;

int MAXBRIGHTNESS = 255;

void setup() {
  pinMode(buttonPin, INPUT);

  AudioMemory(16);
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(255); // 0-255
  
  // Start off with red.
  rgbColour[0] = 150;
  rgbColour[1] = 0;
  rgbColour[2] = 0; 
}

elapsedMillis fps;
float floatPeak = 0;
int monoPeak = 0;
int maxPeak = 0;
bool initialised = false;
float rmsValue = 0.0;

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() { 

  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH && pressed == false) {
      
      // if the current state is HIGH then the button
      // wend from off to on:
      if(mode+1 < modes) mode++;
      else mode = 0;
      pressed = true;
      
      // clear the strip
      for(int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
    }
    
  }

  if(buttonState == LOW) {
    pressed = false;
  }
  
  if (fps > 24 || initialised) {
    if (peak1.available()) {
      initialised = true;
      
      floatPeak = peak1.read() * 30.0;
      monoPeak = floatPeak;
      if(maxPeak < monoPeak) maxPeak = monoPeak;
      if(mode == 0) vuMeter();
    }

    if(rms1.available()) {
      rmsValue = rms1.read();
    }

    
    if(mode == 1) fftBlink();
    if(mode == 2) rms();
    if(mode == 3) chaseStrobe();
  }
  
  if(mode == 4) strobe();
  if(mode == 5) multiStrobe();
}
