## Team number: xohw21-244

## Project name: LLVGG16: Low Latency VGG16 Accelerator for Cloud Integration

**University name:** Eskisehir Technical University

**Advisor:** Ismail San (isan@eskisehir.edu.tr)

**Participants:** Büşranur Yılmaz (busranuryilmaz98@gmail.com)- Kirman Serdar (kirmans341@gmail.com)

**Tools**

**Board used:** ZedBoard Zynq-7000

**Software version:** Vivado 2017.4, Vivado HLS 2017.4
 
# LLVGG16
Convolutional neural network accelerator (VGG16) for low-latency cloud integration.
- Our main goal in this study is to create an accelerated neural network for VGG16 and also to provide a low latency output in the FPGA at the level of milliseconds. We will use the Vivado HLS tool to define our hardware accelerators for VGG16 computation through high-level C language implementations. In this direction, we have divided our project into two stages as software and hardware.
- At the software stage, we are using the VGG16 pretrained code of the [ZFTURBO](https://github.com/ZFTurbo/VGG16-Pretrained-C). 
- VGG16's weight files had to be converted to text format to use the pre-trained code. In this direction, besides the weight file provided by [ZFTURBO](https://github.com/ZFTurbo/VGG16-Pretrained-C), we are converting the alternative weight files to text format. The main purpose of this transformation is that the weight file is in high size for the platform we will implement.

# Hardware Part of Project

Since VGG16 architecture is a much larger than our card memory, The entire architecture could not moved to the hardware. The prediction code is divided intoparts and certain parts are arranged on Vivado  HLS and turned into Ip packager. We created a total of 4 IP packagers for the project. Their names are Softmax IP, Add bias and relu flatten2 IP, Softmax - Add bias and relu flatten3 IP and Dense-reluflatten-softmax IP. All IPs created were integrated with zynq processing system connection and axi interconnect and a certain part of the predict code was run on the ARM operating system.

# Experimental Result
- First experiments on the Intel i7 7700HQ CPU -- 3.7 second per image
                                               
- Second experiment on the ARM  --- 304.64 second per image         

           
- Softmax **IP** --> 0.000131 second                                    
- Add Bias and Relu Flatten2 **IP** --> 0.000123 second
- Add Bias and Relu Flatten3-Softmax **IP** --> 0.000121 second
- Add Bias and Relu Flatten3-Softmax **IP** and Add Bias and Relu Flatten2 **IP** --> 0.000244 second
- Dense- Add Bias and Relu Flatten - Softmax **IP** --> 26.89 second


- Softmax **Function** --> 0.000317 second
- Add Bias and Relu Flatten2 **Function**  --> 0.000101 second
- Add Bias and Relu Flatten3-Softmax **Function**  --> 0.000543 second
- Add Bias and Relu Flatten3-Softmax **Function**  and Add Bias and Relu Flatten2 **Function** --> 0.000644 second
- Dense- Add Bias and Relu Flatten - Softmax  **Function** --> 12.59 second


**2.4** times acceleration with Softmax IP created


**4.5** times acceleration with Add bias and relu flatten3-softmax IP created


**2.6** times acceleration than the system created with Add bias and relu flatten2 and Add bias and relu flatten3-softmax

# Usage

Step 0: VGG16_arm folder in github contains the source code, weight and image header files necessary for the VGG16 model to run on the ARM operating system, you can follow the instructions below.

1) Open Vivado 2017.4
2) Create Project
3) Create block design
4) Add zynq processing system
5) Launch SDK
6) Create application project
7) Extract src.rar
8) Replace code hello world.c with code VGG16_predict.c
9) Add /src/wc1.h , /src/wc2.h, /src/wc3.h, /src/wc4.h, /src/wc5.h, /src/wc6.h -- /src/wc12.h , /src/wc13.h
10) Add /src/weigh_bc.h
11) Add /src/weight_im.h
12) Run VGG16_predict.c(system debugger)

---You can review the following steps for other IP folders in github repo.---

Step 1: Creating IP with HLS

1) Open Vivado HLS 2017.4
2) Create New Project
3) Right click on Source and click add files.
4) Select Softmax/HLS/Softmax_SOURCE.C for softmax IP
5) Select add_bias_and_relu_flatten2/HLS/Bias_reluflat2_SOURCE.c for add_bias_and_relu_flatten2 IP.
6) Select add_bias_and_relu_flatten3_softmax/HLS/addBias_reluflatten3_source.c for Add_bias_and_relufatten3_softmax IP
7) Select dense-reluflatten-softmax/HLS/dense_reluflat_soft_SOURCE.c for Dense_reluflatten_Softmax IP.
8) Name of the top function should be "Softmax" for Softmax IP
9) Name of the top function should be "add_bias_and_relu_flatten2" for Add_bias_and_reluflatten2 IP.
10) Name of the top function should be "dense_reluflatten_softmax" for dense_reluflatten_softmax IP
11) Name of the top function should be "add_bias_and_relu_flatten3_softmax" for Add_bias_and_reluflatten3-Sotmax IP.
12) Click C synthesis.
13) When synthesis is finished, click Export RTL.

Step 2 : Creating SoC Design with IPs 

1) Open Vivado 2017.4
2) Create Project
3) Create block design
4) Settings -> IP --> Repository --> add selected IP
5) Add zynq processing system
6) Add selected IP to block diagram
7) Create HDL Wrapper
8) Generate Output Products
9) Generate Bitstream
10) Export hardware (include bitstream should be marked)
11) Launch SDK.


Step 3 : Test system on SDK

1) Create application project
2) Add /src/hardware_software_srcode.c
3) Run

!!!If you have Vivado version 2017.4, you can add the IP folders in the Github repository to your project by following the Settings -> IP --> Repository --> add selected IP instruction.

