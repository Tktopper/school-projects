`timescale 1ns / 1ns

// Tanner Kleintop
// Computer Engineering 270
// September 12, 2022

// hns12 08212017 - generate rtl model using boolean operators
//
module ao311_rtl (
  input a,b,c,d,e, //listed inputs
  output z //listed outputs
  );
  assign z = (a & b & c) | d | e ; //equation of my ao311 circuit
endmodule
