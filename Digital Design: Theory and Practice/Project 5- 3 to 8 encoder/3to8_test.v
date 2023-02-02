`timescale 1ns / 1ns
//Tanner Kleintop
//Computer Engineering 270
//September 30, 2022
module test;

reg [5:0] cnt=0; //6 bit count starting at 0

	assign A = cnt[2];
	assign B = cnt[1];
    assign C = cnt[0];
    assign G1 = cnt[5];
    assign G2AN = cnt[4];
    assign G3BN = cnt[3]; 
	
	always begin
	# 100 cnt=cnt+1; //begins the count look
	if (&cnt) #100 $finish; //tells the count when to stop
	end
	
		//Compare statements that come the rtl and .v outputs, displaying an error if the outputs do not match
	always @ (cnt) begin
   #90	if (Y0_rtl!==Y0) $strobe("ERROR: time=%4t, Y0_rtl=%d  Y0=%d",$time, Y0_rtl, Y0); 
end
	always @ (cnt) begin
   #90	if (Y1_rtl!==Y1) $strobe("ERROR: time=%4t, Y1_rtl=%d  Y1=%d",$time, Y1_rtl, Y1); 
end
	always @ (cnt) begin
   #90	if (Y2_rtl!==Y2) $strobe("ERROR: time=%4t, Y2_rtl=%d  Y2=%d",$time, Y2_rtl, Y2); 
end
	always @ (cnt) begin
   #90	if (Y3_rtl!==Y3) $strobe("ERROR: time=%4t, Y3_rtl=%d  Y3=%d",$time, Y3_rtl, Y3); 
end
	always @ (cnt) begin
   #90	if (Y4_rtl!==Y4) $strobe("ERROR: time=%4t, Y4_rtl=%d  Y4=%d",$time, Y4_rtl, Y4); 
end
	always @ (cnt) begin
   #90	if (Y5_rtl!==Y5) $strobe("ERROR: time=%4t, Y5_rtl=%d  Y5=%d",$time, Y5_rtl, Y5); 
end
	always @ (cnt) begin
   #90	if (Y6_rtl!==Y6) $strobe("ERROR: time=%4t, Y6_rtl=%d  Y6=%d",$time, Y6_rtl, Y6); 
end
	always @ (cnt) begin
   #90	if (Y7_rtl!==Y7) $strobe("ERROR: time=%4t, Y7_rtl=%d  Y7=%d",$time, Y7_rtl, Y7); 
end

	initial begin
		$dumpfile("3to8.vcd"); //tells the test file where to make a file of the test
		$dumpvars(0, test); //dump file declared
		$display(" %11s %2s %2s %2s     %2s %2s %2s     %2s %2s %2s %2s %2s %2s %2s %2s     %2s %2s %2s %2s %2s %2s %2s %2s","t","A","B","C","G1","G2AN","G3BN","Y0","Y1","Y2","Y3","Y4","Y5","Y6","Y7","Y0_rtl","Y1_rtl","Y2_rtl","Y3_rtl","Y4_rtl","Y5_rtl","Y6_rtl","Y7_rtl"); //displayed "header" for each output
		end
		
	always @ (cnt) begin //count for the strobe 
	#90 $strobe("At time %4t   %1d %1d %1d        %1d %1d %1d               %1d %1d %1d %1d %1d %1d %1d %1d           %1d %1d %1d %1d %1d %1d %1d %1d", //strobe to display each outut 90 time units after the initial time unit. for example instead of  displaying at 100 it would display at 190 time units.
			$time, A, B, C, G1, G2AN, G3BN, 
            Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7, 
            Y0_rtl, Y1_rtl, Y2_rtl, Y3_rtl, Y4_rtl, Y5_rtl, Y6_rtl, Y7_rtl); //order for outputs to be displayed
	end
		
		//instantiation of the rtl and gate level models
	three_to_eight_rtl b1 (.A(A), .B(B), .C(C), .G1(G1), .G2AN(G2AN), .G3BN(G3BN), .Y0(Y0_rtl), .Y1(Y1_rtl), .Y2(Y2_rtl), .Y3(Y3_rtl), .Y4(Y4_rtl), .Y5(Y5_rtl), .Y6(Y6_rtl), .Y7(Y7_rtl));
	three_to_eight g1 (.A(A), .B(B), .C(C), .G1(G1), .G2AN(G2AN), .G3BN(G3BN), .Y0(Y0), .Y1(Y1), .Y2(Y2), .Y3(Y3), .Y4(Y4), .Y5(Y5), .Y6(Y6), .Y7(Y7));
endmodule