`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//September 26, 2022

module three_to_eight (A, B, C, G1, G2AN, G3BN, Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7); //given module name with the respective inputs and outputs necessary for the function of the gate level 3 to 8 decoder
	input A,B,C,G1,G2AN,G3BN; //inputs
	output Y0,Y1,Y2,Y3,Y4,Y5,Y6,Y7; //outputs

//Below is the gate level model of the 3 to 8 decoder using the listed inputs and outputs above.

	INV i1 (.A(A), .Z(iA));
	INV i2 (.A(B), .Z(iB));
	INV i3 (.A(C), .Z(iC));
	INV i4 (.A(G2AN), .Z(iG2N));
	INV i5 (.A(G3BN), .Z(iG3N));
	
	AND3 ag1 (.A(G1), .B(iG2N), .C(iG3N), .Z(EO));

	NAND4 na31 (.A(A), .B(B), .C(C), .D(EO), .Z(Y7));
	NAND4 na32 (.A(A), .B(B), .C(iC), .D(EO), .Z(Y6));
	NAND4 na33 (.A(A), .B(iB), .C(C), .D(EO), .Z(Y5));
	NAND4 na34 (.A(A), .B(iB), .C(iC), .D(EO), .Z(Y4));
	NAND4 na35 (.A(iA), .B(B), .C(C), .D(EO), .Z(Y3));
	NAND4 na36 (.A(iA), .B(B), .C(iC), .D(EO), .Z(Y2));
	NAND4 na37 (.A(iA), .B(iB), .C(C), .D(EO), .Z(Y1));
	NAND4 na38 (.A(iA), .B(iB), .C(iC), .D(EO), .Z(Y0));

	

endmodule
