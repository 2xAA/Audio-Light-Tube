# Audio-Light-Tube
Audio reactive lights using Teensy 3.2 with 4 audio reactive modes and 2 strobe effects

## Software Requirements

* [Teensyduino](https://www.pjrc.com/teensy/td_download.html)
* [Adafruit's NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel)

## Hardware Requirements

* Addressable LED Strip (WS2812 or WS2812B) (like [this one](http://www.banggood.com/5M-WS2812B-5050-RGB-Waterproof-IP67-150-LED-Strip-Light-Dream-Color-Changing-Individual-Addressable-DC-5V-p-998626.html))
* [Teensy 3.2](https://www.pjrc.com/store/teensy32.html)
* 1x Push Button
* 1x 2.2K Resistor
* 2x 10K Resistor (one of these is for the pushbutton)
* 2x 47K Resistor
* 2x 10µF Electrolytic Capacitor
* Wire
* Veroboard (larger piece for the audio circuit, smaller piece for the pushbutton)
* 5V (>2)A power supply (your computer will not be sufficient to power the LEDs at full power)
* Optional: Translucent plastic tube (this was for my own design, however paper works well enough)

## Instructions

1. Flash the Teensy with the code in this repo
2. Build the [audio filter circuit](http://www.pjrc.com/teensy/gui/img/adccircuit.png) as found in the Teensy [Audio System Design Tool](http://www.pjrc.com/teensy/gui/?info=AudioInputAnalog) on the veroboard
3. Build a simple pushbutton circuit (example [here](https://www.arduino.cc/en/Tutorial/Button))
4. Plug everything together (pushbutton to pin 2, LED strip to pin 6) and you should be set!

## Videos

These are some example videos of what the tube looks like when built

* [VU Meter](https://www.instagram.com/p/BDy3RBps9bD/)
* [VU Meter and FFT](https://www.instagram.com/p/BBLUfYAs9ZM/)
* [Early VU Meter](https://www.instagram.com/p/BBDU6mtM9UL/)
* [RMS, VU Meter, FFT](https://www.instagram.com/p/BBDl6d-s9XM/)
* [Tri Strobe](https://www.instagram.com/p/BBERNn-M9RZ/)
* [VU Meter](https://www.instagram.com/p/BBFpUmjs9Re/)
