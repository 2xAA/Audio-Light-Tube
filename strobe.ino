boolean strobeOn = true;

void strobe() {
  int strobeVal = 255;
  
  
  if(strobeOn) {
    strobeVal = 255;
  } else {
    strobeVal = 0;
  }

  strobeOn = !strobeOn;
  
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(strobeVal,strobeVal,strobeVal));
  }
  pixels.show();

  delay(10);

  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();

  delay(40);
}

