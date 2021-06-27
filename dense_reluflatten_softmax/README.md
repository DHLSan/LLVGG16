This file contains Dense_ReLUFlatten_Softmax IP created on vivado HLS. By following the steps below, you can include the created ip in your system and run it.

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
- Add /src/helloworld.c
- Add /src/wc1.h , /src/wc2.h, /src/wc3.h, /src/wc4.h, /src/wc5.h, /src/wc6.h -- /src/wc12.h, /src/wc13.h
- Add /src/weigh_bc.h
- Add /src/weight_im.h
- Run helloworld.c(system debugger)

