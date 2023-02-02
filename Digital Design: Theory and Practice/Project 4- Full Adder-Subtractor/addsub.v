`timescale 1ns / 1ns
//Tanner Kleintop
//Computer Engineering 270
//September 19, 2022

module addsub (sub, a, b, co, ci, z, oflow);
		//declaring each input, each input signed is a 2's complement number
	input sub;
	input signed [3:0] a;
	input signed [3:0] b;
	input ci;

		//declaring each output, each input signed is a 2's complement number
	output signed [3:0] z;
	output co;
	output oflow;

		//declaring each variable as a wire 
	wire b0, b1, b2, b3, co1 ,co2, co3;

		//each xor gate declared for each bit of b in the 4 bit adder
	XOR gt1 (.A(b[0]), .B(sub), .Z(b0));
	XOR gt2 (.A(b[1]), .B(sub), .Z(b1));
	XOR gt3 (.A(b[2]), .B(sub), .Z(b2));
	XOR gt4 (.A(b[3]), .B(sub), .Z(b3));

		//similar to the layout of the rtl file
	add g1 (.a(a[0]), .b(b0), .ci(ci), .z(z[0]), .co(co1));
	add g2 (.a(a[1]), .b(b1), .ci(co1), .z(z[1]), .co(co2));
	add g3 (.a(a[2]), .b(b2), .ci(co2), .z(z[2]), .co(co3));
	add g4 (.a(a[3]), .b(b3), .ci(co3), .z(z[3]), .co(co));

	XOR gt5 (.A(co), .B(co3), .Z(oflow));

endmodule