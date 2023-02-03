`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
//The purpose of this collection of code is to take the data provided from the table and turn it into binary. 
module test;

reg [3:0] cnt = 0; //4 bit counter that is set to start at 0
wire [4:0] d2_5_rtl; //wire of d2_5_rtl that will remember the logic of the the rtl 
wire [4:0] d2_5; //wire of the d2_5 that will remember the logic of the gate level module. 

always begin
  #100 cnt=cnt+1; // increments cnt every 100 time units
  if (&cnt) #100 $finish; // ends simulation 100 times units after all 1s
end

// all states for inputs
assign din = cnt[3:0];

// display headings for inputs and outputs
initial begin
  $dumpfile("two_5enc.vcd"); // generates a verilog dump file for gtkwave
  $dumpvars(0,test);
  
  $display("        %3s          %2s %2s %2s %2s       %2s %2s %2s %2s %2s           %2s  %2s  %2s  %2s  %2s",
  "t","din[3]","din[2]","din[1]","din[0]","d2_5_rtl[4]","d2_5_rtl[3]","d2_5_rtl[2]","d2_5_rtl[1]","d2_5_rtl[0]","d2_5[4]","d2_5[3]","d2_5[2]","d2_5[1]","d2_5[0]"); //display header in which the order is displayed
end

//comparison statement that will compare the rtl and gate levels for any issues
always @ (cnt) begin
   #90
   	if (d2_5_rtl[4]!==d2_5[4]) $strobe("ERROR: time=%4t, d2_5_rtl[4]=%d  d2_5[4]=%d",$time, d2_5_rtl[4], d2_5[4]);
  	if (d2_5_rtl[3]!==d2_5[3]) $strobe("ERROR: time=%4t, d2_5_rtl[3]=%d  d2_5[3]=%d",$time, d2_5_rtl[3], d2_5[3]);
    if (d2_5_rtl[2]!==d2_5[2]) $strobe("ERROR: time=%4t, d2_5_rtl[2]=%d  d2_5[2]=%d",$time, d2_5_rtl[2], d2_5[2]);
    if (d2_5_rtl[1]!==d2_5[1]) $strobe("ERROR: time=%4t, d2_5_rtl[1]=%d  d2_5[1]=%d",$time, d2_5_rtl[1], d2_5[1]);
    if (d2_5_rtl[0]!==d2_5[0]) $strobe("ERROR: time=%4t, d2_5_rtl[0]=%d  d2_5[0]=%d",$time, d2_5_rtl[0], d2_5[0]);
end

// show inputs and outputs
always @ (cnt) begin // starts every time cnt changes
  // display signals 90 time units into period to get rid of delay
  #90 $strobe ("At time %5t          %1d   %1d   %1d   %1d                                             %1d   %1d   %1d   %1d   %1d                             %1d   %1d   %1d   %1d   %1d",
  $time, cnt[3], cnt[2], cnt[1], cnt[0], d2_5_rtl[4], d2_5_rtl[3], d2_5_rtl[2], d2_5_rtl[1], d2_5_rtl[0], d2_5[4], d2_5[3], d2_5[2], d2_5[1], d2_5[0]); //outputs displayed in the same order as displayed in the header
end

//instantiation of modules
two_five_enc_rtl b1 (.din(cnt[3:0]), .d2_5(d2_5_rtl[4:0])); // rtl cell instantiation
two_five_enc b2 (.din(cnt[3:0]), .d2_5(d2_5[4:0])); //gate level cell instantiation

endmodule // tests the modules