#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachine.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(void) {
  if (P2IFG & SWITCHES) {  // did a button cause this interrupt?
    P2IFG &= ~SWITCHES;    // clear pending sw interrupts
    switch_interrupt_handler();  // single handler for all switches
  }
}

void switch_interrupt_handler() {
  char p2val = switch_update_interrupt_sense();
  if (!(p2val & SW1)) {  // Switch 1
    state_advance();
  } else if (!(p2val & SW2)) {  // Switch 2
    state_advance();
  } else if (!(p2val & SW3)) {  // Switch 3
    state_advance();
  } else if (!(p2val & SW4)) {  // Switch 4
    state_advance();
  }
}