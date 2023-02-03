`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
module RS_LATCH (R, S, Q, Qn);
input R, S; //inputs
output Q, Qn; //outputs

assign #10 Q = !(S & Qn); //assign state 
assign #10 Qn = !(R & Q); //assign statement for Qn

endmodule