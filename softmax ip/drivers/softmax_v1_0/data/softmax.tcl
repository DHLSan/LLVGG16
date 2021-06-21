# ==============================================================
# File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
# Version: 2017.4
# Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
# 
# ==============================================================

proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "XSoftmax" \
        "NUM_INSTANCES" \
        "DEVICE_ID" \
        "C_S_AXI_CONTROL_BASEADDR" \
        "C_S_AXI_CONTROL_HIGHADDR" \
        "C_S_AXI_INPUT_BASEADDR" \
        "C_S_AXI_INPUT_HIGHADDR" \
        "C_S_AXI_OUTPUT_BASEADDR" \
        "C_S_AXI_OUTPUT_HIGHADDR" \
        "C_S_AXI_OUTPUT1_BASEADDR" \
        "C_S_AXI_OUTPUT1_HIGHADDR"

    xdefine_config_file $drv_handle "xsoftmax_g.c" "XSoftmax" \
        "DEVICE_ID" \
        "C_S_AXI_CONTROL_BASEADDR" \
        "C_S_AXI_INPUT_BASEADDR" \
        "C_S_AXI_OUTPUT_BASEADDR" \
        "C_S_AXI_OUTPUT1_BASEADDR"

    xdefine_canonical_xpars $drv_handle "xparameters.h" "XSoftmax" \
        "DEVICE_ID" \
        "C_S_AXI_CONTROL_BASEADDR" \
        "C_S_AXI_CONTROL_HIGHADDR" \
        "C_S_AXI_INPUT_BASEADDR" \
        "C_S_AXI_INPUT_HIGHADDR" \
        "C_S_AXI_OUTPUT_BASEADDR" \
        "C_S_AXI_OUTPUT_HIGHADDR" \
        "C_S_AXI_OUTPUT1_BASEADDR" \
        "C_S_AXI_OUTPUT1_HIGHADDR"
}

