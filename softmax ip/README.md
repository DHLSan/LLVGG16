This file contains softmax ip created on vivado HLS. By following the steps below, you can include the created ip in your system and run it.

- Open Vivado 2017.4
- Create Project
- Create block design
- Settings -> IP --> Repository --> add selected IP
- Add zynq processing system
- Add selected IP to block diagram
- Make sure the connections are exactly the same with softmax_ip.JPG
- Create HDL Wrapper
- Generate Output Products
- Generate Bitstream
- Launch SDK
- Create application project
- Add /src/helloworld.c
- Run
