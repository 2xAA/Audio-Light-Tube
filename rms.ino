void rms() {
  float rmsBrightness = mapfloat(rmsValue/2.5, 0.0, 1.0, 0.0, 255.0);
  
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(rmsBrightness,rmsBrightness,rmsBrightness));
  }
  pixels.show();
}

