# ==============================================================
# File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
# Version: 2017.4.1
# Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
# 
# ==============================================================

proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "XAdd_bias_and_relu_flatten2" \
        "NUM_INSTANCES" \
        "DEVICE_ID" \
        "C_S_AXI_CONTROL_BASEADDR" \
        "C_S_AXI_CONTROL_HIGHADDR" \
        "C_S_AXI_INPUT_BASEADDR" \
        "C_S_AXI_INPUT_HIGHADDR" \
        "C_S_AXI_OUTPUT_BASEADDR" \
        "C_S_AXI_OUTPUT_HIGHADDR" \
        "C_S_AXI_PARAMETER_BASEADDR" \
        "C_S_AXI_PARAMETER_HIGHADDR"

    xdefine_config_file $drv_handle "xadd_bias_and_relu_flatten2_g.c" "XAdd_bias_and_relu_flatten2" \
        "DEVICE_ID" \
        "C_S_AXI_CONTROL_BASEADDR" \
        "C_S_AXI_INPUT_BASEADDR" \
        "C_S_AXI_OUTPUT_BASEADDR" \
        "C_S_AXI_PARAMETER_BASEADDR"

    xdefine_canonical_xpars $drv_handle "xparameters.h" "XAdd_bias_and_relu_flatten2" \
        "DEVICE_ID" \
        "C_S_AXI_CONTROL_BASEADDR" \
        "C_S_AXI_CONTROL_HIGHADDR" \
        "C_S_AXI_INPUT_BASEADDR" \
        "C_S_AXI_INPUT_HIGHADDR" \
        "C_S_AXI_OUTPUT_BASEADDR" \
        "C_S_AXI_OUTPUT_HIGHADDR" \
        "C_S_AXI_PARAMETER_BASEADDR" \
        "C_S_AXI_PARAMETER_HIGHADDR"
}

