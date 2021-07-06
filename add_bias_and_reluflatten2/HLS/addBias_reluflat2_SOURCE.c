#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void add_bias_and_relu_flatten2(float mem_block1_dense[4096],float bd2[4096], float memblock1_dense[4096]){
#pragma HLS INTERFACE s_axilite port=mem_block1_dense bundle=INPUT
#pragma HLS INTERFACE s_axilite port=bd2 bundle=parameter
#pragma HLS INTERFACE s_axilite port=memblock1_dense bundle=OUTPUT
#pragma HLS INTERFACE s_axilite port=return bundle=CONTROL
	int i;

	for (i = 0; i < 4096; i++) {
#pragma HLS PIPELINE II=2
		mem_block1_dense[i] += bd2[i];

		if (1 == 1) {
			if (mem_block1_dense[i] < 0)
				mem_block1_dense[i] = 0.0;
		}
	}
	for (i = 0; i < 4096; i++){
#pragma HLS PIPELINE II=1
		memblock1_dense[i]=mem_block1_dense[i];


	}

 return;
}



