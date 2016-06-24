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
void chip_HalfAdder(pin a, pin b, pin* sum, pin* carry);
void chip_FullAdder(pin a, pin b, pin c, pin* sum, pin* carry);
void chip_And16(pin a[], pin b[], pin out[]);
void chip_Or16(pin a[], pin b[], pin out[]);
void chip_Not16(pin in[], pin out[]);

#endif
