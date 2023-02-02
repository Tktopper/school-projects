`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
// Test AO311 modules
module test;

  /* stimuli for and gate */
  reg a = 0;  //starts all variables at a value of 0
  reg b = 0;
  reg c = 0;        
  reg d = 0;
  reg e = 0;
  initial begin
  //all possible combinations for truth table of a ao311. I took this approach and then found out a shorter way of doing it but kept to this method because it works
    # 100 a = 0; b = 0; c = 0; d = 0; e = 0; //00000
	# 100 a = 0; b = 0; c = 0; d = 0; e = 1; //00001
	# 100 a = 0; b = 0; c = 0; d = 1; e = 0; //00010
	# 100 a = 0; b = 0; c = 0; d = 1; e = 1; //00011
	# 100 a = 0; b = 0; c = 1; d = 0; e = 0; //00100
	# 100 a = 0; b = 0; c = 1; d = 0; e = 1; //00101
	# 100 a = 0; b = 0; c = 1; d = 1; e = 0; //00110
	# 100 a = 0; b = 0; c = 1; d = 1; e = 1; //00111
	# 100 a = 0; b = 1; c = 0; d = 0; e = 0; //01000
    # 100 a = 0; b = 1; c = 0; d = 0; e = 1; //01001
	# 100 a = 0; b = 1; c = 0; d = 1; e = 0; //01010
	# 100 a = 0; b = 1; c = 0; d = 1; e = 1; //01011
	# 100 a = 0; b = 1; c = 1; d = 0; e = 0; //01100
	# 100 a = 0; b = 1; c = 1; d = 0; e = 1; //01101
	# 100 a = 0; b = 1; c = 1; d = 1; e = 0; //01110
	# 100 a = 0; b = 1; c = 1; d = 1; e = 1; //01111
	# 100 a = 1; b = 0; c = 0; d = 0; e = 0; //10000
	# 100 a = 1; b = 0; c = 0; d = 0; e = 1; //10001
	# 100 a = 1; b = 0; c = 0; d = 1; e = 0; //10010
	# 100 a = 1; b = 0; c = 0; d = 1; e = 1; //10011
	# 100 a = 1; b = 0; c = 1; d = 0; e = 0; //10100
	# 100 a = 1; b = 0; c = 1; d = 0; e = 1; //10101
	# 100 a = 1; b = 0; c = 1; d = 1; e = 0; //10110
	# 100 a = 1; b = 0; c = 1; d = 1; e = 1; //10111
	# 100 a = 1; b = 1; c = 0; d = 0; e = 0; //11000
	# 100 a = 1; b = 1; c = 0; d = 0; e = 1; //11001
	# 100 a = 1; b = 1; c = 0; d = 1; e = 0; //11010
	# 100 a = 1; b = 1; c = 0; d = 1; e = 1; //11011
	# 100 a = 1; b = 1; c = 1; d = 0; e = 0; //11100
	# 100 a = 1; b = 1; c = 1; d = 0; e = 1; //11101
	# 100 a = 1; b = 1; c = 1; d = 1; e = 0; //11110
	# 100 a = 1; b = 1; c = 1; d = 1; e = 1; //11111
    #100 $finish(2);   //ends the combinations of truth table

  end


  initial begin
    //makes dump file for the ao311 circuit to be able to use the gtkwave
     $dumpfile("./ao311.vcd");
     $dumpvars(0,test);
     // hns12 08292017 - display ascii items on screen - this is used as a header in this case
	 // hns12 08292017 - see below for formatting options.
     $display("        %5s %1s %2s %2s %2s %2s %3s %2s","t","a","b","c","d","e","z_rtl","z"); 
    
	/* hns12 08292017 - monitor prints all signals listed when any of them change
	 //    1st string is a format string, much like c or perl
	 //      %ns would cause a string to be printed in n characters   - useful in aligning columns
	 //      each %nc  displays the next variable in your list.
	 //      values for c:
				s - string   (characters)
				b - binary
				d - decimal
				h - hex
				t - time
	 */
    
     $monitor("At time  %4t %1d  %1d  %1d  %1d  %1d  %1d  %1d", 
              $time, a , b , c , d , e , z_rtl , z );

   end

  ao311_rtl b1 (.a(a),.b(b), .c(c), .d(d), .e(e), .z(z_rtl));   // rtl cell instantiation
														
														
														
  ao311 g1 (.a(a),.b(b), .c(c), .d(d), .e(e), .z(z));			// gate level cell instatiation
endmodule // test file ends
