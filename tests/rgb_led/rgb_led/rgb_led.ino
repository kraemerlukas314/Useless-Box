// https://funduino.de/nr-17-ws2812-neopixel

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 9
#define NUMPIXELS 1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // Initialisierung der NeoPixel
}

void loop() {
  pixels.setPixelColor(1, pixels.Color(0, 255, 0));
  pixels.show(); // Durchführen der Pixel-Ansteuerung
  delay(5000);

}
