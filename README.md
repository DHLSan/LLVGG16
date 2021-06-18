# LLVGG16
Convolutional neural network accelerator (VGG16) for low-latency cloud integration.


- Our main goal in this study is to create an accelerated neural network for VGG16 and also to provide a low latency output in the FPGA at the level of milliseconds. We will use the Vivado HLS tool to define our hardware accelerators for VGG16 computation through high-level C language implementations. In this direction, we have divided our project into two stages as software and hardware.
- At the software stage, we are using the VGG16 pretrained code of the [ZFTURBO](https://github.com/ZFTurbo/VGG16-Pretrained-C). 
- VGG16's weight files had to be converted to text format to use the pre-trained code. In this direction, besides the weight file provided by [ZFTURBO](https://github.com/ZFTurbo/VGG16-Pretrained-C), we are converting the alternative weight files to text format. The main purpose of this transformation is that the weight file is in high size for the platform we will implement.

# Experimental Result
- First experiments on the Intel i7 7700HQ CPU -- 90 second to load weights
                                               -- 3.7 second per image

