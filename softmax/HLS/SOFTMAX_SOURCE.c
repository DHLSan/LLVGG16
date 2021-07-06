#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void Softmax(float mem_block2_dense[1000], float bd3[1000], int class[1000], float result[1000]){
#pragma HLS INTERFACE s_axilite port=mem_block2_dense bundle=INPUT
#pragma HLS INTERFACE s_axilite port=bd3 bundle=parameter
#pragma HLS INTERFACE s_axilite port=class bundle=OUTPUT
#pragma HLS INTERFACE s_axilite port=result bundle=OUTPUT
#pragma HLS INTERFACE s_axilite port=return bundle=CONTROL
	int i;
	int counter =0;

	//softmax();
	float max_val, sum;
	max_val = mem_block2_dense[0];
	for (i = 1; i < 1000; i++) {
#pragma HLS PIPELINE II=1
		if (mem_block2_dense[i] > max_val)
			max_val = mem_block2_dense[i];
	}
	sum = 0.0;
	for (i = 0; i < 1000; i++) {
#pragma HLS PIPELINE II=2
		mem_block2_dense[i] = exp(mem_block2_dense[i] - max_val);
		sum += mem_block2_dense[i];
	}
	for (i = 0; i < 1000; i++) {
#pragma HLS PIPELINE II=1
		mem_block2_dense[i] /= sum;
	}

	for (i = 0; i < 1000; i++) {
#pragma HLS PIPELINE II=2

			if (mem_block2_dense[i]) {

				class[i] = counter;
				result[i] = mem_block2_dense[i];
			}

			counter = counter + 1;

	}

 return;
}



