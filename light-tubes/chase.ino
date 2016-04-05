int chasePos = 0;

void chaseStrobe() {

  if(rmsValue > 0.5) {

    for(int i = 0; i < NUMPIXELS; i++) {
      if(i == chasePos) pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      else pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }

    if(chasePos >= NUMPIXELS) chasePos = 0;
    else chasePos++;
    
    delay(20);
    pixels.show();
  }
}
