void fftBlink() {
  if (fft1.available()) {
    // each time new FFT data is available
    // print it all to the Arduino Serial Monitor
    float n;
    int i;
    
    for (i=0; i < 60; i+=1) {
      n = fft1.read(map(i, 0, 60, 0, NUMPIXELS));

      float brightness = mapfloat(n, 0, 1.0, 0, MAXBRIGHTNESS);
      brightness = brightness/100.0;
      float saturation = 1;
      int hue = map(map(i, 0, 60, 0, NUMPIXELS), 0, 60, 0, 360); // Number between 0 and 360
      
      long color = HSBtoRGB(hue, saturation, brightness); 
  
      // Get the red, blue and green parts from generated color
      int red = color >> 16 & 255;
      int green = color >> 8 & 255;
      int blue = color & 255;
      
      if (n >= 0.01) {
        Serial.print(n);
        Serial.print(" ");
      } else {
        Serial.print("  -  "); // don't print "0.00"
      }
      if (n >= 0.01) {
        pixels.setPixelColor(map(i, 0, 60, 0, NUMPIXELS), pixels.Color(red, green, blue));
      } else {
        pixels.setPixelColor(map(i, 0, 60, 0, NUMPIXELS), pixels.Color(0, 0, 0));
      }
    }
    pixels.show();
    Serial.println();
  }
}

