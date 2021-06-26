# Eskisehir technical university
# Participants :
   Büşranur Yılmaz (busranuryilmaz98@gmail.com)
   
   Kirman Serdar (kirmans341@gmail.com)
# Advisor:
   Ismail San (isan@eskisehir.edu.tr)


# LLVGG16
Convolutional neural network accelerator (VGG16) for low-latency cloud integration.


- Our main goal in this study is to create an accelerated neural network for VGG16 and also to provide a low latency output in the FPGA at the level of milliseconds. We will use the Vivado HLS tool to define our hardware accelerators for VGG16 computation through high-level C language implementations. In this direction, we have divided our project into two stages as software and hardware.
- At the software stage, we are using the VGG16 pretrained code of the [ZFTURBO](https://github.com/ZFTurbo/VGG16-Pretrained-C). 
- VGG16's weight files had to be converted to text format to use the pre-trained code. In this direction, besides the weight file provided by [ZFTURBO](https://github.com/ZFTurbo/VGG16-Pretrained-C), we are converting the alternative weight files to text format. The main purpose of this transformation is that the weight file is in high size for the platform we will implement.
- 
# Hardware Part of Project

Since VGG16 architecture is a much larger than our card memory, The entire architecture could not moved to the hardware. The prediction code is divided intoparts and certain parts are arranged on Vivado  HLS and turned into Ip packager. We created a total of 4 IP packagers for the project. Their names are Softmax IP, Add bias and relu flatten2 IP, Softmax - Add bias and relu flatten3 IP and Dense-reluflatten-softmax IP. All IPs created were integrated with zynq processing system connection and axi interconnect and a certain part of the predict code was run on the ARM operating system.

# Experimental Result
- First experiments on the Intel i7 7700HQ CPU -- 90 second to load weights
                                               -- 3.7 second per image
- Softmax IP --> 0.001 second
- Add Bias and Relu Flatten2 IP --> 0.003 second
- Add Bias and Relu Flatten2-Softmax IP --> 0.0014 second
- Add Bias and Relu Flatten2-Softmax IP and Add Bias and Relu Flatten2 IP --> 0.0036 second
- Dense- Add Bias and Relu Flatten - Softmax --> 26.14 second

# Usage


