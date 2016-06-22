#include "chips.h"

/*
  Only BUILTIN_CHIP can use high-level C constructs like if, for, etc... 
  
 */

void chip_Nand(pin a, pin b, pin *out) /* BUILTIN_CHIP */
{
	if ( ( a == 1 ) && ( b == 1 ) )
		*out = 0;
	else
		*out = 1;
	return;
}

void chip_Not(pin in, pin *out)
{
	chip_Nand( in, in, out );
}

void chip_And(pin a, pin b, pin* out)
{
	pin out_;
	
	chip_Nand( a, b, &out_ );
	chip_Not( out_, out );

	return;
}

void chip_Or(pin a, pin b, pin* out)
{
	pin not_a;
	pin not_b;

	chip_Not( a, &not_a );
	chip_Not( b, &not_b );
	
	pin not_ab;
	chip_And ( not_a, not_b, &not_ab );

	chip_Not( not_ab, out );

	return;
}

void chip_Xor(pin a, pin b, pin* out)
{
	pin not_a;
	pin not_b;
	
	chip_Not( a, &not_a );
	chip_Not( b, &not_b );
	
	pin a_And_Not_b;
	chip_And( a, not_b, &a_And_Not_b );

	pin not_a_And_b;
	chip_And( not_a, b, &not_a_And_b );

	chip_Or( a_And_Not_b, not_a_And_b, out );

	return;
}

void chip_Mux(pin a, pin b, pin sel, pin* out)
{
	pin not_sel;

	chip_Not( sel, &not_sel );
	
	pin sel_a;
	chip_And( a, not_sel, &sel_a );

	pin sel_b;
	chip_And( b, sel, &sel_b );

	chip_Or( sel_a, sel_b, out);

	return;
}
