`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
//The purpose of this collection of code is to make a counter that counts
module test;

reg [8:0] cnt = 0; //4 bit counter that is set to start at 0
wire [3:0] Q_RTL; //wire of d2_5_rtl that will remember the logic of the the rtl 
wire [3:0] Q; //wire of the d2_5 that will remember the logic of the gate level module.
wire RCO_RTL; //wire of the RCO_RTL that will remember the logic of the rtl
wire RCO; //wire of the RCO that will remember the logic of the gate level module.
wire [3:0] LD_DATA;
reg CLK;

always @ (negedge CLK) begin //always block that will run the counter
     cnt = cnt + 1; //increments the counter by 1 every 10ns
  if (&cnt) #100 $finish; //if the counter is 255 then it will finish the simulation
end


assign CLR_L = cnt [7]; //assigns the LD_L to the 8th bit of the counter
assign LD_L = cnt [6]; //assigns the CLR_L to the 7th bit of the counter
assign ENT = cnt [5]; //assigns the ENT to the 6th bit of the counter
assign ENP = cnt [4]; //assigns the ENP to the 5th bit of the counter
assign LD_DATA = cnt [3:0]; //assigns the LD_DATA to the 4th bit of the counter

initial begin //initializes the counter to start at 0
  CLK = 0; //sets the 9th bit of the counter to 1
  #10 cnt [0] = 1; //sets the 1st bit of the counter to 1
  @ (negedge CLK) //waits for the clock to go negative
   cnt[0] = cnt[0] + 1;  //adds 1 to the 1st bit of the counter
end //ends the initial block

always begin //always block that will run the counter
  #50 CLK = ~CLK; //flips the 9th bit of the counter
end

initial begin
  $dumpfile("counter.vcd"); // generates a verilog dump file for gtkwave
  $dumpvars(0,test);
  
  $display("            %3s            %2s  %2s %2s %2s %2s   %2s %2s %2s %2s             %2s %2s %2s %2s %2s                     %2s %2s %2s %2s %2s", 
  "t", "CLK", "CLR_L", "LD_L", "ENT", "ENP", "LD_DATA[3]", "LD_DATA[2]", "LD_DATA[1]", "LD_DATA[0]", "Q[3]", "Q[2]", "Q[1]", "Q[0]", "RCO", "Q_RTL[3]", "Q_RTL[2]", "Q_RTL[1]", "Q_RTL[0]", "RCO_RTL");
   //display header in which the order is displayed
end

always @ (cnt) begin
  #90
  if (Q[3]!==Q_RTL[3]) $strobe("ERROR: time=%4t, Q[3]=%d  Q_RTL[3]=%d",$time, Q[3], Q_RTL[3]); //if the 4th bit of the counter is not equal to the 4th bit of the rtl then it will display an error
  if (Q[2]!==Q_RTL[2]) $strobe("ERROR: time=%4t, Q[2]=%d  Q_RTL[2]=%d",$time, Q[2], Q_RTL[2]); //if the 3rd bit of the counter is not equal to the 3rd bit of the rtl then it will display an error
  if (Q[1]!==Q_RTL[1]) $strobe("ERROR: time=%4t, Q[1]=%d  Q_RTL[1]=%d",$time, Q[1], Q_RTL[1]); //if the 2nd bit of the counter is not equal to the 2nd bit of the rtl then it will display an error
  if (Q[0]!==Q_RTL[0]) $strobe("ERROR: time=%4t, Q[0]=%d  Q_RTL[0]=%d",$time, Q[0], Q_RTL[0]); //if the 1st bit of the counter is not equal to the 1st bit of the rtl then it will display an error
  if (RCO!==RCO_RTL) $strobe("ERROR: time=%4t, RCO=%d  RCO_RTL=%d",$time, RCO, RCO_RTL); //if the RCO is not equal to the RCO_RTL then it will display an error
end

// show inputs and outputs
always @ (cnt) begin // starts every time cnt changes
  // display signals 90 time units into period to get rid of delay
  #90 $strobe ("At time      %5t                %1d  %1d  %1d  %1d  %1d                       %1d   %1d   %1d   %1d                             %1d  %1d  %1d  %1d  %1d                                     %1d  %1d  %1d  %1d  %1d",
  $time, CLK, CLR_L, LD_L, ENT, ENP, cnt[3], cnt[2], cnt[1], cnt[0], Q[3], Q[2], Q[1], Q[0], RCO, Q_RTL[3], Q_RTL[2], Q_RTL[1], Q_RTL[0], RCO_RTL); //outputs displayed in the same order as displayed in the header
end

//instantiation of modules
counter_rtl b1  (.CLK(CLK), .CLR_L(CLR_L), .LD_L(LD_L), .ENT(ENT), .ENP(ENP), .LD_DATA(cnt[3:0]), .Q(Q_RTL[3:0]), .RCO(RCO_RTL)); // rtl cell instantiation
counter g1 (.CLK(CLK), .CLR_L(CLR_L), .LD_L(LD_L), .ENT(ENT), .ENP(ENP), .LD_DATA(cnt[3:0]), .Q(Q[3:0]), .RCO(RCO)); // gate level cell instantiation
endmodule // tests the modules