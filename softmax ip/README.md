This file contains softmax ip created on vivado HLS. By following the steps below, you can include the created ip in your system and run it.

Vivado 2017.4 Create RTL Project
Choose ZedBoard Development Kit as destination board
- Vivado 2017.4

Create block design

Add ip --> zynq processing system

Click Window --> Add ip catalog --> select ip files which you created with HLS

make sure the connections are exactly the same with block_diagram.pdf

Right click on design file and click Create HDL Wrapper.

Right click on design and click Generate Output Products.

Click on Generate Bitstream

SDK
Create new Hello World application project in SDK.

Replace the contents of the Hello world project with /src/helloworld.c

Ready to run.
