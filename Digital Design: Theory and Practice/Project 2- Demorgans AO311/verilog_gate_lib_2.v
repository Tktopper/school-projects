`timescale 1ns / 1ns
// Dr. Hal Scholz, PSU Lehigh Valley
// ao21 DeMorgans 

// this library is for the Demorgans assignment only. You may only use the cells in this file. DO NOT MODIFY THE LIBRARY!!!!

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
