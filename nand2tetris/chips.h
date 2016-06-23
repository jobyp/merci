#ifndef __CHIPS_H
#define __CHIPS_H

typedef unsigned char pin;

void chip_Nand(pin a, pin b, pin *out); /* BUILTIN_CHIP */
void chip_Not(pin in, pin *out);
void chip_And(pin a, pin b, pin* out);
void chip_Or(pin a, pin b, pin* out);
void chip_Xor(pin a, pin b, pin* out);
void chip_Mux(pin a, pin b, pin sel, pin* out);
void chip_DMux(pin in, pin sel, pin* a, pin* b);

#endif
