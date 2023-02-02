`timescale 1ns / 1ns
module test;
// Tanner Kleintop
// Computer Engineering 270
// September 12, 2022
// AO311 DeMorgans 


  reg [4:0] cnt=0; //register to with a count of 5 bits

  
  // increment counting up every 100 time units
  always begin
     # 100 cnt=cnt+1;
     if (&cnt) #100 $finish;    // end simulation 100 time units after all 1s
  end
 
  // use bits of cnt for each input. 
  assign a=cnt[4];
  assign b=cnt[3];
  assign c=cnt[2];
  assign d=cnt[1];
  assign e=cnt[0];

  initial begin
 
     $dumpfile("./ao311.vcd"); //generates the vcd file for the gtkwave
     $dumpvars(0,test); 
     $display("        %4s %1s %1s %1s %1s %1s   %3s %1s","t","a","b","c","d","e","z_rtl","z"); //displays the output of each column
   end
   
   
   // display signals at 90 time units into period to eliminate delay info
always @ (cnt) begin
     #90 $strobe("At time %4t %1d %1d %1d %1d %1d      %1d  %1d", 
              $time, a, b, c, d, e, z_rtl, z); //similar to display but gives values at the end of the current time step
      end

// compare behavioral and gate 90 time units after cnt changes
always @ (cnt) begin
   #90	if (z_rtl!==z) $strobe("ERROR: time=%4t, z_rtl=%d  z=%d",$time, z_rtl, z); //checks to verify that z_rtl==z and if it doesnt, this is outputted
end

// instantiations of modules
  ao311_rtl b1 (.a(a), .b(b), .c(c), .d(d), .e(e), .z(z_rtl));
  ao311 g1 (.a(a), .b(b), .c(c), .d(d), .e(e), .z(z));
endmodule // test
