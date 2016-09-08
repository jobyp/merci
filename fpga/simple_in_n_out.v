module simple_in_n_out ( 
			 // Inputs
			 in_1,
			 in_2,
			 in_3,
			 
			 // Outputs
			 out_1,
			 out_2,
			 out_3,
			 out_4);

   input in_1;
   input in_2;
   input in_3;
   
   output out_1;
   output out_2;
   output out_3;
   output out_4;
   

   assign out_1 = in_1 & in_2 & in_3;
   assign out_2 = in_1 | in_2 | in_3;

   assign out_3 = 1'b1;
   assign out_4 = 1'b0;
   
endmodule
   
// Local Variables:
// mode: verilog
// End:
