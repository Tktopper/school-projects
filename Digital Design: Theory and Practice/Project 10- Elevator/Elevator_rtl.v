`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
module elevator_rtl (clk, B, O, RESET ); //given module name with the respective inputs and outputs necessary for the function of the gate level 3 to 8 decoder
input [3:1]B; //input for the buttons that are pressed
input clk; //input for the clock
input RESET; //input for the reset button
wire [3:1] C; //wire for the output of the state machine
output [3:1] O; //output for the state machine
wire [3:1] R; //wire for the reset button

reg [3:1] Q, nQ;

RS_LATCH l3 (.R(R[3]), .S(B[3]), .Q(C[3]));
RS_LATCH l2 (.R(R[2]), .S(B[2]), .Q(C[2]));
RS_LATCH l1 (.R(R[1]), .S(B[1]), .Q(C[1]));

//notes below from in class
    //use a case statement based on current state or 
        always @ (Q or C) begin
            case (Q)
                3'b001:
                begin
                    if (C[3] | C[2]) nQ <= 3'b011; //if C[3] or C[2] is true, then nQ is 3'b011
                    //O <= 3'b001;
                end
                3'b010:
                begin
                    if (C[2]) nQ <= 3'b010; //if C[2] is true, then nQ is 3'b010
                    else nQ <= 3'b001;
                   // O <= 3'b010;
                end
                3'b011:
                begin
                    if (C[3]) nQ <= 3'b100; //if C[3] is true, then nQ is 3'b100
                    //else (C[1]) nQ <= 3'b001;
                    else nQ <= 3'b001;
                   // O <= 3'b010;
                end
                3'b100:
                begin
                    if (C[2] | C[1]) nQ <= 3'b010; //if C[2] or C[1] is true, then nQ is 3'b010
                    //O <= 3'b100;
                end
                default: nQ <= 3'b001; //if none of the above are true, then nQ is 3'b001
            endcase
        end

        assign R = O; //assign statement for R

        assign O[3]= Q[3]; //assign statement for O[3]
        assign O[2]= Q[2]; //assign statement for O[2]
        assign O[1]= ~Q[3] & ~Q[2] & Q[1]; //assign statement for O[1]
        


        //assign O[1] = (~Q[3] & ~Q[2] & Q[1]);
       //assign O[2] = (~Q[3] & Q[2] & ~Q[1]) | (~Q[3] & Q[2] & Q[1]);
        //assign O[3] = (Q[3] & ~Q[2] & ~Q[1]);

always @ (posedge clk or posedge RESET) //always block that will change the state of the lock
begin
    if (RESET) Q <= 3'b000; //if reset is true, then Q is 3'b000
    else Q <= nQ; //else Q is nQ
end
        
	

endmodule


