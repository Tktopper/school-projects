`timescale 1ns / 1ns

module AND2 (A, B, Z);
output Z;
input A,  B;

assign #(1,2) Z=(A&B);
endmodule


module OR2 (A, B, Z);
output Z;
input A, B;

 assign #(2,1) Z=(A|B);
endmodule


module INV (A, Z);
output Z;
input A;

 assign #(1,1) Z=~A;
endmodule

