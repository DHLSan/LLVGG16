One step before the Softmax function, there was a function in which the dense layer biases were added and the Rectified Linear Unit (ReLU) operation was performed as the activation function. We created a new IP by combining this function with the Softmax function, which resulted in the last prediction map. In the created IP, there are the INPUT where the input will be given, the parameter where the bias information will be sent, CONTROL where the IP control will be made, and OUTPUT where the output will be taken
The source code we use in Vivado HLS in the HLS folder. The src folder contains the test code we used in the SDK platform and the IP folder contains the IP created within the scope of the project.By following the steps below, you can include the created ip in your system and run it.

- Open Vivado 2017.4
- Create Project
- Create block design
- Settings -> IP --> Repository --> add selected IP
- Add zynq processing system
- Add selected IP to block diagram
- Create HDL Wrapper
- Generate Output Products
- Generate Bitstream
- Launch SDK
- Create application project
- Add /src/hardware_sofware_srcode.c
- Run
