`timescale 1ns / 1ns
//Tanner Kleintop
//Computer Engineering 270
//September 19, 2022

module add (a,b,ci,z,co); //declares the module as my adder.v file
	input a,b,ci; //listed inputs
	output z,co; //listed outputs

//all gates necessary for the "z" output
INV invgt1s (.A(a), .Z(inva));
INV invgt2s (.A(b), .Z(invb)); 
INV invgt3s (.A(ci), .Z(invci));
AND2 ag1s (.A(inva), .B(invb), .Z(opts1));
AND2 ag2s (.A(inva), .B(b), .Z(opts2));
AND2 ag3s (.A(a), .B(b), .Z(opts3));
AND2 ag4s (.A(a), .B(invb), .Z(opts4));
AND2 ag5s (.A(opts1), .B(ci), .Z(opts5));
AND2 ag6s (.A(opts2), .B(invci), .Z(opts6));
AND2 ag7s (.A(opts3), .B(ci), .Z(opts7));
AND2 ag8s (.A(opts4), .B(invci), .Z(opts8));
OR2 og1s (.A(opts5), .B(opts6), .Z(opts9));
OR2 og2s (.A(opts7), .B(opts8), .Z(opts10));
OR2 og3s (.A(opts9), .B(opts10), .Z(z));

//Gate level setup of the "co" output
AND2 agc1 (.A(b), .B(ci), .Z(optc1));
AND2 agc2 (.A(a), .B(ci), .Z(optc2));
AND2 agc3 (.A(a), .B(b), .Z(optc3));
OR2 ogc1 (.A(optc1), .B(optc3), .Z(optc4));
OR2 ogc2 (.A(optc4), .B(optc2), .Z(co));

endmodule