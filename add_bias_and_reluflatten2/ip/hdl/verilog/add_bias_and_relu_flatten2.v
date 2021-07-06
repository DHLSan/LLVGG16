// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="add_bias_and_relu_flatten2,hls_ip_2017_4_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=1,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020clg484-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.159000,HLS_SYN_LAT=12299,HLS_SYN_TPT=none,HLS_SYN_MEM=24,HLS_SYN_DSP=2,HLS_SYN_FF=972,HLS_SYN_LUT=1357}" *)

module add_bias_and_relu_flatten2 (
        ap_clk,
        ap_rst_n,
        s_axi_CONTROL_AWVALID,
        s_axi_CONTROL_AWREADY,
        s_axi_CONTROL_AWADDR,
        s_axi_CONTROL_WVALID,
        s_axi_CONTROL_WREADY,
        s_axi_CONTROL_WDATA,
        s_axi_CONTROL_WSTRB,
        s_axi_CONTROL_ARVALID,
        s_axi_CONTROL_ARREADY,
        s_axi_CONTROL_ARADDR,
        s_axi_CONTROL_RVALID,
        s_axi_CONTROL_RREADY,
        s_axi_CONTROL_RDATA,
        s_axi_CONTROL_RRESP,
        s_axi_CONTROL_BVALID,
        s_axi_CONTROL_BREADY,
        s_axi_CONTROL_BRESP,
        interrupt,
        s_axi_INPUT_AWVALID,
        s_axi_INPUT_AWREADY,
        s_axi_INPUT_AWADDR,
        s_axi_INPUT_WVALID,
        s_axi_INPUT_WREADY,
        s_axi_INPUT_WDATA,
        s_axi_INPUT_WSTRB,
        s_axi_INPUT_ARVALID,
        s_axi_INPUT_ARREADY,
        s_axi_INPUT_ARADDR,
        s_axi_INPUT_RVALID,
        s_axi_INPUT_RREADY,
        s_axi_INPUT_RDATA,
        s_axi_INPUT_RRESP,
        s_axi_INPUT_BVALID,
        s_axi_INPUT_BREADY,
        s_axi_INPUT_BRESP,
        s_axi_OUTPUT_AWVALID,
        s_axi_OUTPUT_AWREADY,
        s_axi_OUTPUT_AWADDR,
        s_axi_OUTPUT_WVALID,
        s_axi_OUTPUT_WREADY,
        s_axi_OUTPUT_WDATA,
        s_axi_OUTPUT_WSTRB,
        s_axi_OUTPUT_ARVALID,
        s_axi_OUTPUT_ARREADY,
        s_axi_OUTPUT_ARADDR,
        s_axi_OUTPUT_RVALID,
        s_axi_OUTPUT_RREADY,
        s_axi_OUTPUT_RDATA,
        s_axi_OUTPUT_RRESP,
        s_axi_OUTPUT_BVALID,
        s_axi_OUTPUT_BREADY,
        s_axi_OUTPUT_BRESP,
        s_axi_parameter_AWVALID,
        s_axi_parameter_AWREADY,
        s_axi_parameter_AWADDR,
        s_axi_parameter_WVALID,
        s_axi_parameter_WREADY,
        s_axi_parameter_WDATA,
        s_axi_parameter_WSTRB,
        s_axi_parameter_ARVALID,
        s_axi_parameter_ARREADY,
        s_axi_parameter_ARADDR,
        s_axi_parameter_RVALID,
        s_axi_parameter_RREADY,
        s_axi_parameter_RDATA,
        s_axi_parameter_RRESP,
        s_axi_parameter_BVALID,
        s_axi_parameter_BREADY,
        s_axi_parameter_BRESP
);

parameter    ap_ST_fsm_state1 = 6'd1;
parameter    ap_ST_fsm_pp0_stage0 = 6'd2;
parameter    ap_ST_fsm_pp0_stage1 = 6'd4;
parameter    ap_ST_fsm_state12 = 6'd8;
parameter    ap_ST_fsm_pp1_stage0 = 6'd16;
parameter    ap_ST_fsm_state15 = 6'd32;
parameter    C_S_AXI_CONTROL_DATA_WIDTH = 32;
parameter    C_S_AXI_CONTROL_ADDR_WIDTH = 4;
parameter    C_S_AXI_DATA_WIDTH = 32;
parameter    C_S_AXI_INPUT_DATA_WIDTH = 32;
parameter    C_S_AXI_INPUT_ADDR_WIDTH = 15;
parameter    C_S_AXI_OUTPUT_DATA_WIDTH = 32;
parameter    C_S_AXI_OUTPUT_ADDR_WIDTH = 15;
parameter    C_S_AXI_PARAMETER_DATA_WIDTH = 32;
parameter    C_S_AXI_PARAMETER_ADDR_WIDTH = 15;

parameter C_S_AXI_CONTROL_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_INPUT_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_OUTPUT_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_PARAMETER_WSTRB_WIDTH = (32 / 8);

input   ap_clk;
input   ap_rst_n;
input   s_axi_CONTROL_AWVALID;
output   s_axi_CONTROL_AWREADY;
input  [C_S_AXI_CONTROL_ADDR_WIDTH - 1:0] s_axi_CONTROL_AWADDR;
input   s_axi_CONTROL_WVALID;
output   s_axi_CONTROL_WREADY;
input  [C_S_AXI_CONTROL_DATA_WIDTH - 1:0] s_axi_CONTROL_WDATA;
input  [C_S_AXI_CONTROL_WSTRB_WIDTH - 1:0] s_axi_CONTROL_WSTRB;
input   s_axi_CONTROL_ARVALID;
output   s_axi_CONTROL_ARREADY;
input  [C_S_AXI_CONTROL_ADDR_WIDTH - 1:0] s_axi_CONTROL_ARADDR;
output   s_axi_CONTROL_RVALID;
input   s_axi_CONTROL_RREADY;
output  [C_S_AXI_CONTROL_DATA_WIDTH - 1:0] s_axi_CONTROL_RDATA;
output  [1:0] s_axi_CONTROL_RRESP;
output   s_axi_CONTROL_BVALID;
input   s_axi_CONTROL_BREADY;
output  [1:0] s_axi_CONTROL_BRESP;
output   interrupt;
input   s_axi_INPUT_AWVALID;
output   s_axi_INPUT_AWREADY;
input  [C_S_AXI_INPUT_ADDR_WIDTH - 1:0] s_axi_INPUT_AWADDR;
input   s_axi_INPUT_WVALID;
output   s_axi_INPUT_WREADY;
input  [C_S_AXI_INPUT_DATA_WIDTH - 1:0] s_axi_INPUT_WDATA;
input  [C_S_AXI_INPUT_WSTRB_WIDTH - 1:0] s_axi_INPUT_WSTRB;
input   s_axi_INPUT_ARVALID;
output   s_axi_INPUT_ARREADY;
input  [C_S_AXI_INPUT_ADDR_WIDTH - 1:0] s_axi_INPUT_ARADDR;
output   s_axi_INPUT_RVALID;
input   s_axi_INPUT_RREADY;
output  [C_S_AXI_INPUT_DATA_WIDTH - 1:0] s_axi_INPUT_RDATA;
output  [1:0] s_axi_INPUT_RRESP;
output   s_axi_INPUT_BVALID;
input   s_axi_INPUT_BREADY;
output  [1:0] s_axi_INPUT_BRESP;
input   s_axi_OUTPUT_AWVALID;
output   s_axi_OUTPUT_AWREADY;
input  [C_S_AXI_OUTPUT_ADDR_WIDTH - 1:0] s_axi_OUTPUT_AWADDR;
input   s_axi_OUTPUT_WVALID;
output   s_axi_OUTPUT_WREADY;
input  [C_S_AXI_OUTPUT_DATA_WIDTH - 1:0] s_axi_OUTPUT_WDATA;
input  [C_S_AXI_OUTPUT_WSTRB_WIDTH - 1:0] s_axi_OUTPUT_WSTRB;
input   s_axi_OUTPUT_ARVALID;
output   s_axi_OUTPUT_ARREADY;
input  [C_S_AXI_OUTPUT_ADDR_WIDTH - 1:0] s_axi_OUTPUT_ARADDR;
output   s_axi_OUTPUT_RVALID;
input   s_axi_OUTPUT_RREADY;
output  [C_S_AXI_OUTPUT_DATA_WIDTH - 1:0] s_axi_OUTPUT_RDATA;
output  [1:0] s_axi_OUTPUT_RRESP;
output   s_axi_OUTPUT_BVALID;
input   s_axi_OUTPUT_BREADY;
output  [1:0] s_axi_OUTPUT_BRESP;
input   s_axi_parameter_AWVALID;
output   s_axi_parameter_AWREADY;
input  [C_S_AXI_PARAMETER_ADDR_WIDTH - 1:0] s_axi_parameter_AWADDR;
input   s_axi_parameter_WVALID;
output   s_axi_parameter_WREADY;
input  [C_S_AXI_PARAMETER_DATA_WIDTH - 1:0] s_axi_parameter_WDATA;
input  [C_S_AXI_PARAMETER_WSTRB_WIDTH - 1:0] s_axi_parameter_WSTRB;
input   s_axi_parameter_ARVALID;
output   s_axi_parameter_ARREADY;
input  [C_S_AXI_PARAMETER_ADDR_WIDTH - 1:0] s_axi_parameter_ARADDR;
output   s_axi_parameter_RVALID;
input   s_axi_parameter_RREADY;
output  [C_S_AXI_PARAMETER_DATA_WIDTH - 1:0] s_axi_parameter_RDATA;
output  [1:0] s_axi_parameter_RRESP;
output   s_axi_parameter_BVALID;
input   s_axi_parameter_BREADY;
output  [1:0] s_axi_parameter_BRESP;

reg    ap_rst_n_inv;
wire    ap_start;
reg    ap_done;
reg    ap_idle;
(* fsm_encoding = "none" *) reg   [5:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    ap_ready;
reg   [11:0] mem_block1_dense_address0;
reg    mem_block1_dense_ce0;
reg    mem_block1_dense_we0;
wire   [31:0] mem_block1_dense_q0;
wire   [11:0] bd2_address0;
reg    bd2_ce0;
wire   [31:0] bd2_q0;
wire   [11:0] memblock1_dense_address0;
reg    memblock1_dense_ce0;
reg    memblock1_dense_we0;
reg   [12:0] i_reg_123;
reg   [12:0] i_1_reg_134;
wire   [0:0] exitcond1_fu_154_p2;
reg   [0:0] exitcond1_reg_237;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_block_state2_pp0_stage0_iter0;
wire    ap_block_state4_pp0_stage0_iter1;
wire    ap_block_state6_pp0_stage0_iter2;
wire    ap_block_state8_pp0_stage0_iter3;
wire    ap_block_state10_pp0_stage0_iter4;
wire    ap_block_pp0_stage0_11001;
reg   [0:0] ap_reg_pp0_iter1_exitcond1_reg_237;
reg   [0:0] ap_reg_pp0_iter2_exitcond1_reg_237;
reg   [0:0] ap_reg_pp0_iter3_exitcond1_reg_237;
reg   [0:0] ap_reg_pp0_iter4_exitcond1_reg_237;
wire   [12:0] i_2_fu_160_p2;
reg   [12:0] i_2_reg_241;
reg    ap_enable_reg_pp0_iter0;
reg   [11:0] mem_block1_dense_add_reg_251;
reg   [11:0] ap_reg_pp0_iter1_mem_block1_dense_add_reg_251;
reg   [11:0] ap_reg_pp0_iter2_mem_block1_dense_add_reg_251;
reg   [11:0] ap_reg_pp0_iter3_mem_block1_dense_add_reg_251;
reg   [11:0] ap_reg_pp0_iter4_mem_block1_dense_add_reg_251;
reg   [31:0] bd2_load_reg_256;
wire    ap_CS_fsm_pp0_stage1;
wire    ap_block_state3_pp0_stage1_iter0;
wire    ap_block_state5_pp0_stage1_iter1;
wire    ap_block_state7_pp0_stage1_iter2;
wire    ap_block_state9_pp0_stage1_iter3;
wire    ap_block_state11_pp0_stage1_iter4;
wire    ap_block_pp0_stage1_11001;
reg   [31:0] mem_block1_dense_loa_reg_261;
wire   [31:0] grp_fu_145_p2;
reg   [31:0] tmp_1_reg_266;
wire   [31:0] storemerge_fu_213_p3;
reg   [31:0] storemerge_reg_273;
wire   [0:0] exitcond_fu_220_p2;
reg   [0:0] exitcond_reg_278;
wire    ap_CS_fsm_pp1_stage0;
wire    ap_block_state13_pp1_stage0_iter0;
wire    ap_block_state14_pp1_stage0_iter1;
wire    ap_block_pp1_stage0_11001;
wire   [12:0] i_3_fu_226_p2;
reg    ap_enable_reg_pp1_iter0;
wire   [63:0] tmp_4_fu_232_p1;
reg   [63:0] tmp_4_reg_287;
wire    ap_block_pp0_stage0_subdone;
reg    ap_condition_pp0_exit_iter0_state2;
reg    ap_enable_reg_pp0_iter1;
wire    ap_block_pp0_stage1_subdone;
reg    ap_enable_reg_pp0_iter2;
reg    ap_enable_reg_pp0_iter3;
reg    ap_enable_reg_pp0_iter4;
wire    ap_CS_fsm_state12;
wire    ap_block_pp1_stage0_subdone;
reg    ap_condition_pp1_exit_iter0_state13;
reg    ap_enable_reg_pp1_iter1;
reg   [12:0] ap_phi_mux_i_phi_fu_127_p4;
wire    ap_block_pp0_stage0;
wire   [63:0] tmp_fu_166_p1;
wire    ap_block_pp1_stage0;
wire    ap_block_pp0_stage1;
wire   [31:0] tmp_1_to_int_fu_172_p1;
wire   [7:0] tmp_2_fu_175_p4;
wire   [22:0] tmp_6_fu_185_p1;
wire   [0:0] notrhs_fu_195_p2;
wire   [0:0] notlhs_fu_189_p2;
wire   [0:0] tmp_7_fu_201_p2;
wire   [0:0] tmp_8_fu_149_p2;
wire   [0:0] tmp_9_fu_207_p2;
wire    ap_block_pp0_stage0_00001;
wire    ap_CS_fsm_state15;
reg   [5:0] ap_NS_fsm;
reg    ap_idle_pp0;
wire    ap_enable_pp0;
reg    ap_idle_pp1;
wire    ap_enable_pp1;

// power-on initialization
initial begin
#0 ap_CS_fsm = 6'd1;
#0 ap_enable_reg_pp0_iter0 = 1'b0;
#0 ap_enable_reg_pp1_iter0 = 1'b0;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter3 = 1'b0;
#0 ap_enable_reg_pp0_iter4 = 1'b0;
#0 ap_enable_reg_pp1_iter1 = 1'b0;
end

add_bias_and_relu_flatten2_CONTROL_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_CONTROL_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_CONTROL_DATA_WIDTH ))
add_bias_and_relu_flatten2_CONTROL_s_axi_U(
    .AWVALID(s_axi_CONTROL_AWVALID),
    .AWREADY(s_axi_CONTROL_AWREADY),
    .AWADDR(s_axi_CONTROL_AWADDR),
    .WVALID(s_axi_CONTROL_WVALID),
    .WREADY(s_axi_CONTROL_WREADY),
    .WDATA(s_axi_CONTROL_WDATA),
    .WSTRB(s_axi_CONTROL_WSTRB),
    .ARVALID(s_axi_CONTROL_ARVALID),
    .ARREADY(s_axi_CONTROL_ARREADY),
    .ARADDR(s_axi_CONTROL_ARADDR),
    .RVALID(s_axi_CONTROL_RVALID),
    .RREADY(s_axi_CONTROL_RREADY),
    .RDATA(s_axi_CONTROL_RDATA),
    .RRESP(s_axi_CONTROL_RRESP),
    .BVALID(s_axi_CONTROL_BVALID),
    .BREADY(s_axi_CONTROL_BREADY),
    .BRESP(s_axi_CONTROL_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .ap_start(ap_start),
    .interrupt(interrupt),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_idle(ap_idle)
);

add_bias_and_relu_flatten2_INPUT_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_INPUT_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_INPUT_DATA_WIDTH ))
add_bias_and_relu_flatten2_INPUT_s_axi_U(
    .AWVALID(s_axi_INPUT_AWVALID),
    .AWREADY(s_axi_INPUT_AWREADY),
    .AWADDR(s_axi_INPUT_AWADDR),
    .WVALID(s_axi_INPUT_WVALID),
    .WREADY(s_axi_INPUT_WREADY),
    .WDATA(s_axi_INPUT_WDATA),
    .WSTRB(s_axi_INPUT_WSTRB),
    .ARVALID(s_axi_INPUT_ARVALID),
    .ARREADY(s_axi_INPUT_ARREADY),
    .ARADDR(s_axi_INPUT_ARADDR),
    .RVALID(s_axi_INPUT_RVALID),
    .RREADY(s_axi_INPUT_RREADY),
    .RDATA(s_axi_INPUT_RDATA),
    .RRESP(s_axi_INPUT_RRESP),
    .BVALID(s_axi_INPUT_BVALID),
    .BREADY(s_axi_INPUT_BREADY),
    .BRESP(s_axi_INPUT_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .mem_block1_dense_address0(mem_block1_dense_address0),
    .mem_block1_dense_ce0(mem_block1_dense_ce0),
    .mem_block1_dense_we0(mem_block1_dense_we0),
    .mem_block1_dense_d0(storemerge_reg_273),
    .mem_block1_dense_q0(mem_block1_dense_q0)
);

add_bias_and_relu_flatten2_OUTPUT_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_OUTPUT_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_OUTPUT_DATA_WIDTH ))
add_bias_and_relu_flatten2_OUTPUT_s_axi_U(
    .AWVALID(s_axi_OUTPUT_AWVALID),
    .AWREADY(s_axi_OUTPUT_AWREADY),
    .AWADDR(s_axi_OUTPUT_AWADDR),
    .WVALID(s_axi_OUTPUT_WVALID),
    .WREADY(s_axi_OUTPUT_WREADY),
    .WDATA(s_axi_OUTPUT_WDATA),
    .WSTRB(s_axi_OUTPUT_WSTRB),
    .ARVALID(s_axi_OUTPUT_ARVALID),
    .ARREADY(s_axi_OUTPUT_ARREADY),
    .ARADDR(s_axi_OUTPUT_ARADDR),
    .RVALID(s_axi_OUTPUT_RVALID),
    .RREADY(s_axi_OUTPUT_RREADY),
    .RDATA(s_axi_OUTPUT_RDATA),
    .RRESP(s_axi_OUTPUT_RRESP),
    .BVALID(s_axi_OUTPUT_BVALID),
    .BREADY(s_axi_OUTPUT_BREADY),
    .BRESP(s_axi_OUTPUT_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .memblock1_dense_address0(memblock1_dense_address0),
    .memblock1_dense_ce0(memblock1_dense_ce0),
    .memblock1_dense_we0(memblock1_dense_we0),
    .memblock1_dense_d0(mem_block1_dense_q0)
);

add_bias_and_relu_flatten2_parameter_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_PARAMETER_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_PARAMETER_DATA_WIDTH ))
add_bias_and_relu_flatten2_parameter_s_axi_U(
    .AWVALID(s_axi_parameter_AWVALID),
    .AWREADY(s_axi_parameter_AWREADY),
    .AWADDR(s_axi_parameter_AWADDR),
    .WVALID(s_axi_parameter_WVALID),
    .WREADY(s_axi_parameter_WREADY),
    .WDATA(s_axi_parameter_WDATA),
    .WSTRB(s_axi_parameter_WSTRB),
    .ARVALID(s_axi_parameter_ARVALID),
    .ARREADY(s_axi_parameter_ARREADY),
    .ARADDR(s_axi_parameter_ARADDR),
    .RVALID(s_axi_parameter_RVALID),
    .RREADY(s_axi_parameter_RREADY),
    .RDATA(s_axi_parameter_RDATA),
    .RRESP(s_axi_parameter_RRESP),
    .BVALID(s_axi_parameter_BVALID),
    .BREADY(s_axi_parameter_BREADY),
    .BRESP(s_axi_parameter_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .bd2_address0(bd2_address0),
    .bd2_ce0(bd2_ce0),
    .bd2_q0(bd2_q0)
);

add_bias_and_relubkb #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
add_bias_and_relubkb_U1(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .din0(mem_block1_dense_loa_reg_261),
    .din1(bd2_load_reg_256),
    .ce(1'b1),
    .dout(grp_fu_145_p2)
);

add_bias_and_relucud #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 1 ))
add_bias_and_relucud_U2(
    .din0(tmp_1_reg_266),
    .din1(32'd0),
    .opcode(5'd4),
    .dout(tmp_8_fu_149_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter0 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_condition_pp0_exit_iter0_state2) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_enable_reg_pp0_iter0 <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            ap_enable_reg_pp0_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage1_subdone) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
            if ((1'b1 == ap_condition_pp0_exit_iter0_state2)) begin
                ap_enable_reg_pp0_iter1 <= (1'b1 ^ ap_condition_pp0_exit_iter0_state2);
            end else if ((1'b1 == 1'b1)) begin
                ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
            end
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage1_subdone) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter3 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage1_subdone) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
            ap_enable_reg_pp0_iter3 <= ap_enable_reg_pp0_iter2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter4 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage1_subdone) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
            ap_enable_reg_pp0_iter4 <= ap_enable_reg_pp0_iter3;
        end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            ap_enable_reg_pp0_iter4 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp1_iter0 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp1_stage0_subdone) & (1'b1 == ap_condition_pp1_exit_iter0_state13) & (1'b1 == ap_CS_fsm_pp1_stage0))) begin
            ap_enable_reg_pp1_iter0 <= 1'b0;
        end else if ((1'b1 == ap_CS_fsm_state12)) begin
            ap_enable_reg_pp1_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp1_iter1 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp1_stage0_subdone) & (1'b1 == ap_condition_pp1_exit_iter0_state13))) begin
            ap_enable_reg_pp1_iter1 <= (1'b1 ^ ap_condition_pp1_exit_iter0_state13);
        end else if ((1'b0 == ap_block_pp1_stage0_subdone)) begin
            ap_enable_reg_pp1_iter1 <= ap_enable_reg_pp1_iter0;
        end else if ((1'b1 == ap_CS_fsm_state12)) begin
            ap_enable_reg_pp1_iter1 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        i_1_reg_134 <= 13'd0;
    end else if (((1'b0 == ap_block_pp1_stage0_11001) & (exitcond_fu_220_p2 == 1'd0) & (ap_enable_reg_pp1_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp1_stage0))) begin
        i_1_reg_134 <= i_3_fu_226_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (exitcond1_reg_237 == 1'd0))) begin
        i_reg_123 <= i_2_reg_241;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_reg_123 <= 13'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        ap_reg_pp0_iter1_exitcond1_reg_237 <= exitcond1_reg_237;
        ap_reg_pp0_iter1_mem_block1_dense_add_reg_251 <= mem_block1_dense_add_reg_251;
        ap_reg_pp0_iter2_exitcond1_reg_237 <= ap_reg_pp0_iter1_exitcond1_reg_237;
        ap_reg_pp0_iter2_mem_block1_dense_add_reg_251 <= ap_reg_pp0_iter1_mem_block1_dense_add_reg_251;
        ap_reg_pp0_iter3_exitcond1_reg_237 <= ap_reg_pp0_iter2_exitcond1_reg_237;
        ap_reg_pp0_iter3_mem_block1_dense_add_reg_251 <= ap_reg_pp0_iter2_mem_block1_dense_add_reg_251;
        ap_reg_pp0_iter4_exitcond1_reg_237 <= ap_reg_pp0_iter3_exitcond1_reg_237;
        ap_reg_pp0_iter4_mem_block1_dense_add_reg_251 <= ap_reg_pp0_iter3_mem_block1_dense_add_reg_251;
        exitcond1_reg_237 <= exitcond1_fu_154_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (1'b1 == ap_CS_fsm_pp0_stage1) & (exitcond1_reg_237 == 1'd0))) begin
        bd2_load_reg_256 <= bd2_q0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp1_stage0_11001) & (1'b1 == ap_CS_fsm_pp1_stage0))) begin
        exitcond_reg_278 <= exitcond_fu_220_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        i_2_reg_241 <= i_2_fu_160_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (exitcond1_fu_154_p2 == 1'd0))) begin
        mem_block1_dense_add_reg_251 <= tmp_fu_166_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (exitcond1_reg_237 == 1'd0))) begin
        mem_block1_dense_loa_reg_261 <= mem_block1_dense_q0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_reg_pp0_iter3_exitcond1_reg_237 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        storemerge_reg_273 <= storemerge_fu_213_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_reg_pp0_iter2_exitcond1_reg_237 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        tmp_1_reg_266 <= grp_fu_145_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp1_stage0_11001) & (exitcond_fu_220_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp1_stage0))) begin
        tmp_4_reg_287[12 : 0] <= tmp_4_fu_232_p1[12 : 0];
    end
end

always @ (*) begin
    if ((exitcond1_fu_154_p2 == 1'd1)) begin
        ap_condition_pp0_exit_iter0_state2 = 1'b1;
    end else begin
        ap_condition_pp0_exit_iter0_state2 = 1'b0;
    end
end

always @ (*) begin
    if ((exitcond_fu_220_p2 == 1'd1)) begin
        ap_condition_pp1_exit_iter0_state13 = 1'b1;
    end else begin
        ap_condition_pp1_exit_iter0_state13 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state15)) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter4 == 1'b0) & (ap_enable_reg_pp0_iter3 == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp1_iter1 == 1'b0) & (ap_enable_reg_pp1_iter0 == 1'b0))) begin
        ap_idle_pp1 = 1'b1;
    end else begin
        ap_idle_pp1 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (exitcond1_reg_237 == 1'd0))) begin
        ap_phi_mux_i_phi_fu_127_p4 = i_2_reg_241;
    end else begin
        ap_phi_mux_i_phi_fu_127_p4 = i_reg_123;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state15)) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        bd2_ce0 = 1'b1;
    end else begin
        bd2_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp1_stage0) & (ap_enable_reg_pp1_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp1_stage0))) begin
        mem_block1_dense_address0 = tmp_4_fu_232_p1;
    end else if (((1'b0 == ap_block_pp0_stage1) & (ap_enable_reg_pp0_iter4 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
        mem_block1_dense_address0 = ap_reg_pp0_iter4_mem_block1_dense_add_reg_251;
    end else if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        mem_block1_dense_address0 = tmp_fu_166_p1;
    end else begin
        mem_block1_dense_address0 = 'bx;
    end
end

always @ (*) begin
    if ((((1'b0 == ap_block_pp1_stage0_11001) & (ap_enable_reg_pp1_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp1_stage0)) | ((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter4 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1)) | ((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001)))) begin
        mem_block1_dense_ce0 = 1'b1;
    end else begin
        mem_block1_dense_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter4 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (ap_reg_pp0_iter4_exitcond1_reg_237 == 1'd0))) begin
        mem_block1_dense_we0 = 1'b1;
    end else begin
        mem_block1_dense_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp1_stage0_11001) & (ap_enable_reg_pp1_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp1_stage0))) begin
        memblock1_dense_ce0 = 1'b1;
    end else begin
        memblock1_dense_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp1_stage0_11001) & (exitcond_reg_278 == 1'd0) & (ap_enable_reg_pp1_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp1_stage0))) begin
        memblock1_dense_we0 = 1'b1;
    end else begin
        memblock1_dense_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (exitcond1_fu_154_p2 == 1'd1)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else if (((ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (exitcond1_fu_154_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state12;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((~((ap_enable_reg_pp0_iter3 == 1'b0) & (1'b0 == ap_block_pp0_stage1_subdone) & (ap_enable_reg_pp0_iter4 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1)) & (1'b0 == ap_block_pp0_stage1_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else if (((ap_enable_reg_pp0_iter3 == 1'b0) & (1'b0 == ap_block_pp0_stage1_subdone) & (ap_enable_reg_pp0_iter4 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage1))) begin
                ap_NS_fsm = ap_ST_fsm_state12;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_state12 : begin
            ap_NS_fsm = ap_ST_fsm_pp1_stage0;
        end
        ap_ST_fsm_pp1_stage0 : begin
            if (~((1'b0 == ap_block_pp1_stage0_subdone) & (exitcond_fu_220_p2 == 1'd1) & (ap_enable_reg_pp1_iter0 == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_pp1_stage0;
            end else if (((1'b0 == ap_block_pp1_stage0_subdone) & (exitcond_fu_220_p2 == 1'd1) & (ap_enable_reg_pp1_iter0 == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state15;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp1_stage0;
            end
        end
        ap_ST_fsm_state15 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_pp1_stage0 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state12 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state15 = ap_CS_fsm[32'd5];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_00001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp1_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp1_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp1_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_state10_pp0_stage0_iter4 = ~(1'b1 == 1'b1);

assign ap_block_state11_pp0_stage1_iter4 = ~(1'b1 == 1'b1);

assign ap_block_state13_pp1_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state14_pp1_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state2_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage1_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state4_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state5_pp0_stage1_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state6_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state7_pp0_stage1_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state8_pp0_stage0_iter3 = ~(1'b1 == 1'b1);

assign ap_block_state9_pp0_stage1_iter3 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_enable_pp1 = (ap_idle_pp1 ^ 1'b1);

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign bd2_address0 = tmp_fu_166_p1;

assign exitcond1_fu_154_p2 = ((ap_phi_mux_i_phi_fu_127_p4 == 13'd4096) ? 1'b1 : 1'b0);

assign exitcond_fu_220_p2 = ((i_1_reg_134 == 13'd4096) ? 1'b1 : 1'b0);

assign i_2_fu_160_p2 = (ap_phi_mux_i_phi_fu_127_p4 + 13'd1);

assign i_3_fu_226_p2 = (i_1_reg_134 + 13'd1);

assign memblock1_dense_address0 = tmp_4_reg_287;

assign notlhs_fu_189_p2 = ((tmp_2_fu_175_p4 != 8'd255) ? 1'b1 : 1'b0);

assign notrhs_fu_195_p2 = ((tmp_6_fu_185_p1 == 23'd0) ? 1'b1 : 1'b0);

assign storemerge_fu_213_p3 = ((tmp_9_fu_207_p2[0:0] === 1'b1) ? 32'd0 : tmp_1_reg_266);

assign tmp_1_to_int_fu_172_p1 = tmp_1_reg_266;

assign tmp_2_fu_175_p4 = {{tmp_1_to_int_fu_172_p1[30:23]}};

assign tmp_4_fu_232_p1 = i_1_reg_134;

assign tmp_6_fu_185_p1 = tmp_1_to_int_fu_172_p1[22:0];

assign tmp_7_fu_201_p2 = (notrhs_fu_195_p2 | notlhs_fu_189_p2);

assign tmp_9_fu_207_p2 = (tmp_8_fu_149_p2 & tmp_7_fu_201_p2);

assign tmp_fu_166_p1 = ap_phi_mux_i_phi_fu_127_p4;

always @ (posedge ap_clk) begin
    tmp_4_reg_287[63:13] <= 51'b000000000000000000000000000000000000000000000000000;
end

endmodule //add_bias_and_relu_flatten2