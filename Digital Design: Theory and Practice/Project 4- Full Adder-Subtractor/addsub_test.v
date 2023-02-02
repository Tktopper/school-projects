`timescale 1ns / 1ns
//Tanner Kleintop
//Computer Engineering 270
//September 25, 2022
//The purpose of this set of code is to make a 4 bit adder using the 1 bit adder from the previous assignment with the ability to subtract
module test;

reg [8:0] cnt=0; //9 bit count starting at 0
wire [3:0] z_rtl, z; //wire declared as z and z_rtl to retain the "memory" of the output
assign ci = sub;

	assign a = cnt[7:4]; //assigned a at a count of 10 bits
	assign b = cnt[3:0]; //assigned b at a count of 4 bits
	assign sub = cnt[8]; //assigned cin at a count of 8 bits
	
	always begin
	# 100 cnt=cnt+1; //begins the count look
	if (&cnt) #100 $finish; //tells the count when to stop
	end

	initial begin
		$dumpfile("addsub.vcd"); //tells the test file where to make a file of the test
		$dumpvars(0, test); //dump file declared
		$display("        %5s %1s %1s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3s %3d %3s %3s",
                   "t", "ci","sub","a3","a2","a1","a0","b3","b2","b1","b0","z_rtl1","z_rtl1","z_rtl1","z_rtl0","co_rtl","oflow_rtl","z3","z2","z1","z0","co","oflow"); //displayed "header" for each output
		end
		
	always @ (cnt) begin //count for the strobe 
	#90 $strobe("At time %5t %2d %3d %3d  %3d  %3d  %3d  %3d  %3d  %3d  %3d  %3d  %3d  %3d  %3d  %3d  %3d %3d %3d %3d %3d %3d %3d %3d",  
             $time, ci, sub, cnt[8], cnt[7], cnt[6], cnt[5], cnt[4], cnt[3], cnt[2], cnt[1], cnt[0], z_rtl[3], z_rtl[2], z_rtl[1], z_rtl[0], co_rtl, oflow_rtl, z[3], z[2], z[1], z[0], co, oflow); //order for outputs to be displayed
	end


//below are all the compare statements that compare each rtl output and each gate level output
	always @ (cnt) begin
   #90	if (z_rtl[0]!==z[0]) $strobe("ERROR: time=%4t, z_rtl[0]=%d  z[0]=%d",$time, z_rtl, z); 
end
always @ (cnt) begin
   #90	if (z_rtl[1]!==z[1]) $strobe("ERROR: time=%4t, z_rtl[1]=%d  z[1]=%d",$time, z_rtl, z); 
end
always @ (cnt) begin
   #90	if (z_rtl[2]!==z[2]) $strobe("ERROR: time=%4t, z_rtl[2]=%d  z[2]=%d",$time, z_rtl, z); 
end
always @ (cnt) begin
   #90	if (z_rtl[3]!==z[3]) $strobe("ERROR: time=%4t, z_rtl[3]=%d  z[3]=%d",$time, z_rtl, z); 
end
	always @ (cnt) begin
   #90	if (co_rtl!==co) $strobe("ERROR: time=%4t, co_rtl=%d  co=%d",$time, z_rtl, z);
end
	always @ (cnt) begin
   #90	if (oflow_rtl!==oflow) $strobe("ERROR: time=%4t, oflow_rtl=%d  oflow_rtl=%d",$time, z_rtl, z);
end
		
		//instantiation of the rtl and gate level models
	addsub_rtl g1 (.sub(cnt[8]), .ci(ci), .a(cnt[7:4]), .b(cnt[3:0]), .z(z_rtl[3:0]), .co(co_rtl), .oflow(oflow_rtl));
	addsub gt6 (.sub(cnt[8]), .ci(ci), .a(cnt[7:4]), .b(cnt[3:0]), .z(z[3:0]), .co(co), .oflow(oflow));
endmodule