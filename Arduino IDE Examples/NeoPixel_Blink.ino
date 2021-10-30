/* Small modification of Adafruit NeoPixel example
 * Author Dejan Petrovic
 * 10/30/2021
 * v1.0
*/
#include <Adafruit_NeoPixel.h>
#define PIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
  colorWipe(strip.Color(0, 255, 0), 1000); // Green
  //colorWipe(strip.Color(255, 0, 0), 1000); // Green
  //colorWipe(strip.Color(0, 0, 255), 1000); // Green
  colorWipe(strip.Color(0, 0, 0), 1000); // white
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
