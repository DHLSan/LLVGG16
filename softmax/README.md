In this section, we decided to accelerate the Softmax function, which is part of the project and the final stage of our architecture, in hardware. We added our function on Vivado HLS. We put our remaining project code on the test bench and simulated it. The created IP has one input, two outputs and a control input to use IP. Since the model is trained with the ImageNet dataset, there are 1000 classes to detect in our functions. With the module called OUTPUT, we learn which class the prediction belongs to and how accurately it predicts it. 
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
- Add /src/hardware_software_srcode.c
- Run