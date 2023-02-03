`timescale 1ns / 1ns
// Tanner Kleintop
// Computer Engineering 270
//October 10, 2022
//The purpose of this collection of code is to make a truth table of a 7 segment display, being able to output displays -8 to 15. (10 through 15 are displayed in hex)
module test;

reg [4:0] cnt = 0; //4 bit counter starting at 0

always begin //counter that basically tells the code to keep counting up 
		#100 cnt=cnt+1;
		if (&cnt) #100 $finish;
end

assign MODE = cnt[4]; //assigns MODE to a specific count, in this case it is 4
assign DATA = cnt[3:0]; //assigns DATA to a specific countm in this case it is declared as 4 bits

initial begin
	$dumpfile("bin_7seg_disp.vcd"); //tells the test to make a vcd to use for the gtkwave
	$dumpvars(0, test);

//below is the "Header" that will list what each columns value is. The order of the display statement and strobe statement is the same so that the correct output is named correctly. 
	$display ("  %3s %4s %2s %2s %2s %2s      %3s %3s %3s %3s %3s %3s %3s %3s        %3s %3s %3s %3s %3s %3s %3s %3s",
	"t","MODE","D3","D2","D1","D0","A_rtl","B_rtl","C_rtl","D_rtl","E_rtl","F_rtl","G_rtl","DP_rtl","A","B","C","D","E","F","G","DP");
end

//below are the compare statements for each output (A-G and DP). They compare the rtl and gate level expression to make sure that the outputs match eachother from each file
always @ (cnt) begin
   #90	if (A_rtl!==A) $strobe("ERROR: time=%4t, A_rtl=%d  A=%d",$time, A_rtl, A); 
   		#90	if (B_rtl!==B) $strobe("ERROR: time=%4t, B_rtl=%d  B=%d",$time, B_rtl, B); 
      		#90	if (C_rtl!==C) $strobe("ERROR: time=%4t, C_rtl=%d  C=%d",$time, C_rtl, C); 
	     		#90	if (D_rtl!==D) $strobe("ERROR: time=%4t, D_rtl=%d  D=%d",$time, D_rtl, D); 
		    		#90	if (E_rtl!==E) $strobe("ERROR: time=%4t, E_rtl=%d  E=%d",$time, E_rtl, E); 
				   		#90	if (F_rtl!==F) $strobe("ERROR: time=%4t, F_rtl=%d  F=%d",$time, F_rtl, F);
						   #90	if (G_rtl!==G) $strobe("ERROR: time=%4t, G_rtl=%d  G=%d",$time, G_rtl, G); 
						      #90	if (DP_rtl!==DP) $strobe("ERROR: time=%4t, DP_rtl=%d  DP=%d",$time, DP_rtl, DP);  
end

//below is the always statement that displays the values outputted under a strobe statement. The outputs are put out on a count starting at 90 time units. 
always @ (cnt) begin
	#90 $strobe ("At time %5t %1d %1d %1d %1d %1d               %1d %1d %1d %1d %1d %1d %1d %1d                                     %1d %1d %1d %1d %1d %1d %1d %1d",
	$time, MODE, cnt[3], cnt[2], cnt[1], cnt[0], A_rtl, B_rtl, C_rtl, D_rtl, E_rtl, F_rtl, G_rtl, DP_rtl, A, B, C, D, E, F, G, DP);
end

//instantiations that calls the rtl and .v files
bin_7seg_disp_rtl b1 (.MODE(MODE), .DATA(cnt[3:0]), .A(A_rtl), .B(B_rtl), .C(C_rtl), .D(D_rtl), .E(E_rtl), .F(F_rtl), .G(G_rtl), .DP(DP_rtl));
bin_7seg_disp g1 (.MODE(MODE), .DATA(cnt[3:0]), .A(A), .B(B), .C(C), .D(D), .E(E), .F(F), .G(G), .DP(DP));

endmodule