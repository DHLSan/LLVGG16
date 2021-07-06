IP of add bias and relu flatten is integrated with IP of add bias and relu flatten-softmax. The source code we use in Vivado HLS in the HLS folder. The src folder contains the test code we used in the SDK platform and the IP folder contains the IP created within the scope of the project.By following the steps below, you can include the created ip in your system and run it.

- Open Vivado 2017.4
- Create Project
- Create block design
- Settings -> IP --> Repository --> add selected IP
- Settings -> IP --> Repository --> add selected add_bias_and_reluflatten_softmax IP
- Add zynq processing system
- Add selected IP to block diagram
- Create HDL Wrapper
- Generate Output Products
- Generate Bitstream
- Launch SDK
- Create application project
- Add /src/hardware_srcode.c
- Run