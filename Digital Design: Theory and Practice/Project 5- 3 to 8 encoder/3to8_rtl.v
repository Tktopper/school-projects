`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//September 26, 2022

module three_to_eight_rtl (A, B, C, G1, G2AN, G3BN, Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7); //Module name with displayed inputs and outputs necessary for the function of the rtl file to run
	input A,B,C,G1,G2AN,G3BN; //listed inputs
	output Y0,Y1,Y2,Y3,Y4,Y5,Y6,Y7; //listed outputs

    //below is each respective equation that is for each respective output

    assign enable= ((G1 & ~G2AN & ~G3BN));
    assign Y7= ~( A & B & C & enable );
    assign Y6= ~( A & B & ~C & enable );
    assign Y5= ~( A & ~B & C & enable );
    assign Y4= ~( A & ~B & ~C & enable );
    assign Y3= ~( ~A & B & C & enable );
    assign Y2= ~( ~A & B & ~C & enable );
    assign Y1= ~( ~A & ~B & C & enable );
    assign Y0= ~( ~A &~B & ~C & enable );
endmodule