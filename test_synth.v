module test_synth(
  input clk,
  input rst,
  input [4-1:0] din,
  output [4-1:0] dout
);

 top_level_synth uut(
    .clk(clk),
	.rst(rst),
	.start(din[0]),
	.loadseed(din[1]),
	
	.result(dout[0]),
	.done(dout[1])
 );


endmodule
