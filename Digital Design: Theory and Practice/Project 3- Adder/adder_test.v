`timescale 1ns / 1ns
//Tanner Kleintop
//Computer Engineering 270
//September 19, 2022
//The purpose of this set of code is to make an adder with the truth table provided from the slides
module test;

reg [2:0] cnt=0; //3 bit count starting at 0

	assign a = cnt[2]; //assigned a at a count of 2
	assign b = cnt[1]; //assigned b at a count of 1
	assign ci = cnt[0]; //assigned cin at a count of 0
	
	always begin
	# 100 cnt=cnt+1; //begins the count look
	if (&cnt) #100 $finish; //tells the count when to stop
	end

	initial begin
		$dumpfile("add.vcd"); //tells the test file where to make a file of the test
		$dumpvars(0, test); //dump file declared
		$display(" %11s %1s %2s %2s %2s %2s %1s %1s","t","a","b","ci","s","s_rtl","co","co_rtl"); //displayed "header" for each output
		end
		
	always @ (cnt) begin //count for the strobe 
	#90 $strobe("At time %4t %1d %1d %1d %1d   %1d      %1d      %1d", //strobe to display each outut 90 time units after the initial time unit. for example instead of  displaying at 100 it would display at 190 time units.
			$time, a,b,ci,z,z_rtl,co,co_rtl); //order for outputs to be displayed
	end
		
		//instantiation of the rtl and gate level models
	add_rtl b1 (.a(a), .b(b), .ci(ci), .z(z_rtl), .co(co_rtl));
	add g1 (.a(a), .b(b), .ci(ci), .z(z), .co(co));
endmodule