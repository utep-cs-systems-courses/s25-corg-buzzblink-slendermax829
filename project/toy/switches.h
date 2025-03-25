#ifndef switches_included
#define switches_included

#define SW1 BIT0  // Switch 1 is P2.0
#define SW2 BIT1  // Switch 2 is P2.1
#define SW3 BIT2  // Switch 3 is P2.2
#define SW4 BIT3  // Switch 4 is P2.3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)  // All switches

void switch_init();
char switch_update_interrupt_sense();
void switch_interrupt_handler();

#endif // included