`timescale 1ns / 1ns
// library for CMPEN 270 verilog projects
// Hal Scholz, PSU-LV

module NAND2 (A, B, Z);
output Z;
input A,  B;

assign #(1,2) Z=!(A&B);
endmodule


module NAND3 (A, B, C, Z);
output Z;
input A, B, C;

 assign #(1,3) Z=!(A&B&C);
endmodule

module NAND4 (A, B, C, D, Z);
output Z;
input A, B, C, D;

 assign #(1,4) Z=!(A&B&C&D);
endmodule


module AND2 (A, B, Z);
output Z;
input A,  B;

assign #(1,2) Z=(A&B);
endmodule


module AND3 (A, B, C, Z);
output Z;
input A, B, C;

 assign #(1,3) Z=(A&B&C);
endmodule

module AND4 (A, B, C, D, Z);
output Z;
input A, B, C, D;

 assign #(1,4) Z=(A&B&C&D);
endmodule


module NOR2 (A, B, Z);
output Z;
input A, B;

 assign #(2,1) Z=!(A|B);
endmodule


module NOR3 (A, B, C, Z);
output Z;
input A, B, C;

 assign #(3,1) Z=!(A|B|C);
endmodule

module NOR4 (A, B, C, D, Z);
output Z;
input A, B, C, D;

 assign #(4,1) Z=!(A|B|C|D);
endmodule

module OR2 (A, B, Z);
output Z;
input A, B;

 assign #(2,1) Z=(A|B);
endmodule


module OR3 (A, B, C, Z);
output Z;
input A, B, C;

 assign #(3,1) Z=(A|B|C);
endmodule

module OR4 (A, B, C, D, Z);
output Z;
input A, B, C, D;

 assign #(4,1) Z=(A|B|C|D);
endmodule

module INV (A, Z);
output Z;
input A;

 assign #(1,1) Z=!A;
endmodule


module XOR (A, B, Z);
output Z;
input A, B;

 assign #(3,3) Z=(A^B);
endmodule

module XNOR (A, B, Z);
output Z;
input A, B;

 assign #(3,3) Z=(A~^B);
endmodule

module AOI21 (A1, A2, B, Z);
output Z;
input A1, A2, B;

 assign #(2,2) Z=!((A1&A2)|B);
endmodule

module AOI22 (A1, A2, B1,B2, Z);
output Z;
input A1, A2, B1,B2;

 assign #(2,2) Z=!((A1&A2)|(B1&B2));
endmodule

module AOI222 (A1, A2, B1,B2, C1,C2, Z);
output Z;
input A1, A2, B1,B2, C1,C2;

 assign #(2,2) Z=!((A1&A2)|(B1&B2)|(C1&C2));
endmodule

module OAI21 (A1, A2, B, Z);
output Z;
input A1, A2, B;

 assign #(2,2) Z=!((A1|A2)&B);
endmodule

module OAI22 (A1, A2, B1,B2, Z);
output Z;
input A1, A2, B1,B2;

 assign #(2,2) Z=!((A1|A2)&(B1|B2));
endmodule

module OAI222 (A1, A2, B1,B2, C1,C2, Z);
output Z;
input A1, A2, B1,B2, C1,C2;

 assign #(2,2) Z=!((A1|A2)&(B1|B2)&(C1|C2));
endmodule

module HI (HI);
output HI;
and h1 (HI,1);
endmodule

module LO (LO);
output LO;
and h1 (LO,0);
endmodule

module MUX21 (D0,D1,S,Z);
output Z;
input D0,D1,S;
assign Z=D1&S|D0&!S;
endmodule

module MUX41 (D0,D1,D2,D3,S0,S1,Z);
output Z;
input D0,D1,D2,D3,S0,S1;
//    pick up each state of decoded selects
assign Z=D0&!S0&!S1 | D1&!S1&S0 | D2&S1&!S0 | D3&S0&S1;
endmodule

// HNS - modified all FFs to be behavioral due to issues in UDP version 7/9/22
// Positive edge D FF 
module FFD (D, CK, Q);
output Q;
input D, CK;
reg Q;

always @(posedge CK)
begin
	if (D===1'bz)     // if input is 'Z', set output to X
		Q<= 1'bx;
	else
		Q<= #3 D;
end
endmodule

// behavioral D FF with high clear and preset
// Preset overrides clear
module FFDPC (D, CK, PRE, CLR, Q);
output Q;
input D,PRE,CLR, CK;
reg Q;

always @(posedge CK or posedge PRE or posedge CLR )
begin
	if (PRE)
		Q<= #2 1;
	else if (CLR)
		Q<= #2 0;
	else if (D===1'bz)
		Q<= #3 1'bx;
	else Q<= #3 D;
end
endmodule

// DFF with high active PRE  (Q=1 if PRE=1)
module FFDP (D, CK, PRE,  Q);
output Q;
input D,PRE, CK;
reg Q;

always @(posedge CK or posedge PRE )
begin
	if (PRE)
		Q<= #2 1;
	else if (D===1'bz)
		Q<= #3 1'bx;
	else Q<= #3 D;
end
endmodule

// DFF with high active CLR  (Q=0 if CLR=1)
module FFDC (D, CK, CLR,  Q);
output Q;
input D,CLR, CK;
reg Q;

always @(posedge CK or posedge CLR )
begin
	if (CLR)
		Q<= #2 0;
	else if (D===1'bz)
		Q<= #3 1'bx;
	else Q<= #3 D;
end
endmodule

