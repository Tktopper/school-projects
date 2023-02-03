`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 5, 2022

module bin_7seg_disp_rtl (MODE, DATA, A, B, C, D, E, F, G, DP); //given module name with the respective inputs and outputs necessary for the function of the gate level 3 to 8 decoder
	input MODE; 
	input [3:0] DATA; //inputs
	output reg A, B, C, D, E, F, G, DP; //outputs


		//The below case statement has a few parts to this. Outputs A to F and DP are set to either a value of 0 or 1. If it is a 1 that segment of the display is
		//on and if it is a 0 it is off. Each case statement is commented with what each respective output would be.


 	always @ (MODE or DATA)
	begin
		case(DATA)	
		4'b0000: //case that display the binary value, 0 starts with 0 and it counts up to 15. 
		begin
		A=1;B=1;C=1;D=1;E=1;F=1;G=0;DP=0;  // 0 
		end

		4'b0001: //binary 1
		begin
        A=0;B=1;C=1;D=0;E=0;F=0;G=0;DP=0;  // 1
		end

		4'b0010: //binary 2
		begin
		A=1;B=1;C=0;D=1;E=1;F=0;G=1;DP=0;  // 2 
		end

		4'b0011: //binary 3
		begin
		A=1;B=1;C=1;D=1;E=0;F=0;G=1;DP=0;  // 3 
		end

		4'b0100: //binary 4
		begin
		A=0;B=1;C=1;D=0;E=0;F=1;G=1;DP=0;  // 4
		end

		4'b0101: //binary 5
		begin
		A=1;B=0;C=1;D=1;E=0;F=1;G=1;DP=0;  // 5 
		end

		4'b0110: //binary 6
		begin
		A=1;B=0;C=1;D=1;E=1;F=1;G=1;DP=0;  // 6 
		end

		4'b0111: //binary 7
		begin
		A=1;B=1;C=1;D=0;E=0;F=0;G=0;DP=0;  // 7 
		end

		4'b1000: //binary 8
		begin
		if (MODE == 0) begin A=1;B=1;C=1;D=1;E=1;F=1;G=1;DP=0;  end // 8
		else begin A=1;B=1;C=1;D=1;E=1;F=1;G=1;DP=1;  end // -8
		end

		4'b1001: //binary 9
		begin
		if (MODE == 0) begin A=1;B=1;C=1;D=1;E=0;F=1;G=1;DP=0;  end // 9
		else begin A=1;B=1;C=1;D=0;E=0;F=0;G=0;DP=1;  end // -7
		end

		4'b1010: //binary 10
		begin
		if (MODE == 0) begin A=1;B=1;C=1;D=0;E=1;F=1;G=1;DP=0;  end // A
		else begin A=1;B=0;C=1;D=1;E=1;F=1;G=1;DP=1;  end // -6
		end

		4'b1011: //binary 11
		begin
		if (MODE == 0) begin A=0;B=0;C=1;D=1;E=1;F=1;G=1;DP=0;  end // B
		else begin A=1;B=0;C=1;D=1;E=0;F=1;G=1;DP=1;  end // -5
		end

		4'b1100: //binary 12
		begin
		if (MODE == 0) begin A=1;B=0;C=0;D=1;E=1;F=1;G=0;DP=0;  end // C
		else begin A=0;B=1;C=1;D=0;E=0;F=1;G=1;DP=1;  end // -4
		end

		4'b1101: //binary 13
		begin
		if (MODE == 0) begin A=0;B=1;C=1;D=1;E=1;F=0;G=1;DP=0;  end // D
		else begin A=1;B=1;C=1;D=1;E=0;F=0;G=1;DP=1;  end // -3
		end

		4'b1110: //binary 14
		begin
		if (MODE == 0) begin A=1;B=0;C=0;D=1;E=1;F=1;G=1;DP=0;  end // E
		else begin A=1;B=1;C=0;D=1;E=1;F=0;G=1;DP=1;  end // -2
		end

		4'b1111: //binary 15
		begin
		if (MODE == 0) begin A=1;B=0;C=0;D=0;E=1;F=1;G=1;DP=0;  end // F
		else begin A=0;B=1;C=1;D=0;E=0;F=0;G=0;DP=1;  end // -1
		end
	
		default:  //default statement for if a -0 would be put out
		begin
		A=1;B=1;C=1;D=1;E=1;F=1;G=1;DP=1; 
		end 
		endcase  //declares the end of the case statement
	end


	
endmodule