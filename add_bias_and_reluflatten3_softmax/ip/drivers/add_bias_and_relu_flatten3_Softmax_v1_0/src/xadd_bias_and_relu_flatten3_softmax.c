// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.4.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xadd_bias_and_relu_flatten3_softmax.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XAdd_bias_and_relu_flatten3_softmax_CfgInitialize(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, XAdd_bias_and_relu_flatten3_softmax_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->Input_BaseAddress = ConfigPtr->Input_BaseAddress;
    InstancePtr->Output_BaseAddress = ConfigPtr->Output_BaseAddress;
    InstancePtr->Parameter_BaseAddress = ConfigPtr->Parameter_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XAdd_bias_and_relu_flatten3_softmax_Start(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_AP_CTRL) & 0x80;
    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XAdd_bias_and_relu_flatten3_softmax_IsDone(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XAdd_bias_and_relu_flatten3_softmax_IsIdle(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XAdd_bias_and_relu_flatten3_softmax_IsReady(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XAdd_bias_and_relu_flatten3_softmax_EnableAutoRestart(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XAdd_bias_and_relu_flatten3_softmax_DisableAutoRestart(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_AP_CTRL, 0);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_mem_block2_dense_BaseAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Input_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_mem_block2_dense_HighAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Input_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_HIGH);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_mem_block2_dense_TotalBytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + 1);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_mem_block2_dense_BitWidth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_WIDTH_MEM_BLOCK2_DENSE;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_mem_block2_dense_Depth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_DEPTH_MEM_BLOCK2_DENSE;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_mem_block2_dense_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Input_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_mem_block2_dense_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Input_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + (offset + i)*4);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_mem_block2_dense_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Input_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_mem_block2_dense_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Input_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_INPUT_ADDR_MEM_BLOCK2_DENSE_BASE + offset + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_class_BaseAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_class_HighAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_HIGH);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_class_TotalBytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + 1);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_class_BitWidth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_WIDTH_CLASS;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_class_Depth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_DEPTH_CLASS;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_class_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_class_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + (offset + i)*4);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_class_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_class_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_CLASS_BASE + offset + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_result_BaseAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_result_HighAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_HIGH);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_result_TotalBytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + 1);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_result_BitWidth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_WIDTH_RESULT;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_result_Depth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_DEPTH_RESULT;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_result_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_result_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + (offset + i)*4);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_result_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_result_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Output_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_OUTPUT_ADDR_RESULT_BASE + offset + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_bd3_BaseAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Parameter_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_bd3_HighAddress(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Parameter_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_HIGH);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_bd3_TotalBytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + 1);
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_bd3_BitWidth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_WIDTH_BD3;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Get_bd3_Depth(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_DEPTH_BD3;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_bd3_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Parameter_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_bd3_Words(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Parameter_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Write_bd3_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Parameter_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XAdd_bias_and_relu_flatten3_softmax_Read_bd3_Bytes(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_HIGH - XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Parameter_BaseAddress + XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_PARAMETER_ADDR_BD3_BASE + offset + i);
    }
    return length;
}

void XAdd_bias_and_relu_flatten3_softmax_InterruptGlobalEnable(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_GIE, 1);
}

void XAdd_bias_and_relu_flatten3_softmax_InterruptGlobalDisable(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_GIE, 0);
}

void XAdd_bias_and_relu_flatten3_softmax_InterruptEnable(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_IER);
    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_IER, Register | Mask);
}

void XAdd_bias_and_relu_flatten3_softmax_InterruptDisable(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_IER);
    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_IER, Register & (~Mask));
}

void XAdd_bias_and_relu_flatten3_softmax_InterruptClear(XAdd_bias_and_relu_flatten3_softmax *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_bias_and_relu_flatten3_softmax_WriteReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_ISR, Mask);
}

u32 XAdd_bias_and_relu_flatten3_softmax_InterruptGetEnabled(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_IER);
}

u32 XAdd_bias_and_relu_flatten3_softmax_InterruptGetStatus(XAdd_bias_and_relu_flatten3_softmax *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAdd_bias_and_relu_flatten3_softmax_ReadReg(InstancePtr->Control_BaseAddress, XADD_BIAS_AND_RELU_FLATTEN3_SOFTMAX_CONTROL_ADDR_ISR);
}

