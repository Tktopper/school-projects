`timescale 1ns / 1ns
//* Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
//The purpose of this collection of code is to make a comination lock that will unlock with the correct expression

module combination_boolean_rtl (
    CLK,
    CLR,
    X,
    UNLK,
    HINT
);

  input CLK, CLR, X;  //inputs
  output UNLK, HINT;  //outputs

  reg state1, state2, state3;

  assign nstate1 = !X & !state1 & state2 & state3 | X & state1 & !state2 | state1 & state2 & !state3; // next state for state1

  assign nstate2 = X & !state2 & state3 | X & state2 & !state3;  // next state for state2

  assign nstate3 = !X & !state2 | X & state1 & !state3 | !X & state1 & state3 | !state1 & state2 & !state3; // next state for state3

  always @ (posedge CLK or posedge CLR) //always block that will change the state of the lock
    begin
    if (CLR) begin  // if the clear is 1, then the lock will be reset
      state1 <= 0;
      state2 <= 0;
      state3 <= 0;
    end else begin  // if the clear is 0, then the lock will be set to the next state
      state1 <= nstate1;
      state2 <= nstate2;
      state3 <= nstate3;
    end
  end

  assign UNLK   = state1 & state2 & state3;  // output UNLK 

  assign S_HINT = state2 & !state3 | state1 & !state3 | !state2 & state3;  // output S_HINT 

  assign HINT   = !(X ^ S_HINT);  // HINT is X XNOR S_HINT

endmodule
