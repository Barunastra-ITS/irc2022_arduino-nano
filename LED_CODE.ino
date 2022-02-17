#include <FastLED_NeoPixel.h>

// Which pin on the Arduino is connected to the LEDs?
#define DATA_PIN 8

// How many LEDs are attached to the Arduino?
#define NUM_LEDS 128

// LED brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 20 // 80% kecerahan

// Amount of time for each half-blink, in milliseconds
#define BLINK_TIME 10

/* Declare the NeoPixel strip object:
*     * Argument 1 = Number of LEDs in the LED strip
*     * Argument 2 = Arduino pin number
*     * Argument 3 = LED strip color order

  The FastLED_NeoPixel version uses template arguments instead of function
  arguments. Note the use of '<>' brackets!

  You can switch between libraries by commenting out one of these two objects.
  In this example they should behave identically.
*/
// Adafruit_NeoPixel strip(NUM_LEDS, DATA_PIN, NEO_GRB);  // <- Adafruit NeoPixel version
FastLED_NeoPixel<NUM_LEDS, DATA_PIN, NEO_GRB> strip;      // <- FastLED NeoPixel version

int i;

void setup() {
  strip.begin();  // initialize strip (required!)
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  for (i = 0; i <= 128 ; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));  // RED
    strip.show();
  }
  delay(BLINK_TIME);
  for (i = 0; i <= 128 ; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));  // GREEN
    strip.show();
  }
  delay(BLINK_TIME);
  for (i = 0; i <= 128 ; i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255));  // WHITE
    strip.show();
  }
  delay(BLINK_TIME);
  for (i = 0; i <= 128 ; i++) {
    strip.setPixelColor(i, strip.Color(255, 140, 0));  // ORANGE
    strip.show();
  }
  delay(BLINK_TIME);
}
