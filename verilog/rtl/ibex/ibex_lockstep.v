module ibex_lockstep (
	clk_i,
	rst_ni,
	hart_id_i,
	boot_addr_i,
	instr_req_i,
	instr_gnt_i,
	instr_rvalid_i,
	instr_addr_i,
	instr_rdata_i,
	instr_rdata_intg_i,
	instr_err_i,
	data_req_i,
	data_gnt_i,
	data_rvalid_i,
	data_we_i,
	data_be_i,
	data_addr_i,
	data_wdata_i,
	data_wdata_intg_o,
	data_rdata_i,
	data_rdata_intg_i,
	data_err_i,
	dummy_instr_id_i,
	rf_raddr_a_i,
	rf_raddr_b_i,
	rf_waddr_wb_i,
	rf_we_wb_i,
	rf_wdata_wb_ecc_i,
	rf_rdata_a_ecc_i,
	rf_rdata_b_ecc_i,
	ic_tag_req_i,
	ic_tag_write_i,
	ic_tag_addr_i,
	ic_tag_wdata_i,
	ic_tag_rdata_i,
	ic_data_req_i,
	ic_data_write_i,
	ic_data_addr_i,
	ic_data_wdata_i,
	ic_data_rdata_i,
	irq_software_i,
	irq_timer_i,
	irq_external_i,
	irq_fast_i,
	irq_nm_i,
	irq_pending_i,
	debug_req_i,
	crash_dump_i,
	fetch_enable_i,
	alert_minor_o,
	alert_major_o,
	core_busy_i,
	test_en_i,
	scan_rst_ni
);
	parameter [31:0] LockstepOffset = 2;
	parameter [0:0] PMPEnable = 1'b0;
	parameter [31:0] PMPGranularity = 0;
	parameter [31:0] PMPNumRegions = 4;
	parameter [31:0] MHPMCounterNum = 0;
	parameter [31:0] MHPMCounterWidth = 40;
	parameter [0:0] RV32E = 1'b0;
	parameter integer RV32M = 32'sd2;
	parameter integer RV32B = 32'sd0;
	parameter [0:0] BranchTargetALU = 1'b0;
	parameter [0:0] WritebackStage = 1'b0;
	parameter [0:0] ICache = 1'b0;
	parameter [0:0] ICacheECC = 1'b0;
	localparam [31:0] ibex_pkg_BUS_SIZE = 32;
	parameter [31:0] BusSizeECC = ibex_pkg_BUS_SIZE;
	localparam [31:0] ibex_pkg_ADDR_W = 32;
	localparam [31:0] ibex_pkg_IC_LINE_SIZE = 64;
	localparam [31:0] ibex_pkg_IC_LINE_BYTES = 8;
	localparam [31:0] ibex_pkg_IC_NUM_WAYS = 2;
	localparam [31:0] ibex_pkg_IC_SIZE_BYTES = 4096;
	localparam [31:0] ibex_pkg_IC_NUM_LINES = (ibex_pkg_IC_SIZE_BYTES / ibex_pkg_IC_NUM_WAYS) / ibex_pkg_IC_LINE_BYTES;
	localparam [31:0] ibex_pkg_IC_INDEX_W = $clog2(ibex_pkg_IC_NUM_LINES);
	localparam [31:0] ibex_pkg_IC_LINE_W = 3;
	localparam [31:0] ibex_pkg_IC_TAG_SIZE = ((ibex_pkg_ADDR_W - ibex_pkg_IC_INDEX_W) - ibex_pkg_IC_LINE_W) + 1;
	parameter [31:0] TagSizeECC = ibex_pkg_IC_TAG_SIZE;
	parameter [31:0] LineSizeECC = ibex_pkg_IC_LINE_SIZE;
	parameter [0:0] BranchPredictor = 1'b0;
	parameter [0:0] DbgTriggerEn = 1'b0;
	parameter [31:0] DbgHwBreakNum = 1;
	parameter [0:0] ResetAll = 1'b0;
	localparam signed [31:0] ibex_pkg_LfsrWidth = 32;
	localparam [31:0] ibex_pkg_RndCnstLfsrSeedDefault = 32'hac533bf4;
	parameter [31:0] RndCnstLfsrSeed = ibex_pkg_RndCnstLfsrSeedDefault;
	localparam [159:0] ibex_pkg_RndCnstLfsrPermDefault = 160'h1e35ecba467fd1b12e958152c04fa43878a8daed;
	parameter [159:0] RndCnstLfsrPerm = ibex_pkg_RndCnstLfsrPermDefault;
	parameter [0:0] SecureIbex = 1'b0;
	parameter [0:0] DummyInstructions = 1'b0;
	parameter [0:0] RegFileECC = 1'b0;
	parameter [31:0] RegFileDataWidth = 32;
	parameter [31:0] DmHaltAddr = 32'h1a110800;
	parameter [31:0] DmExceptionAddr = 32'h1a110808;
	input wire clk_i;
	input wire rst_ni;
	input wire [31:0] hart_id_i;
	input wire [31:0] boot_addr_i;
	input wire instr_req_i;
	input wire instr_gnt_i;
	input wire instr_rvalid_i;
	input wire [31:0] instr_addr_i;
	input wire [31:0] instr_rdata_i;
	input wire [6:0] instr_rdata_intg_i;
	input wire instr_err_i;
	input wire data_req_i;
	input wire data_gnt_i;
	input wire data_rvalid_i;
	input wire data_we_i;
	input wire [3:0] data_be_i;
	input wire [31:0] data_addr_i;
	input wire [31:0] data_wdata_i;
	output wire [6:0] data_wdata_intg_o;
	input wire [31:0] data_rdata_i;
	input wire [6:0] data_rdata_intg_i;
	input wire data_err_i;
	input wire dummy_instr_id_i;
	input wire [4:0] rf_raddr_a_i;
	input wire [4:0] rf_raddr_b_i;
	input wire [4:0] rf_waddr_wb_i;
	input wire rf_we_wb_i;
	input wire [RegFileDataWidth - 1:0] rf_wdata_wb_ecc_i;
	input wire [RegFileDataWidth - 1:0] rf_rdata_a_ecc_i;
	input wire [RegFileDataWidth - 1:0] rf_rdata_b_ecc_i;
	input wire [1:0] ic_tag_req_i;
	input wire ic_tag_write_i;
	input wire [ibex_pkg_IC_INDEX_W - 1:0] ic_tag_addr_i;
	input wire [TagSizeECC - 1:0] ic_tag_wdata_i;
	input wire [(ibex_pkg_IC_NUM_WAYS * TagSizeECC) - 1:0] ic_tag_rdata_i;
	input wire [1:0] ic_data_req_i;
	input wire ic_data_write_i;
	input wire [ibex_pkg_IC_INDEX_W - 1:0] ic_data_addr_i;
	input wire [LineSizeECC - 1:0] ic_data_wdata_i;
	input wire [(ibex_pkg_IC_NUM_WAYS * LineSizeECC) - 1:0] ic_data_rdata_i;
	input wire irq_software_i;
	input wire irq_timer_i;
	input wire irq_external_i;
	input wire [14:0] irq_fast_i;
	input wire irq_nm_i;
	input wire irq_pending_i;
	input wire debug_req_i;
	input wire [127:0] crash_dump_i;
	input wire fetch_enable_i;
	output wire alert_minor_o;
	output wire alert_major_o;
	input wire core_busy_i;
	input wire test_en_i;
	input wire scan_rst_ni;
	localparam [31:0] LockstepOffsetW = $clog2(LockstepOffset);
	localparam [31:0] OutputsOffset = LockstepOffset + 1;
	wire [LockstepOffsetW - 1:0] rst_shadow_cnt_d;
	reg [LockstepOffsetW - 1:0] rst_shadow_cnt_q;
	wire rst_shadow_set_d;
	reg rst_shadow_set_q;
	wire rst_shadow_n;
	reg enable_cmp_q;
	function automatic [LockstepOffsetW - 1:0] sv2v_cast_3B624;
		input reg [LockstepOffsetW - 1:0] inp;
		sv2v_cast_3B624 = inp;
	endfunction
	assign rst_shadow_set_d = rst_shadow_cnt_q == sv2v_cast_3B624(LockstepOffset - 1);
	function automatic signed [LockstepOffsetW - 1:0] sv2v_cast_3B624_signed;
		input reg signed [LockstepOffsetW - 1:0] inp;
		sv2v_cast_3B624_signed = inp;
	endfunction
	assign rst_shadow_cnt_d = (rst_shadow_set_d ? rst_shadow_cnt_q : rst_shadow_cnt_q + sv2v_cast_3B624_signed(1));
	always @(posedge clk_i or negedge rst_ni)
		if (!rst_ni) begin
			rst_shadow_cnt_q <= 1'sb0;
			rst_shadow_set_q <= 1'sb0;
			enable_cmp_q <= 1'sb0;
		end
		else begin
			rst_shadow_cnt_q <= rst_shadow_cnt_d;
			rst_shadow_set_q <= rst_shadow_set_d;
			enable_cmp_q <= rst_shadow_set_q;
		end
	assign rst_shadow_n = (test_en_i ? scan_rst_ni : rst_shadow_set_q);
	reg [((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? (LockstepOffset * (((70 + RegFileDataWidth) + RegFileDataWidth) + 21)) - 1 : (LockstepOffset * (1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))) + (((70 + RegFileDataWidth) + RegFileDataWidth) + 19)):((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 0 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 20)] shadow_inputs_q;
	wire [((70 + RegFileDataWidth) + RegFileDataWidth) + 20:0] shadow_inputs_in;
	reg [6:0] instr_rdata_intg_q;
	reg [6:0] data_rdata_intg_q;
	reg [(LockstepOffset * TagSizeECC) - 1:0] shadow_tag_rdata_q [0:1];
	reg [(LockstepOffset * LineSizeECC) - 1:0] shadow_data_rdata_q [0:1];
	assign shadow_inputs_in[70 + (RegFileDataWidth + (RegFileDataWidth + 20))] = instr_gnt_i;
	assign shadow_inputs_in[69 + (RegFileDataWidth + (RegFileDataWidth + 20))] = instr_rvalid_i;
	assign shadow_inputs_in[68 + (RegFileDataWidth + (RegFileDataWidth + 20))-:((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (36 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (36 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((36 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)] = instr_rdata_i;
	assign shadow_inputs_in[36 + (RegFileDataWidth + (RegFileDataWidth + 20))] = instr_err_i;
	assign shadow_inputs_in[35 + (RegFileDataWidth + (RegFileDataWidth + 20))] = data_gnt_i;
	assign shadow_inputs_in[34 + (RegFileDataWidth + (RegFileDataWidth + 20))] = data_rvalid_i;
	assign shadow_inputs_in[33 + (RegFileDataWidth + (RegFileDataWidth + 20))-:((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (1 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (1 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((1 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)] = data_rdata_i;
	assign shadow_inputs_in[1 + (RegFileDataWidth + (RegFileDataWidth + 20))] = data_err_i;
	assign shadow_inputs_in[RegFileDataWidth + (RegFileDataWidth + 20)-:((RegFileDataWidth + (RegFileDataWidth + 20)) >= (RegFileDataWidth + 21) ? ((RegFileDataWidth + (RegFileDataWidth + 20)) - (RegFileDataWidth + 21)) + 1 : ((RegFileDataWidth + 21) - (RegFileDataWidth + (RegFileDataWidth + 20))) + 1)] = rf_rdata_a_ecc_i;
	assign shadow_inputs_in[RegFileDataWidth + 20-:((RegFileDataWidth + 20) >= 21 ? RegFileDataWidth : 22 - (RegFileDataWidth + 20))] = rf_rdata_b_ecc_i;
	assign shadow_inputs_in[20] = irq_software_i;
	assign shadow_inputs_in[19] = irq_timer_i;
	assign shadow_inputs_in[18] = irq_external_i;
	assign shadow_inputs_in[17-:15] = irq_fast_i;
	assign shadow_inputs_in[2] = irq_nm_i;
	assign shadow_inputs_in[1] = debug_req_i;
	assign shadow_inputs_in[0] = fetch_enable_i;
	function automatic [((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20)) - 1:0] sv2v_cast_5CD9E;
		input reg [((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20)) - 1:0] inp;
		sv2v_cast_5CD9E = inp;
	endfunction
	function automatic [TagSizeECC - 1:0] sv2v_cast_CA15E;
		input reg [TagSizeECC - 1:0] inp;
		sv2v_cast_CA15E = inp;
	endfunction
	function automatic [LineSizeECC - 1:0] sv2v_cast_B1C65;
		input reg [LineSizeECC - 1:0] inp;
		sv2v_cast_B1C65 = inp;
	endfunction
	always @(posedge clk_i or negedge rst_ni)
		if (!rst_ni) begin
			instr_rdata_intg_q <= 1'sb0;
			data_rdata_intg_q <= 1'sb0;
			begin : sv2v_autoblock_1
				reg [31:0] i;
				for (i = 0; i < LockstepOffset; i = i + 1)
					begin
						shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 0 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 20) + (i * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20)))+:((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))] <= sv2v_cast_5CD9E(1'sb0);
						shadow_tag_rdata_q[i] <= {LockstepOffset {sv2v_cast_CA15E(0)}};
						shadow_data_rdata_q[i] <= {LockstepOffset {sv2v_cast_B1C65(0)}};
					end
			end
		end
		else begin
			instr_rdata_intg_q <= instr_rdata_intg_i;
			data_rdata_intg_q <= data_rdata_intg_i;
			begin : sv2v_autoblock_2
				reg [31:0] i;
				for (i = 0; i < (LockstepOffset - 1); i = i + 1)
					begin
						shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 0 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 20) + (i * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20)))+:((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))] <= shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 0 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 20) + ((i + 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20)))+:((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))];
						shadow_tag_rdata_q[i] <= shadow_tag_rdata_q[i + 1];
						shadow_data_rdata_q[i] <= shadow_data_rdata_q[i + 1];
					end
			end
			shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 0 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 20) + ((LockstepOffset - 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20)))+:((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))] <= shadow_inputs_in;
			shadow_tag_rdata_q[LockstepOffset - 1] <= ic_tag_rdata_i;
			shadow_data_rdata_q[LockstepOffset - 1] <= ic_data_rdata_i;
		end
	wire bus_intg_err;
	wire [1:0] instr_intg_err;
	wire [1:0] data_intg_err;
	wire [31:0] unused_wdata;
	prim_secded_39_32_dec u_instr_intg_dec(
		.data_i({instr_rdata_intg_q, shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((LockstepOffset - 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))) + ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 68 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) : ((((LockstepOffset - 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))) + ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 68 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20))))) + ((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (36 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (36 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((36 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)) - 1)-:((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (36 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (36 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((36 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)]}),
		.data_o(),
		.syndrome_o(),
		.err_o(instr_intg_err)
	);
	prim_secded_39_32_dec u_data_intg_dec(
		.data_i({data_rdata_intg_q, shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((LockstepOffset - 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))) + ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 33 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) : ((((LockstepOffset - 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))) + ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 33 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20))))) + ((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (1 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (1 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((1 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)) - 1)-:((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (1 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (1 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((1 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)]}),
		.data_o(),
		.syndrome_o(),
		.err_o(data_intg_err)
	);
	assign bus_intg_err = (shadow_inputs_q[((LockstepOffset - 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))) + ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 69 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (69 + (RegFileDataWidth + (RegFileDataWidth + 20))))] & |instr_intg_err) | (shadow_inputs_q[((LockstepOffset - 1) * ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((70 + RegFileDataWidth) + RegFileDataWidth) + 21 : 1 - (((70 + RegFileDataWidth) + RegFileDataWidth) + 20))) + ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 34 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (34 + (RegFileDataWidth + (RegFileDataWidth + 20))))] & |data_intg_err);
	prim_secded_39_32_enc u_data_gen(
		.data_i(data_wdata_i),
		.data_o({data_wdata_intg_o, unused_wdata})
	);
	reg [(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (OutputsOffset * ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130)) - 1 : (OutputsOffset * (1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129))) + ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 128)):(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? 0 : (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129)] core_outputs_q;
	wire [(((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129:0] core_outputs_in;
	wire [(((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129:0] shadow_outputs_d;
	reg [(((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129:0] shadow_outputs_q;
	assign core_outputs_in[120 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))] = instr_req_i;
	assign core_outputs_in[119 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((119 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (87 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((119 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (87 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((87 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (119 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)] = instr_addr_i;
	assign core_outputs_in[87 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))] = data_req_i;
	assign core_outputs_in[86 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))] = data_we_i;
	assign core_outputs_in[85 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((85 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (81 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((85 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (85 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)] = data_be_i;
	assign core_outputs_in[81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((81 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (49 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)] = data_addr_i;
	assign core_outputs_in[49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((49 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (17 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (17 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((17 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)] = data_wdata_i;
	assign core_outputs_in[17 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))] = dummy_instr_id_i;
	assign core_outputs_in[16 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((16 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (11 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((16 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (16 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)] = rf_raddr_a_i;
	assign core_outputs_in[11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((11 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (6 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)] = rf_raddr_b_i;
	assign core_outputs_in[6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((6 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (1 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (1 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((1 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)] = rf_waddr_wb_i;
	assign core_outputs_in[1 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))] = rf_we_wb_i;
	assign core_outputs_in[RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))-:((RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))) >= (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))) ? ((RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))) + 1 : ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) - (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) + 1)] = rf_wdata_wb_ecc_i;
	assign core_outputs_in[ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))-:((3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))) >= (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))) ? ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) - (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) + 1 : ((1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))) + 1)] = ic_tag_req_i;
	assign core_outputs_in[1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))] = ic_tag_write_i;
	assign core_outputs_in[ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))-:((ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))) >= (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))) ? ((ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))) - (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))) + 1 : ((TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))) - (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))) + 1)] = ic_tag_addr_i;
	assign core_outputs_in[TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))-:((TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))) >= (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))) ? ((TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))) + 1 : ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))) - (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))) + 1)] = ic_tag_wdata_i;
	assign core_outputs_in[ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))-:((3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))) >= (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))) ? ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))) - (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))) + 1 : ((1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))) + 1)] = ic_data_req_i;
	assign core_outputs_in[1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))] = ic_data_write_i;
	assign core_outputs_in[ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)-:((ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)) >= (LineSizeECC + 130) ? ((ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)) - (LineSizeECC + 130)) + 1 : ((LineSizeECC + 130) - (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))) + 1)] = ic_data_addr_i;
	assign core_outputs_in[LineSizeECC + 129-:((LineSizeECC + 129) >= 130 ? LineSizeECC : 131 - (LineSizeECC + 129))] = ic_data_wdata_i;
	assign core_outputs_in[129] = irq_pending_i;
	assign core_outputs_in[128-:128] = crash_dump_i;
	assign core_outputs_in[0] = core_busy_i;
	always @(posedge clk_i) begin
		begin : sv2v_autoblock_3
			reg [31:0] i;
			for (i = 0; i < (OutputsOffset - 1); i = i + 1)
				core_outputs_q[(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? 0 : (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) + (i * (((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130 : 1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129)))+:(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130 : 1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129))] <= core_outputs_q[(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? 0 : (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) + ((i + 1) * (((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130 : 1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129)))+:(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130 : 1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129))];
		end
		core_outputs_q[(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? 0 : (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) + ((OutputsOffset - 1) * (((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130 : 1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129)))+:(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130 : 1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129))] <= core_outputs_in;
	end
	wire shadow_alert_minor;
	wire shadow_alert_major;
	ibex_core #(
		.PMPEnable(PMPEnable),
		.PMPGranularity(PMPGranularity),
		.PMPNumRegions(PMPNumRegions),
		.MHPMCounterNum(MHPMCounterNum),
		.MHPMCounterWidth(MHPMCounterWidth),
		.RV32E(RV32E),
		.RV32M(RV32M),
		.RV32B(RV32B),
		.BranchTargetALU(BranchTargetALU),
		.ICache(ICache),
		.ICacheECC(ICacheECC),
		.BusSizeECC(BusSizeECC),
		.TagSizeECC(TagSizeECC),
		.LineSizeECC(LineSizeECC),
		.BranchPredictor(BranchPredictor),
		.DbgTriggerEn(DbgTriggerEn),
		.DbgHwBreakNum(DbgHwBreakNum),
		.WritebackStage(WritebackStage),
		.ResetAll(ResetAll),
		.RndCnstLfsrSeed(RndCnstLfsrSeed),
		.RndCnstLfsrPerm(RndCnstLfsrPerm),
		.SecureIbex(SecureIbex),
		.DummyInstructions(DummyInstructions),
		.RegFileECC(RegFileECC),
		.RegFileDataWidth(RegFileDataWidth),
		.DmHaltAddr(DmHaltAddr),
		.DmExceptionAddr(DmExceptionAddr)
	) u_shadow_core(
		.clk_i(clk_i),
		.rst_ni(rst_shadow_n),
		.hart_id_i(hart_id_i),
		.boot_addr_i(boot_addr_i),
		.instr_req_o(shadow_outputs_d[120 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))]),
		.instr_gnt_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 70 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (70 + (RegFileDataWidth + (RegFileDataWidth + 20))))]),
		.instr_rvalid_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 69 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (69 + (RegFileDataWidth + (RegFileDataWidth + 20))))]),
		.instr_addr_o(shadow_outputs_d[119 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((119 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (87 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((119 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (87 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((87 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (119 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)]),
		.instr_rdata_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 68 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) : (((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 68 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + ((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (36 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (36 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((36 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)) - 1)-:((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (36 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((68 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (36 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((36 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (68 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)]),
		.instr_err_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 36 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (36 + (RegFileDataWidth + (RegFileDataWidth + 20))))]),
		.data_req_o(shadow_outputs_d[87 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))]),
		.data_gnt_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 35 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (35 + (RegFileDataWidth + (RegFileDataWidth + 20))))]),
		.data_rvalid_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 34 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (34 + (RegFileDataWidth + (RegFileDataWidth + 20))))]),
		.data_we_o(shadow_outputs_d[86 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))]),
		.data_be_o(shadow_outputs_d[85 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((85 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (81 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((85 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (85 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)]),
		.data_addr_o(shadow_outputs_d[81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((81 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (49 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (81 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)]),
		.data_wdata_o(shadow_outputs_d[49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((49 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (17 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (17 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((17 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (49 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)]),
		.data_rdata_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 33 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) : (((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 33 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + ((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (1 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (1 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((1 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)) - 1)-:((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) >= (1 + (RegFileDataWidth + (RegFileDataWidth + 21))) ? ((33 + (RegFileDataWidth + (RegFileDataWidth + 20))) - (1 + (RegFileDataWidth + (RegFileDataWidth + 21)))) + 1 : ((1 + (RegFileDataWidth + (RegFileDataWidth + 21))) - (33 + (RegFileDataWidth + (RegFileDataWidth + 20)))) + 1)]),
		.data_err_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 1 + (RegFileDataWidth + (RegFileDataWidth + 20)) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (1 + (RegFileDataWidth + (RegFileDataWidth + 20))))]),
		.dummy_instr_id_o(shadow_outputs_d[17 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))]),
		.rf_raddr_a_o(shadow_outputs_d[16 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((16 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (11 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((16 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (16 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)]),
		.rf_raddr_b_o(shadow_outputs_d[11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((11 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (6 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (11 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)]),
		.rf_waddr_wb_o(shadow_outputs_d[6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))-:((6 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) >= (1 + (RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) ? ((6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) - (1 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))))) + 1 : ((1 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))))) - (6 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))))) + 1)]),
		.rf_we_wb_o(shadow_outputs_d[1 + (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))]),
		.rf_wdata_wb_ecc_o(shadow_outputs_d[RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))-:((RegFileDataWidth + (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))) >= (3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))) ? ((RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))))) + 1 : ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) - (RegFileDataWidth + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))))) + 1)]),
		.rf_rdata_a_ecc_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? RegFileDataWidth + (RegFileDataWidth + 20) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (RegFileDataWidth + (RegFileDataWidth + 20))) : (((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? RegFileDataWidth + (RegFileDataWidth + 20) : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (RegFileDataWidth + (RegFileDataWidth + 20))) + ((RegFileDataWidth + (RegFileDataWidth + 20)) >= (RegFileDataWidth + 21) ? ((RegFileDataWidth + (RegFileDataWidth + 20)) - (RegFileDataWidth + 21)) + 1 : ((RegFileDataWidth + 21) - (RegFileDataWidth + (RegFileDataWidth + 20))) + 1)) - 1)-:((RegFileDataWidth + (RegFileDataWidth + 20)) >= (RegFileDataWidth + 21) ? ((RegFileDataWidth + (RegFileDataWidth + 20)) - (RegFileDataWidth + 21)) + 1 : ((RegFileDataWidth + 21) - (RegFileDataWidth + (RegFileDataWidth + 20))) + 1)]),
		.rf_rdata_b_ecc_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? RegFileDataWidth + 20 : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (RegFileDataWidth + 20)) : (((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? RegFileDataWidth + 20 : (((70 + RegFileDataWidth) + RegFileDataWidth) + 20) - (RegFileDataWidth + 20)) + ((RegFileDataWidth + 20) >= 21 ? RegFileDataWidth : 22 - (RegFileDataWidth + 20))) - 1)-:((RegFileDataWidth + 20) >= 21 ? RegFileDataWidth : 22 - (RegFileDataWidth + 20))]),
		.ic_tag_req_o(shadow_outputs_d[ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))-:((3 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))) >= (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))) ? ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))))) - (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))))) + 1 : ((1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))))) + 1)]),
		.ic_tag_write_o(shadow_outputs_d[1 + (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))]),
		.ic_tag_addr_o(shadow_outputs_d[ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))-:((ibex_pkg_IC_INDEX_W + (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))) >= (TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))) ? ((ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))) - (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))))) + 1 : ((TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))) - (ibex_pkg_IC_INDEX_W + (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))))) + 1)]),
		.ic_tag_wdata_o(shadow_outputs_d[TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))-:((TagSizeECC + (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))) >= (3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))) ? ((TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))))) + 1 : ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))) - (TagSizeECC + (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))))) + 1)]),
		.ic_tag_rdata_i(shadow_tag_rdata_q[0]),
		.ic_data_req_o(shadow_outputs_d[ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))-:((3 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))) >= (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))) ? ((ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)))) - (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130)))) + 1 : ((1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 130))) - (ibex_pkg_IC_NUM_WAYS + (1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))))) + 1)]),
		.ic_data_write_o(shadow_outputs_d[1 + (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))]),
		.ic_data_addr_o(shadow_outputs_d[ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)-:((ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)) >= (LineSizeECC + 130) ? ((ibex_pkg_IC_INDEX_W + (LineSizeECC + 129)) - (LineSizeECC + 130)) + 1 : ((LineSizeECC + 130) - (ibex_pkg_IC_INDEX_W + (LineSizeECC + 129))) + 1)]),
		.ic_data_wdata_o(shadow_outputs_d[LineSizeECC + 129-:((LineSizeECC + 129) >= 130 ? LineSizeECC : 131 - (LineSizeECC + 129))]),
		.ic_data_rdata_i(shadow_data_rdata_q[0]),
		.irq_software_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 20 : (70 + RegFileDataWidth) + RegFileDataWidth)]),
		.irq_timer_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 19 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 1)]),
		.irq_external_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 18 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 2)]),
		.irq_fast_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 17 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 3) : ((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 17 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 3) + 14)-:15]),
		.irq_nm_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 2 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 18)]),
		.irq_pending_o(shadow_outputs_d[129]),
		.debug_req_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 1 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 19)]),
		.crash_dump_o(shadow_outputs_d[128-:128]),
		.fetch_enable_i(shadow_inputs_q[((((70 + RegFileDataWidth) + RegFileDataWidth) + 20) >= 0 ? 0 : ((70 + RegFileDataWidth) + RegFileDataWidth) + 20)]),
		.alert_minor_o(shadow_alert_minor),
		.alert_major_o(shadow_alert_major),
		.core_busy_o(shadow_outputs_d[0])
	);
	always @(posedge clk_i) shadow_outputs_q <= shadow_outputs_d;
	wire outputs_mismatch;
	assign outputs_mismatch = enable_cmp_q & (shadow_outputs_q != core_outputs_q[(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? 0 : (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129)+:(((((((((120 + RegFileDataWidth) + 3) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + 3) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129) >= 0 ? (((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 130 : 1 - ((((((((((120 + RegFileDataWidth) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + TagSizeECC) + ibex_pkg_IC_NUM_WAYS) + 1) + ibex_pkg_IC_INDEX_W) + LineSizeECC) + 129))]);
	assign alert_major_o = (outputs_mismatch | shadow_alert_major) | bus_intg_err;
	assign alert_minor_o = shadow_alert_minor;
endmodule
