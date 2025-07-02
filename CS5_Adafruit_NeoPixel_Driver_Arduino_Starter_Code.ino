#include <seesaw_neopixel.h>
#include "lights_out.h"
#define PIN 15
#define NUM_LEDS 10
#define RANDOM_MOVES  10

seesaw_NeoPixel strip = seesaw_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);
int board[NUM_LEDS];
int moves = 0;

void setup() {
  Serial.begin(9600);
  
  while (!Serial) {
    Serial.println("Waiting until serial port is opened.");
    delay(10);
  }

  randomSeed(micros());
  
  if(!strip.begin(0x60)){
    Serial.println("seesaw not found!");
    while(1) delay(10);
  }
  
  Serial.println("Seesaw NeoPixel Started!");
  
  strip.setBrightness(25);
  set_board(board, NUM_LEDS); // Initialize all pixels to 'off'
  strip.show();

  randomize_board(board, NUM_LEDS, RANDOM_MOVES);
  show_board(board, NUM_LEDS, strip);

  Serial.println("1D Lights Out");
  Serial.println("Enter index [0–" + String(NUM_LEDS - 1) + "] to flip it and its neighbors.");

  show_board(board, NUM_LEDS, strip);
}

void loop() {
  if (Serial.available() > 0) {
    int idx = Serial.parseInt();
    while (Serial.available()) {
      Serial.read(); // discard any leftover values
    }

    // Your code here!
  }
}
