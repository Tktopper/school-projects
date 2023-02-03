`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 17, 2022
//The purpose of this collection of code is to make a counter that counts
module test;

  reg  x = 0;  //input
  reg  clr = 0;  //input
  reg  clk = 0;  //input
  wire HINT_bool;  //wire for boolean hint
  wire HINT_CASE;  //wire for case hint
  wire UNLK_bool;  //wire for boolean unlock
  wire UNLK_CASE;  //wire for case unlock

  always begin
    #50 clk = ~clk;  //increments the clock by 1 every 50ns
  end




  initial begin
    #0 clr = 1;  //sets the clear to 1
    #20 clr = 0;  //sets the clear to 0
    #100 x = 0;  //sets the input X to 1 after 100ns
    #100 x = 1;  //sets the input X to 0 after 200ns
    #100 x = 1;  //sets the input X to 1 after 300ns
    #100 x = 0;  //sets the input X to 0 after 400ns
    #100 x = 1;  //sets the input X to 1 after 500ns
    #100 x = 1;  //sets the input X to 0 after 600ns
    #100 x = 1;  //sets the input X to 1 after 700ns
    #100 x = 0;  //sets the input X to 0 after 800ns
    $finish;
  end


  initial begin
    $dumpfile("Combinational_Lock.vcd");  // generates a verilog dump file for gtkwave
    $dumpvars(0, test);  // dumps the variables to the file

    $display("            %3s          %2s %2s  %2s  %2s %2s %2s %2s", "t", "CLK", "CLR", "X",
             "UNLK_bool", "UNLK_case", "HINT_bool",
             "HINT_case");  //displays the header for the table
    //display header in which the order is displayed
  end

  //always @ () begin
  // #90
  //if (UNLK_bool!==UNLK_CASE) $strobe("ERROR: time=%4t, UNLK_bool=%d  UNLK_CASE=%d",$time, UNLK_bool, UNLK_CASE); //if the UNLK_bool and UNLK_case are not equal, then it will display an error
  //if (HINT_bool!==HINT_CASE) $strobe("ERROR: time=%4t, HINT_bool=%d  HINT_CASE=%d",$time, HINT_bool, HINT_CASE); //if the HINT_bool and HINT_case are not equal, then it will display an error

  //end

  // show inputs and outputs
  always @(negedge clk) begin  // starts every time cnt changes
    // display signals 90 time units into period to get rid of delay
    #90
      $strobe(
          "At time      %5t        %1d   %1d    %1d      %1d         %1d         %1d         %1d",
          $time,
          clk,
          clr,
          x,
          UNLK_bool,
          UNLK_case,
          HINT_bool,
          HINT_case
      );  //outputs displayed in the same order as displayed in the header
  end

  //instantiation of modules
  combination_boolean_rtl b1 (
      .CLK(clk),
      .CLR(clr),
      .X(x),
      .UNLK(UNLK_bool),
      .HINT(HINT_bool)
  );  // rtl cell instantiation
  combination_case_rtl c1 (
      .CLK(clk),
      .CLR(clr),
      .X(x),
      .UNLK(UNLK_case),
      .HINT(HINT_case)
  );  // rtl cell instantiation
  //counter g1 (.CLK(CLK), .CLR_L(CLR_L), .LD_L(LD_L), .ENT(ENT), .ENP(ENP), .LD_DATA(cnt[3:0]), .Q(Q[3:0]), .RCO(RCO)); // gate level cell instantiation
endmodule  // tests the modules
