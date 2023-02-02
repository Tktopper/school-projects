`timescale 1ns / 1ns
//Tanner Kleintop
//Computer Engineering 270
//September 21, 2022

module addsub_rtl (sub, a, b, co, ci, z, oflow);

		//declared input, each input being signed is signing it as a 2's complement number
	input sub;
	input ci;
	input signed [3:0] a;
	input signed [3:0] b;
	
	//ouputs declared, each input that is signed is signed as a 2's complement number
	output signed [3:0] z;
	output co;
	output oflow;

	//declaring each variable as a wire so it "holds" its memory
	wire b0, b1, b2, b3, co1 ,co2, co3;
	
	//assigning each bit of b to a variable that it is xored with
	assign b0 = b[0]^sub;
	assign b1 = b[1]^sub;
	assign b2 = b[2]^sub;
	assign b3 = b[3]^sub;
	assign oflow = co^co3;
	
	//calls the previous addrtl to read for the 4 bit adder
	add_rtl g1 (.a(a[0]), .b(b0), .ci(ci), .z(z[0]), .co(co1));
	add_rtl g2 (.a(a[1]), .b(b1), .ci(co1), .z(z[1]), .co(co2));
	add_rtl g3 (.a(a[2]), .b(b2), .ci(co2), .z(z[2]), .co(co3));
	add_rtl g4 (.a(a[3]), .b(b3), .ci(co3), .z(z[3]), .co(co));

endmodule