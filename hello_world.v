`timescale 1ns / 1ns
module main;
reg [7:0] a;  // hns 08192017 defines a as an 8 bit binary register (has memory)
initial	// hns 08192017 run at beginning of time 
    begin
      $display("Hello, World: Tanner Kleintop");		// hns 08192017 print to display
   
	   // hns 08192017 generate verilog dump file for waveform display
     $dumpfile("hello_world.vcd");
     $dumpvars;
    end
	
initial
	begin
	a=0;
	#100 a=1;	// hns 08192017 #100 delays the assignment for 100 ns (units of time)
	#100 a=a*3;
	#100 a=a*3;
	#100 a=a*3;
	#100 a=a*3;
	#100 a=a*3;
	#100 a=a*3;
	#100 $finish;    // hns 08192017 quit simulation
   end


// hns 08192017 whenever a changes, display value of a in various bases
always @(a)
begin
	// hns 08192017 first string (" ... " ) is format statement. 
	// hns 08192017 Each %##x is a position for printing a variable
	//  hns 08192017 $time is a system variable for the time
	
	$display("%5t a base 10 = %d   a base 2 = %b  a base 16 = %x \n",$time, a, a, a) ; 
end
	
endmodule

