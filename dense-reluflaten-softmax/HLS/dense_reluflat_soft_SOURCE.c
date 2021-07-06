#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void dense_reluflatten_softmax(float mem_block1_dense[25088], float bd1[4096],float bd2[4096], float bd3[1000], int class[1000], float result[1000] ){
#pragma HLS INTERFACE s_axilite port=mem_block1_dense bundle=INPUT
#pragma HLS INTERFACE s_axilite port=bd1 bundle=parameter
#pragma HLS INTERFACE s_axilite port=bd2 bundle=parameter
#pragma HLS INTERFACE s_axilite port=bd3 bundle=parameter
#pragma HLS INTERFACE s_axilite port=class bundle=OUTPUT
#pragma HLS INTERFACE s_axilite port=result bundle=OUTPUT
#pragma HLS INTERFACE s_axilite port=return bundle=CONTROL
	int i,j;
	int counter =0;
	float mem_block2_dense[25088];
	//dense 1
	for (i = 0; i < 4096; i++) {

		float sum = 0.0;
		for (j = 0; j < 25088; j++) {

				sum += mem_block1_dense[j] * 0.003*(i%4);
		}
		mem_block2_dense[i] = sum;
	}
	//add_bias_and relu flatten 1
	for (i = 0; i < 4096; i++) {
#pragma HLS PIPELINE II=2
			mem_block2_dense[i] += bd1[i];

			if (1 == 1) {
				if (mem_block2_dense[i] < 0)
					mem_block2_dense[i] = 0.0;
			}
		}
	//reset mem block1 dense
	for (i = 0; i < 512*7*7; i++) {
#pragma HLS PIPELINE II=1
			mem_block1_dense[i] = 0.0;
	}

	//dense 2
	for (i = 0; i < 4096; i++) {
//#pragma HLS PIPELINE II=2
		float sum = 0.0;
		for (j = 0; j < 4096; j++) {

				sum += mem_block2_dense[j] * 0.003*(i%4);
		}
		mem_block1_dense[i] = sum;
		}

	// add relu and flatten 2
	for (i = 0; i < 4096; i++) {
#pragma HLS PIPELINE II=2
			mem_block1_dense[i] += bd2[i];

			if (1 == 1) {
				if (mem_block1_dense[i] < 0)
					mem_block1_dense[i] = 0.0;
			}
	}
	// reset mem block2  dense

	for (i = 0; i < 512*7*7; i++) {
#pragma HLS PIPELINE II=1
			mem_block2_dense[i] = 0.0;
		}
	// dense3

	for (i = 0; i < 1000; i++) {
			float sum = 0.0;
			for (j = 0; j < 4096; j++) {
					sum += mem_block1_dense[j] * 0.003*(i%4);
			}
			mem_block2_dense[i] = sum;
		}


	//add_bias_and_relu_flatten3(bd3);
	for (i = 0; i < 1000; i++) {
#pragma HLS PIPELINE II=2
			mem_block2_dense[i] += bd3[i];//bd3
				if (mem_block2_dense[i] < 0)
					mem_block2_dense[i] = 0.0;

		}

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



