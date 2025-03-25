#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"

void state_advance() {
  static char state = 0;
  switch (state) {
    case 0:
      buzzer_set_period(1000);  // Set buzzer frequency
      led_update(1);            // Turn on green LED
      state = 1;
      break;
    case 1:
      buzzer_set_period(2000);  // Set buzzer frequency
      led_update(2);            // Blink green LED
      state = 2;
      break;
    case 2:
      buzzer_set_period(3000);  // Set buzzer frequency
      led_update(3);            // Turn on red LED
      state = 3;
      break;
    case 3:
      buzzer_set_period(4000);  // Set buzzer frequency
      led_update(4);            // Blink red LED
      state = 0;
      break;
  }
}