   
module top_level_synth
(
   input clk,
   input rst,
   input start,
   input loadseed,
   
   output result,
   output done
);

  localparam grid_size = 4;
  localparam rand_width = 3;
  localparam max_edges_width = 8;
  localparam mem_edges_depth = 8;
  localparam mem_edges_width = 8;
  localparam mem_offset_depth = 6;
  localparam mem_offset_width = 4;
  localparam mem_position_depth = 7;
  localparam mem_position_width = 5;
  localparam mem_grid_depth = 7;
  localparam mem_grid_width = 8;
  
  reg [32-1:0] seed;
  reg [max_edges_width-1:0] n_edge;
   
  always @(posedge clk) begin
    if(rst) begin
        seed <= 1;
        n_edge <= 0;
    end else begin
       if(loadseed)begin
          seed <= seed + 1;
       end 
       if(start)begin
          n_edge <= 19;
       end 
    end 
  end

  placement_top
  #(
    .grid_size(grid_size),
    .rand_width(rand_width),
    .max_edges_width(max_edges_width),
    .mem_edges_depth(mem_edges_depth),
    .mem_edges_width(mem_edges_width),
    .mem_offset_depth(mem_offset_depth),
    .mem_offset_width(mem_offset_width),
    .mem_position_depth(mem_position_depth),
    .mem_position_width(mem_position_width),
    .mem_grid_depth(mem_grid_depth),
    .mem_grid_width(mem_grid_width)
  )
  p1
  (
    .clk(clk),
    .rst(rst),
    .start(start),
    .loadseed(loadseed),
    .seed(seed),
    .n_edge(n_edge),
    .result(result),
    .done(done)
  );


endmodule

