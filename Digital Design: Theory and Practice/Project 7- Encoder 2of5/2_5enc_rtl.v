`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022

module two_five_enc_rtl (din, d2_5); //given module name with the respective inputs and outputs necessary for the function of the gate level 3 to 8 decoder
	input [3:0] din; //inputs
	output reg [4:0] d2_5; //outputs

 	always @ (din)
	begin
		case(din)	
		4'b0000: //case statement that uses a binary number as the case value and uses the output from the table to set each value to each that is paired to each number
		begin
		d2_5[4]=0;d2_5[3]=1;d2_5[2]=1;d2_5[1]=0;d2_5[0]=0; //01100
		end

		4'b0001: //binary 1
		begin
		d2_5[4]=1;d2_5[3]=1;d2_5[2]=0;d2_5[1]=0;d2_5[0]=0; //11000
		end

		4'b0010: //binary 2
		begin
		d2_5[4]=1;d2_5[3]=0;d2_5[2]=1;d2_5[1]=0;d2_5[0]=0; //10100
		end

		4'b0011: //binary 3
		begin
		d2_5[4]=1;d2_5[3]=0;d2_5[2]=0;d2_5[1]=1;d2_5[0]=0; //10010
		end

		4'b0100: //binary 4
		begin
		d2_5[4]=0;d2_5[3]=1;d2_5[2]=0;d2_5[1]=1;d2_5[0]=0; //01010
		end

		4'b0101: //binary 5
		begin
		d2_5[4]=0;d2_5[3]=0;d2_5[2]=1;d2_5[1]=1;d2_5[0]=0; //00110
		end

		4'b0110: //binary 6
		begin
		d2_5[4]=1;d2_5[3]=0;d2_5[2]=0;d2_5[1]=0;d2_5[0]=1; //10001
		end

		4'b0111: //binary 7
		begin
		d2_5[4]=0;d2_5[3]=1;d2_5[2]=0;d2_5[1]=0;d2_5[0]=1; //01001
		end

		4'b1000: //binary 8
		begin
		d2_5[4]=0;d2_5[3]=0;d2_5[2]=1;d2_5[1]=0;d2_5[0]=1; //00101
		end

		4'b1001: //binary 9
		begin
		d2_5[4]=0;d2_5[3]=0;d2_5[2]=0;d2_5[1]=1;d2_5[0]=1; //00011
		end
		default:
		begin
	    d2_5[4]=1;d2_5[3]=1;d2_5[2]=0;d2_5[1]=1;d2_5[0]=1; // 11011
	  	end

		endcase  // declares the end of the case statement
	end


	
endmodule