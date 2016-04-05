void multiStrobe() {

  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255,0,0));
  }
  pixels.show();

  delay(10);

  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0,0,255));
  }
  pixels.show();

  delay(40);

  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0,255,0));
  }
  pixels.show();

  delay(10);
}

