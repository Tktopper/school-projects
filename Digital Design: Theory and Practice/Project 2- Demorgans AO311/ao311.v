`timescale 1ns / 1ns
// Tanner Kleintop
// ao311 DeMorgans 
// September 12, 2022

/* cell level model of ao311 */
module ao311 (a,b,c,d,e,z); //listed circuit name
  input a,b,c,d,e; //listed inputs
  output z; //listed outputs
NAND3 n1 (.A(a), .B(b), .C(c), .Z(out1)); //NAND gate with inputs a b and c all outputting out1
NAND2 n2 (.A(d), .B(d), .Z(out2)); //NAND gate 2 with d inputting as inputs 1 and 2, outputting out2
NAND2 n3 (.A(e), .B(e), .Z(out3)); //NAND gate 3 with e inputting as inputs 1 and 2, outputting out3
NAND3 n4 (.A(out1), .B(out2), .C(out3), .Z(z)); //NAND gate 4 inputting the outputs of n1 and n2, outputting to z
endmodule
