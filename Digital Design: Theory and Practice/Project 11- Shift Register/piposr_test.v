//Tanner Kleintop
//CMPEN 270
`timescale 1ns / 1ns
module test ; //module name

reg clk; //clock
reg [3:0] Din; //input data
reg [3:0] Din_rtl; //input data
reg SI, LDin, LDout; //serial in, load in, load out
reg SI_rtl, LDin_rtl, LDout_rtl; //serial in, load in, load out
wire SO; //serial out
wire SO_rtl; //serial out
wire [3:0] Dout; //output data
wire [3:0] Dout_rtl; //output data


always begin //clock that changes every 50 ns
	#50 clk = ~clk;
end

initial begin //initial values. The = number is the value of the variable
	#0 clk = 0;
	#0 Din = 4'b0101;
	#5 SI = 1;
	#5 LDin = 1;
	#5 LDout = 1;
	#100 LDin = 1;
	#100 LDout = 1;
	#100 LDin = 1;
	#100 LDout = 0;
	#100 LDin = 0;
	#100 LDout = 1;
	#100 LDin = 0;
	#100 LDout = 0;
	#100
	$finish;
end

  always @ (posedge clk) begin
   #90
  if (Din!==Din_rtl) $strobe("ERROR: time=%4t, Din=%d  Din_rtl=%d",$time, Din, Din_rtl); 
  if (SI!==SI_rtl) $strobe("ERROR: time=%4t, SI=%d  SI_rtl=%d",$time, SI, SI_rtl);
  if (LDin!==LDin_rtl) $strobe("ERROR: time=%4t, LDin=%d  LDin_rtl=%d",$time, LDin, LDin_rtl);
  if (LDout!==LDout_rtl) $strobe("ERROR: time=%4t, LDout=%d  LDout_rtl=%d",$time, LDout, LDout_rtl);
  if (Dout!==Dout_rtl) $strobe("ERROR: time=%4t, Dout=%d  Dout_rtl=%d",$time, Dout, Dout_rtl);
  if (SO!==SO_rtl) $strobe("ERROR: time=%4t, SO=%d  SO_rtl=%d",$time, SO, SO_rtl);
  end

initial begin //initial values for the rtl module. The = number is the value of the variable
	#0 clk = 0;
	#0 Din_rtl = 4'b0101;
	#5 SI_rtl = 1;
	#5 LDin_rtl = 1;
	#5 LDout_rtl = 1;
	#100 LDin_rtl = 1;
	#100 LDout_rtl = 1;
	#100 LDin_rtl = 1;
	#100 LDout_rtl = 0;
	#100 LDin_rtl = 0;
	#100 LDout_rtl = 1;
	#100 LDin_rtl = 0;
	#100 LDout_rtl = 0;
	#100
	$finish;
end

initial begin //initial block that will print out the values of the signals
	$dumpfile("piposr.vcd");
	$dumpvars(0,test);
end


//cell instantiations
piposr_rtl sr1 (.CK(clk), .Din(Din_rtl), .Dout(Dout_rtl), .SI(SI_rtl), .LDin(LDin_rtl), .LDout(LDout_rtl), .SO(SO_rtl));
piposr sr2 (.CK(clk), .Din(Din), .Dout(Dout), .SI(SI), .LDin(LDin), .LDout(LDout), .SO(SO));

endmodule