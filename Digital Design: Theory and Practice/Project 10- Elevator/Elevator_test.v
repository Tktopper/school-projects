`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
//The purpose of this collection of code is to make a counter that counts
module test;

reg clk, RESET; //registers for the clock and reset
reg [3:1]B = 3'b001; //register for the buttons that are pressed
wire [3:1] O; //wire for the output of the state machine



always begin 
    #50 clk = ~clk; //increments the clock by 1 every 50ns
end

initial begin
#0 clk = 0; //initializes the clock to 0
#0 RESET = 1'b1; //initializes the reset to 1
#10 RESET = 1'b0; //resets the reset to 0
#90 //waits 90ns
#100 B= 3'b001; //sets the input to 1
#100 B= 3'b010; //sets the input to 2
#100 B= 3'b011; //sets the input to 3
#100 B= 3'b100; //sets the input to 4
#100 B= 3'b001; //sets the input to 0
  $finish;
end


initial begin
  $dumpfile("Elevator.vcd"); // generates a verilog dump file for gtkwave
  $dumpvars(0,test);
    $display("            %3s          %2s    %2s     %2s %2s %2s       %2s %2s %2s", 
    "t", "CLK", "RESET", "B3", "B2", "B1", "O3", "O2", "O1"); //displays the header for the table
     //display header in which the order is displayed
end


// show inputs and outputs
always @ (negedge clk) begin // starts every time cnt changes
  // display signals 90 time units into period to get rid of delay
    #90 $strobe ("At time      %5t    %1d      %1d      %1d  %1d  %1d         %1d  %1d  %1d", $time, clk, RESET, B[3], B[2], B[1], O[3], O[2], O[1]); //displays the values of the inputs and outputs
end

//instantiation of modules
elevator_rtl e1  (.clk(clk), .RESET(RESET), .O(O), .B(B)); // rtl cell instantiation
endmodule // tests the modules