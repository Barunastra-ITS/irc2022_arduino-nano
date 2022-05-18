#include <FastLED_NeoPixel.h>
//#include <SoftwareSerial.h>
//
//SoftwareSerial LED(0, 1);

char str_buf[6];
int ret_val;
uint8_t led_indicator;

//#include <cmath>
#define HEIGHT 16
#define WIDTH 16
#define PART_W 8
#define PART_H 8
// Which pin on the Arduino is connected to the LEDs?
#define DATA_PIN 8

// How many LEDs are attached to the Arduino?
#define NUM_LEDS 256

// LED brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 10 // 80% kecerahan

// Amount of time for each half-blink, in milliseconds
#define BLINK_TIME 10000

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
//FastLED_NeoPixel<NUM_LEDS, DATA_PIN, NEO_GRB> strip;      // <- FastLED NeoPixel version


CRGB leds[NUM_LEDS];

CRGB* ledaddress(int h, int w)
{
  CRGB* tleds = leds;
  if (h >= PART_H) {
    tleds = tleds + PART_H * PART_W;
    h = h % PART_H;
  }
  if (w >= PART_W) {
    tleds = tleds + 2 * PART_H * PART_W;
    w = w % PART_W;
  }
  if (h % 2 == 0)
    return tleds + ((h + 1) * PART_W - w - 1);
  else
    return tleds + (h * PART_W + w);
}

void clearLED()
{
  for (unsigned int i = 0; i < NUM_LEDS ; i++)
  {
    leds[i] = CRGB::Black;
  }
}
int i, j, clridx, bidx;
CRGB clrs[] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::White, CRGB::Yellow, CRGB::Orange};
void setup() {

  //  LED.begin(9600);
  Serial.begin(9600);

  //  strip.begin();  // initialize strip (required!)
  //  strip.setBrightness(BRIGHTNESS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // GRB ordering is assumed
  FastLED.setBrightness(10);
  i = j = 0;
  clridx = 0;
  bidx = 0;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      //      *ledaddress(i, j) = clrs[clridx];
      leds[i * WIDTH + j] = CRGB::Red;
    }
    //    FastLED.setBrightness((int)cos((float)bidx/acos(-1)/2)*10);
    bidx++;
    FastLED.show();
    //    delay(BLINK_TIME / 10);
  }
  clridx = (clridx + 1) % 4;
  //  clearLED();
}

void loop() {

  //  for (i = 0; i < HEIGHT; i++) {
  //    for (j = 0; j < WIDTH; j++) {
  //      //      *ledaddress(i, j) = clrs[clridx];
  //      leds[i * WIDTH + j] = CRGB::Green;
  //    }
  //    //    FastLED.setBrightness((int)cos((float)bidx/acos(-1)/2)*10);
  //    bidx++;
  //    FastLED.show();
  //    //    delay(BLINK_TIME / 10);
  //  }
  //  clridx = (clridx + 1) % 4;
  //  //  clearLED();

  if (Serial.available())
  {
    ret_val = Serial.readBytes(str_buf, 6);
    if (ret_val > 0)
    {
      for (int i = 0; i < 6; i++) {
        Serial.print(str_buf[i]);
        if (str_buf[i] == 'i' and str_buf[i + 1] == 't' and str_buf[i + 2] == 's') {
          memcpy(&led_indicator, str_buf + i + 3, 1);
          break;
          //        led_indicator = str_buf[3];
        }
      }

    }
    if (led_indicator == 10) {
      for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
          //      *ledaddress(i, j) = clrs[clridx];
          leds[i * WIDTH + j] = CRGB::Green;
        }
        //    FastLED.setBrightness((int)cos((float)bidx/acos(-1)/2)*10);
        bidx++;
        FastLED.show();
        //    delay(BLINK_TIME / 10);
      }
      clridx = (clridx + 1) % 4;
      //  clearLED();
    }

    else if (led_indicator == 20) {
      for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
          //      *ledaddress(i, j) = clrs[clridx];
          leds[i * WIDTH + j] = CRGB::Yellow;
        }
        //    FastLED.setBrightness((int)cos((float)bidx/acos(-1)/2)*10);
        bidx++;
        FastLED.show();
        //    delay(BLINK_TIME / 10);
      }
      clridx = (clridx + 1) % 4;
      //  clearLED();
    }

    else if (led_indicator == 30) {
      for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
          //      *ledaddress(i, j) = clrs[clridx];
          leds[i * WIDTH + j] = CRGB::Red;
        }
        //    FastLED.setBrightness((int)cos((float)bidx/acos(-1)/2)*10);
        bidx++;
        FastLED.show();
        //    delay(BLINK_TIME / 10);
      }
      clridx = (clridx + 1) % 4;
      //  clearLED();
    }

    else if (led_indicator == 40) {
      for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
          //      *ledaddress(i, j) = clrs[clridx];
          leds[i * WIDTH + j] = CRGB::Blue;
        }
        //    FastLED.setBrightness((int)cos((float)bidx/acos(-1)/2)*10);
        bidx++;
        FastLED.show();
        //    delay(BLINK_TIME / 10);
      }
      clridx = (clridx + 1) % 4;
      //  clearLED();
    }
  }
  delay(10);
  Serial.println(led_indicator);
}
