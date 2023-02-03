`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
// November 8, 2022
//pipo shift register with the ability to load in and out of the register 
module piposr_rtl (Din,SI,LDin,LDout,CK,Dout,SO);

  input [3:0] Din; //input data
  input SI,LDin,LDout,CK; //serial in, load in, load out
  
  output reg [3:0] Dout; //output data
  output SO; //serial out
  
  reg [3:0] Q; //register
  
  assign SO = Q[0]; // serial out is bit 0 of the SR data
  
  always @ (posedge CK)
    begin
	  if (LDin) // select input 1 for mux being Din
	    Q <= Din;
	  else
	    begin
		  Q[3] <= SI; // bit 3 of SR data becomes serial in
	      Q[2:0] <= Q >> 1; // rest of bits are shifted to the right
       end
	  if (LDout)
	    Dout <= Q; // select input 1 of mux being Q
	  else
	    Dout <= Dout; // keep values of Dout
	end
  
endmodule