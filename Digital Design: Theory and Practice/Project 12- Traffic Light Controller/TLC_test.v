//Tanner Kleintop
//CMPEN 270
`timescale 1ns / 1ns
module test; //module name

reg clk, clr; //input signals
reg MD, SD; //inputs

wire MG, MY, MR, MA, SR, SY, SG; //output wires

always begin //always block
	#50 clk = ~clk; //toggle clk
end

initial begin //initial block
//initializations for test cases
	clk = 0;
	clr = 1;
	MD = 0;
	SD = 0;
#20 clr = 0;

//test cases
#100 MD = 1;
#100 SD = 1;

#100 MD = 0;
#100 SD = 0;

#100 MD = 1;
#100 SD = 1;

#100 MD = 0;
#100 SD = 0;

#100 MD = 1;
#100 SD = 1;

#100 MD = 0;
#100 SD = 0;

#100 MD = 1;
#100 SD = 1;

#100 MD = 0;
#100 SD = 0;

#100 MD = 1;
#100 SD = 1;

#100 MD = 0;
#100 SD = 0;

#100 MD = 1;
#100 SD = 1;

#100 MD = 0;
#100 SD = 0;



$finish;
end //initial block


initial begin //initial block
	$dumpfile("TLC_test.vcd"); //create vcd file
	$dumpvars(0, test); //dump all variables
end

//instantiate TLC_rtl
TLC_rtl tlc1 ( .CLK(clk), .MD(MD), .SD(SD), .clr(clr), .MR(MR), .MY(MY), .MG(MG), .MA(MA), .SR(SR), .SY(SY), .SG(SG));


endmodule