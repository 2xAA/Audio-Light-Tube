int peakPointer = 0;
int pixelsLast = 0;
int pointerCount = 0;

// Rainbow color changing RGB
int counter = 0;
// Number of colors used for animating, higher = smoother and slower animation)
int numColors = 255;

void vuMeter() {
  int pixelsOn = 0;
  pixelsOn = map(monoPeak, 0, maxPeak, 0, NUMPIXELS);
  //float pixFloat = mapfloat(floatPeak, 0.0, (float)maxPeak, 0.0, (float)NUMPIXELS);
  
  // This part takes care of displaying the
  // color changing in reverse by counting backwards if counter
  // is above the number of available colors  
  float colorNumber = counter > numColors ? counter - numColors: counter;
  
  // Play with the saturation and brightness values
  // to see what they do
  float saturation = 1; // Between 0 and 1 (0 = gray, 1 = full color)
  float brightness = .5; // Between 0 and 1 (0 = dark, 1 is full brightness)
  float hue = (colorNumber / float(numColors)) * 360; // Number between 0 and 360
  long color = HSBtoRGB(hue, saturation, brightness); 
  
  // Get the red, blue and green parts from generated color
  int red = color >> 16 & 255;
  int green = color >> 8 & 255;
  int blue = color & 255;
  
  for(int i=0; i<NUMPIXELS; i++) {
    if(i == pixelsOn-1) {
          
      long lastColor = HSBtoRGB(hue, saturation, mapfloat(floatPeak, 0.0, maxPeak, 0, 10)/10); 
      //Serial.println(mapfloat(floatPeak, 0.0, maxPeak, 0, 10)/10);
      
      int lastRed = lastColor >> 16 & 255;
      int lastGreen = lastColor >> 8 & 255;
      int lastBlue = lastColor & 255;
      pixels.setPixelColor(pixelsOn-1, pixels.Color(lastRed, lastGreen, lastBlue));
    } else if(i > (NUMPIXELS-pixelsLast)) {
      pixels.setPixelColor(NUMPIXELS-1-i, pixels.Color(red, green, blue));
    } else {
      pixels.setPixelColor(NUMPIXELS-1-i, pixels.Color(0,0,0));
    }
  }
      
  // peak pointer
  color = HSBtoRGB(abs(180.0-hue), saturation, brightness); 
  
  // Get the inversed red, blue and green parts from generated color
  red = color >> 16 & 255;
  green = color >> 8 & 255;
  blue = color & 255;
  pixels.setPixelColor(peakPointer-1, pixels.Color(red, green, blue));
  pixels.show();

  if(pointerCount >= 100) {
    if(pointerCount == 115) {
      pointerCount = 100;
      peakPointer-=1;
      //peakPointer+=random(0,2);
    }
  }
  pointerCount++;
  
  pixelsLast = pixelsOn;
  if(pixelsOn > peakPointer) {
    pointerCount = 0;
    peakPointer = pixelsOn;
  }

  // Counter can never be greater than 2 times the number of available colors
  // the colorNumber = line above takes care of counting backwards (nicely looping animation)
  // when counter is larger then the number of available colors
  if(fps >= 2000) {
    counter = (counter + 1) % (numColors * 2);
    fps = 0;
  }
  //Serial.println(fps);
}
