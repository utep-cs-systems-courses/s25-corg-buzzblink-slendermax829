#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init() {
  P1DIR |= LEDS;  // Set LED pins as outputs
  P1OUT &= ~LEDS; // Initialize LEDs to off
}

void led_update(int state) {
  switch (state) {
    case 1: // Switch 1: Turn on green LED
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_RED;
      break;
    case 2: // Switch 2: Blink green LED
      P1OUT ^= LED_GREEN;
      P1OUT &= ~LED_RED;
      break;
    case 3: // Switch 3: Turn on red LED
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      break;
    case 4: // Switch 4: Blink red LED
      P1OUT ^= LED_RED;
      P1OUT &= ~LED_GREEN;
      break;
  }
}