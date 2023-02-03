`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 5, 2022

module d2_5dec_rtl (d2_5, dout); //given module name with the respective inputs and outputs necessary for the function of the gate level 3 to 8 decoder
	input [4:0] d2_5; //inputs
	output reg [3:0] dout; //outputs


 	always @ (d2_5)
	begin
		case(d2_5)
		//5'bnnnnn is the case provided from the chart off the document starting from a binary 0 to a binary 9. The default statement is used to set everything that is generated that isnt on the table to a 1110 (a hex E)
		5'b01100: 
		begin
		dout[3]=0;dout[2]=0;dout[1]=0;dout[0]=0;  //binary 0
		end

		5'b11000: 
		begin
       dout[3]=0;dout[2]=0;dout[1]=0;dout[0]=1;  //binary 1
		end

		5'b10100: 
		begin
		dout[3]=0;dout[2]=0;dout[1]=1;dout[0]=0; //binary 2
		end

		5'b10010: 
		begin
		dout[3]=0;dout[2]=0;dout[1]=1;dout[0]=1; //binary 3
		end

		5'b01010: 
		begin
		dout[3]=0;dout[2]=1;dout[1]=0;dout[0]=0; //binary 4
		end

		5'b00110: 
		begin
		dout[3]=0;dout[2]=1;dout[1]=0;dout[0]=1; //binary 5
		end

		5'b10001: 
		begin
		dout[3]=0;dout[2]=1;dout[1]=1;dout[0]=0; //binary 6
		end

		5'b01001: 
		begin
		dout[3]=0;dout[2]=1;dout[1]=1;dout[0]=1; //binary 7
		end

		5'b00101: 
		begin
		dout[3]=1;dout[2]=0;dout[1]=0;dout[0]=0; //binary 8
		end

		5'b00011: 
		begin
		dout[3]=1;dout[2]=0;dout[1]=0;dout[0]=1; //binary 9
		end
		default:
		begin
	   	dout[3]=1;dout[2]=1;dout[1]=1;dout[0]=0; //default statement for any case statement that is generated without statement provided (hex E)
	  	end

		endcase  // declares the end of the case statement
	end


	
endmodule