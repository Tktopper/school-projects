`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
/* cell module setup of a ao311 circuit */
/* function is z=(a*b)*c&(d&e) */
module ao311 (
  input a,b,c,d,e,   //inputs of the gates     
  output z              //output of the gates
  );
  //for my specific circuit, i had 2 AND gates and 2 OR gates each with 2 inputs leading to an out z
  AND2 ag1 (.A(a), .B(b), .Z(out1)); //AND gate 1 that connects inputs a and b together, outputting out1
  AND2 ag2 (.A(c), .B(out1), .Z(out2)); //AND gate 2 that inputs c and out1 from AND gate 1
  OR2 og1 (.A(d), .B(e), .Z(out3)); //OR gate 1 that inputs d and e, outputting output 3
  OR2 og2 (.A(out2),.B(out3),.Z(z)); //OR gate 2 that connects outputs 1 and 3, connecting to z
endmodule
