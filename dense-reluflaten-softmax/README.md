The generated dense_reluflatten_softmax IP includes dense1, dense2, dense3, add_bias_and_relu_flatten, add_bias_and_relu_flatten2, add_bias_and_relu_flatten3 and softmax functions. The dense layer is a deeply connected neural network layer; This means that every neuron in the dense layer receives input from all the neurons of its previous layer. Values used in dense layers are actually parameters that can be trained and updated with the help of back propagation.
By following the steps below, you can include the created ip in your system and run it.

- Open Vivado 2017.4
- Create Project
- Create block design
- Settings -> IP --> Repository --> add selected IP
- Add zynq processing system
- Add selected IP to block diagram
- Make sure the connections are exactly the same with Relu_flatten_soft.JPG
- Create HDL Wrapper
- Generate Output Products
- Generate Bitstream
- Launch SDK
- Create application project
- Extract src.rar
- Add /src/software_srcode.c
- Add /src/wc1.h , /src/wc2.h, /src/wc3.h, /src/wc4.h, /src/wc5.h, /src/wc6.h -- /src/wc12.h, /src/wc13.h in the VGG16_arm folder
- Add /src/weigh_bc.h in the VGG16_arm folder
- Add /src/weight_im.h in the VGG16_arm folder
- Run software_srcode.c(system debugger)
