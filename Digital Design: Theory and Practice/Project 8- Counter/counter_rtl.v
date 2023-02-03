`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
module counter_rtl (CLK, LD_L, CLR_L, LD_DATA, ENP, ENT, Q, RCO); //given module name with the respective inputs and outputs necessary for the function of the gate level 3 to 8 decoder
	input CLK, LD_L, CLR_L, ENP, ENT; //inputs
	input [3:0]LD_DATA; //input
	output reg [3:0] Q; //output
	output RCO; //output
	
assign RCO = Q[3] & Q[2] & Q[1] & Q[0] & ENT; //assigns the output of the RCO to the output of the module

	always @ (posedge CLK) begin //always block that is triggered by the positive edge of the clock
		if (CLR_L == 0) begin //if the clear line is low
			Q <= 4'b0000; //set the output to 0000
		end 

		else if (LD_L == 0) begin //if the load line is low
			Q <= LD_DATA; //set the output to the data on the load line
		end

		else if (ENT == 0 || ENP == 0) begin //if the enable line is low
			Q <= Q; //set the output to the previous output
		end
		else begin
			Q <= Q + 1; //increment the output by 1
		end
	end

endmodule
