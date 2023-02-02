`timescale 1ns / 1ns
// Dr. Hal Scholz, PSU Lehigh Valley
// CMPEN 270 1st assignment
// modified 9/7/2016 - changed delays on AND2/OR2 to include output inversion

// DO NOT EDIT THIS FILE
module AND2 (
   input A,
   input B,
   output Z
);

assign #(3,2) Z=(A&B);
endmodule


module OR2 (
input A, B,
output Z
);

 assign #(2,3) Z=(A|B);
endmodule


module INV (
input A,
output Z
);

 assign #(1,1) Z=~A;
endmodule

