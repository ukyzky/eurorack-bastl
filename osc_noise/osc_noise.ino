/*
 * LITTLE NERD
 * eurorack module by Bastl Instruments
 * www.bastl-instruments.com
 * Vaclav Pelousek
 * licensed under cc-by-sa
 *
 *TODO
 *finish visual testing
 *do audioble testing
 *implement production code = testing + eeprom reset
 *implement midi ?
 *
 */

#ifdef EXTERNAL_IDE

#include <Arduino.h>
#define PIN B,4


int main(void) {

  init();
  setup();

  while(true) {
    loop();
  }
}

#endif

#include <portManipulations.h>
#include "multiChannelOscillator.h"

extern MultiChannelOscillator oscil;

uint16_t frequencies[6] = {153,185,267,327,465,1023};
uint8_t pinIndices[6]  = {2,3,4,5,6,7};



void setup() {


	TIMSK0 = 0; // disable millis timer to not disturb our interrupt
	TIMSK2 = 0;

	Serial.begin(115200);
	Serial.println("start");


	oscil.init(frequencies,pinIndices);
	oscil.printBuffer();
	oscil.start();



}



void loop() {


	oscil.fillBuffer();

	//Serial.println(oscil.fillCount);





}




