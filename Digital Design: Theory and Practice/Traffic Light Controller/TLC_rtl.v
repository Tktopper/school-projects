`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
// November 8, 2022
// Traffic Light Controller
module TLC_rtl (CLK, MD, SD, clr, MR, MY, MG, MA, SR, SY, SG); //module name

input CLK, MD, SD, clr; //input signals
output reg MG, MY, MR, MA, SR, SY, SG; //output wires

reg [3:0] state; //state register
reg [3:0] next_state; //next state register

parameter [3:0] //state machine states
A = 4'b0000,
B = 4'b0001,
C = 4'b0010,
D = 4'b0011,
E = 4'b0100,
F = 4'b0101,
G = 4'b0110,
H = 4'b0111,
I = 4'b1000,
J = 4'b1001;
/*
A is Main Red, Side Red
B is Main Green, Side Red
C is Main Green, Side Red
D is Main Green, Side Red
E is Main Yellow, Side Red
F is Main Red, Side Red
G is Main Red, Side Green
H is Main Red, Side Yellow
I is Main Red, Side Red
J is Main Red, Side Red, Arrow Green
*/

always @ (posedge CLK) //always block
begin //begin always block
	if (clr) //if clear is high
		state <= 4'b0000; //set state to A
	else //otherwise
		state <= next_state; //set state to next state
end //end always block

always @ (MD or SD or state)begin //begin always block
	case (state) //case statement
		A: next_state <=B; //if state is A, next state is B
		B: next_state <=C; //if state is B, next state is C
		C: next_state <=D; //if state is C, next state is D
		D: next_state <= (!MD && !SD) ? D : E; //if state is D, next state is D if MD and SD are low, otherwise next state is E
		E: next_state <=F; //if state is E, next state is F
		F: next_state <= (MD && !SD) ? J : G; //if state is F, next state is J if MD is high and SD is low, otherwise next state is G
		G: next_state <= H; //if state is G, next state is H
		H: next_state <= I; //if state is H, next state is I
		I: next_state <= MD? J : B; //if state is I, next state is J if MD is high, otherwise next state is B
		J: next_state <= A; //if state is J, next state is A
			default : next_state <= A; //if state is none of the above, next state is A
	endcase //end case statement
end //end always block

always @ (state) //always block
	begin //begin always block
	//when the output value is a 1 the light is on, when the output value is a 0 the light is off
		case (state)
		A: begin //output logic for state A
			MR = 1;
			MY = 0;
			MG = 0;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		B: begin //output logic for state B
			MR = 0;
			MY = 0;
			MG = 1;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		C: begin //output logic for state C
			MR = 0;
			MY = 0;
			MG = 1;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		D: begin //output logic for state D
			MR = 0;
			MY = 0;
			MG = 1;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		E: begin //output logic for state E
			MR = 0;
			MY = 1;
			MG = 0;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		F: begin //output logic for state F
			MR = 1;
			MY = 0;
			MG = 0;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		G: begin //output logic for state G
			MR = 1;
			MY = 0;
			MG = 0;
			MA = 0;
			SR = 0;
			SY = 0;
			SG = 1;
		end
		H: begin //output logic for state H
			MR = 1;
			MY = 0;
			MG = 0;
			MA = 0;
			SR = 0;
			SY = 1;
			SG = 0;
		end
		I: begin //output logic for state I
			MR = 1;
			MY = 0;
			MG = 0;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		J: begin //output logic for state J
			MR = 1;
			MY = 0;
			MG = 0;
			MA = 1;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		default: //default output logic
		begin
			MR = 1;
			MY = 0;
			MG = 0;
			MA = 0;
			SR = 1;
			SY = 0;
			SG = 0;
		end
		endcase //end case statement
	end //end always block
  
  
endmodule //end module
