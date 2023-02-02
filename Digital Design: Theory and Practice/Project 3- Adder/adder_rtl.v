`timescale 1ns / 1ns
//Tanner Kleintop
//Computer Engineering 270
//September 19, 2022

module add_rtl 
	(
	input a, b, ci, //listed inputs
	output z, co  //listed outputs
	);

	assign z = ((!a & !b & ci) | (!a & b & !ci) | (a & b & ci) | (a & !b & !ci)); //algebraic equation of the s output
	assign co = ((a & b) | (a & ci) | (b & ci)); //algebraic equation for the cout output
	
endmodule