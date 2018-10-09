#include <SPI.h>
#include "PWiFi.h"
#include "blink.h"
#include "Log.h"
#include "FastLED.h"
#include "FastLED_RGBW.h"
#include "hsi2rgbw.h"
#include "Color/Color.h"

#define NUM_LEDS 30
#define DATA_PIN 6

// FastLED with RGBW
CRGBW leds[NUM_LEDS];
CRGB *ledsRGB = (CRGB *) &leds[0];

byte deviceId[6];
short int loopCount = 0;

void setup() {

  Serial.begin(9600);
  delay(1000);

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(ledsRGB, getRGBWsize(NUM_LEDS));
  //FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  //  if (WiFi.status() == WL_NO_SHIELD) {
  //    blink(2);
  //  }
  //  Log log;
  //
  //  log.writeln("test");
  //  unsigned short int value = 255;
  //  //LedModule(1, value);
  //
  //  PWiFi::connect();
  //  PWiFi::printCurrentNet();
}

void loop() {

  if (loopCount > NUM_LEDS) {
    loopCount = 1;
  }
  else {
    loopCount++;
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    float hue = i * 360 / NUM_LEDS;
    int rgbw[4];
    hsi2rgbw(hue, 1.0f, 1.0f, rgbw);
    int led = (i + loopCount) % NUM_LEDS;
    leds[led] = CRGBW(rgbw[0], rgbw[1], rgbw[2], 255);
  }
  FastLED.show();
  //delay(1);

}
