#include <iostream>

#include "Vsimple_in_n_out.h"
#include "verilated.h"

int main(int argc, char *argv[])
{
	Verilated::commandArgs(argc, argv);
	Vsimple_in_n_out *top = new Vsimple_in_n_out;

	for(int in_1 = 0 ; in_1 < 2; in_1++)
		for(int in_2 = 0 ; in_2 < 2; in_2++)
			for(int in_3 = 0 ; in_3 < 2; in_3++) {

				top->in_1 = in_1;
				top->in_2 = in_2;
				top->in_3 = in_3;

				top->eval();
				
				std::cout << int(top->in_1) << " " << int(top->in_2) << " " << int(top->in_3)
					  << "|   " 
					  << int (top->out_1) << "   " << int(top->out_2) << std::endl;

				if (Verilated::gotFinish())
					exit(0);
			}

	delete top;

	exit(0);
}

