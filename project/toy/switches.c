#include <msp430.h>
#include "switches.h"

void switch_init() {
  P2REN |= SWITCHES;  // Enable resistors for switches
  P2IE |= SWITCHES;   // Enable interrupts from switches
  P2OUT |= SWITCHES;  // Pull-ups for switches
  P2DIR &= ~SWITCHES; // Set switches' bits for input
  switch_update_interrupt_sense();
}

char switch_update_interrupt_sense() {
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);  // if switch up, sense down
  P2IES &= (p2val | ~SWITCHES); // if switch down, sense up
  return p2val;
}