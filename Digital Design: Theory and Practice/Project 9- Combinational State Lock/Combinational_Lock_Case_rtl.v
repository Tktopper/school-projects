`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
// October 17, 2022
// The purpose of this collection of code is to make a comination lock that will unlock with the correct expression

module combination_case_rtl (CLK,CLR,X,UNLK,HINT); // Lock case rtl module

  input CLK,CLR,X; //inputs
  output UNLK,HINT; //outputs
  
  reg [2:0] state,nstate; // registers current state state and neXt state state*
  
  // states A through H as 3 bit parameters
  parameter [2:0] A = 3'b000, B = 3'b001, C = 3'b010, D = 3'b011, E = 3'b100, F = 3'b101, G = 3'b110, H = 3'b111;
  
  always @ (X or state)
    begin
	  case (state) // case statement for state of the combinational lock
	    A: nstate <= X? A: B;
		B: nstate <= X? C: B;
		C: nstate <= X? D: B;
		D: nstate <= X? A: E;
		E: nstate <= X? F: B;
		F: nstate <= X? G: B;
		G: nstate <= X? H: E;
		H: nstate <= X? A: B;
		default: nstate <= B;
	  endcase
    end
  
  always @ (posedge CLK or posedge CLR) //always block that will change the state of the lock
    begin
      if (CLR) // if the clear is 1, then the lock will be reset
	    state <= 0;
	  else
	    state <= nstate; // if the clear is 0, then the lock will be set to the next state
	end
	
  assign UNLK = state[2] & state[1] & state[0]; // unlock is the 3 bits of current state input ANDed together
	
  assign S_HINT = state[1] & !state[0] | state[2] & !state[0] | !state[1] & state[0]; // S_HINT is an output based on minterms of current state input
  
  assign HINT = !(X ^ S_HINT); // HINT is X XNOR'd with S_HINT
  
endmodule