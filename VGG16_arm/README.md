This file contains VGG16_predct.c. By following the steps below,

- Open Vivado 2017.4
- Create Project
- Create block design
- Add zynq processing system
- Create HDL Wrapper
- Generate Bitstream
- Launch SDK
- Create application project
- Extract src.rar
- Replace code hello world.c with code VGG16 predict.c
- Add /src/wc1.h , /src/wc2.h, /src/wc3.h, /src/wc4.h, /src/wc5.h, /src/wc6.h -- /src/wc12.h, /src/wc13.h in the dense_reluflatten_softmax folder
- Add /src/weigh_bc.h in the dense_reluflatten_softmax folder
- Add /src/weight_im.h in the dense_reluflatten_softmax folder
- Run VGG16_predict.c(system debugger)