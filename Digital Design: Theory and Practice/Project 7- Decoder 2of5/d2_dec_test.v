`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 10, 2022
//The purpose of this collection of code is to decode the provided data from the encoders
module test;

reg [4:0] cnt = 0; //register of 4 bits starting a count of 0
//the wires are used to remember the values of each respective data input that is called from the respective file
wire [3:0] dout;  
wire [3:0] dout_rtl;

always begin
  #100 cnt=cnt+1; // increments cnt every 100 time units
  if (&cnt) #100 $finish; // ends simulation 100 times units after all 1s
end

// all states for inputs
assign din = cnt[3:0];

// display headings for inputs and outputs
initial begin
  $dumpfile("dtwo_5enc.vcd"); // generates a verilog dump file for gtkwave
  $dumpvars(0,test);
  
  $display("          %3s        %2s %2s %2s %2s %2s      %2s %2s %2s %2s       %2s %2s %2s %2s",
  "t","cnt[4]","cnt[3]","cnt[2]","cnt[1]","cnt[0]","dout[3]","dout[2]","dout[1]","dout[0]" , "dout_rtl[3]" , "dout_rtl[2]", "dout_rtl[1]", "dout_rtl[0]"); //the header in which to display the inputs/ outputs
end

always @ (cnt) begin
   #90
   	if (dout_rtl[3]!==dout[3]) $strobe("ERROR: time=%4t, dout_rtl[3]=%d  dout[3]=%d",$time, dout_rtl[3], dout[3]);
   	if (dout_rtl[2]!==dout[2]) $strobe("ERROR: time=%4t, dout_rtl[2]=%d  dout[2]=%d",$time, dout_rtl[2], dout[2]);
  	if (dout_rtl[1]!==dout[1]) $strobe("ERROR: time=%4t, dout_rtl[1]=%d  dout[1]=%d",$time, dout_rtl[1], dout[1]);
  	if (dout_rtl[0]!==dout[0]) $strobe("ERROR: time=%4t, dout_rtl[0]=%d  dout[0]=%d",$time, dout_rtl[0], dout[0]);
end

// show inputs and outputs
always @ (cnt) begin // starts every time cnt changes
  // display signals 90 time units into period to get rid of delay
  #90 $strobe ("At time %5t                    %1d   %1d   %1d   %1d  %1d                    %1d   %1d   %1d   %1d                                 %1d   %1d   %1d   %1d",
  $time, cnt[4], cnt[3], cnt[2], cnt[1], cnt[0], dout[3], dout[2], dout[1], dout[0], dout_rtl[3], dout_rtl[2], dout_rtl[1], dout_rtl[0]); //the order in which the variables are displayed, this matches the above display line
end


//instantiation of modules
d2_5dec_rtl b1 (.d2_5(cnt[4:0]), .dout(dout_rtl[3:0])); // rtl cell instantiation
d2_5dec b2 (.d2_5(cnt[4:0]), .dout(dout[3:0]));

endmodule // tests the modules