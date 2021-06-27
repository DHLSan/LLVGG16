#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <xtime_l.h>


#include "wc1.h"
#include "wc2.h"
#include "wc3.h"
#include "wc4.h"
#include "wc5.h"
#include "wc6.h"
#include "wc7.h"

#include "wc8.h"
#include "wc9.h"
#include "wc10.h"
#include "wc11.h"
#include "weight_im.h"
#include "weigh_bc.h"

#define _CRT_SECURE_NO_WARNINGS 1
int counter=0;
int counter1=0;


#define SIZE 224
#define CONV_SIZE 3

volatile int * soft_control = (volatile int *)(0x43C00000);
volatile float * soft_input =  (volatile float *)(0x43C11000);
volatile int * soft_output=     (volatile int *)(0x43C21000);
volatile float * soft_output1= (volatile float *)(0x43C31000);
volatile float * soft_parameter =  (volatile float *)(0x43C41000);

volatile int * control_1 = (volatile int *)(0x43C50000);
volatile float * bias_dense =  (volatile float *)(0x43C64000);
volatile float * memblock1_in=     (volatile float *)(0x43C74000);
volatile float * memblock1_out= (volatile float *)(0x43C84000);



// Weights and image block START
volatile float image[3][224][224];

volatile float wc1[64][3][3][3];
volatile float wc2[64][64][3][3];
volatile float wc3[128][64][3][3];
volatile float wc4[128][128][3][3];
volatile float wc5[256][128][3][3];
volatile float wc6[256][256][3][3];
volatile float wc7[256][256][3][3];
volatile float wc8[512][256][3][3];
volatile float wc9[512][512][3][3];
volatile float wc10[512][512][3][3];
volatile float wc11[512][512][3][3];
volatile float wc12[512][512][3][3];
volatile float wc13[512][512][3][3];

volatile float wd2[4096][4096];
volatile float wd3[4096][1000];

// Blocks for intermediate convolutions
volatile int mem_block_shape[3] = {512, SIZE, SIZE};
float mem_block1[512][SIZE][SIZE];
float mem_block2[512][SIZE][SIZE];
// Blocks for dense flatten layers
int mem_block_dense_shape = { 512 * 7 * 7 };
float mem_block1_dense[512*7*7];
float mem_block2_dense[512*7*7];


XTime tStart,tEnd;
XTime tStart1,tEnd1;
XTime tStart2,tEnd2;
// Weights and image block END
/*
void gettimeofday(time_t *tp, char *_)
{
	*tp = clock();
	return;
}

double get_seconds(time_t timeStart, time_t timeEnd) {
	return (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
}
*/
void reset_mem_block1() {
	int i, j, k;
	for (i = 0; i < mem_block_shape[0]; i++) {
		for (j = 0; j < mem_block_shape[1]; j++) {
			for (k = 0; k < mem_block_shape[2]; k++) {
				mem_block1[i][j][k] = 0.0;
			}
		}
	}
}

void reset_mem_block2() {
	int i, j, k;
	for (i = 0; i < mem_block_shape[0]; i++) {
		for (j = 0; j < mem_block_shape[1]; j++) {
			for (k = 0; k < mem_block_shape[2]; k++) {
				mem_block2[i][j][k] = 0.0;
			}
		}
	}
}

void reset_mem_block_dense1() {
	int i;
	for (i = 0; i < mem_block_dense_shape; i++) {
		mem_block1_dense[i] = 0.0;
	}
}
void reset_mem_block_dense2() {
	int i;
	for (i = 0; i < mem_block_dense_shape; i++) {
		mem_block2_dense[i] = 0.0;
	}
}


void read_weights(int lvls) {

	int i, j, k, l;


	counter = 0;
	//printf("Read1\n");
	for (i = 0; i < 64; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k <3; k++) {
				for (l = 0; l < 3; l++) {

					wc1[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc1_h[counter];
					counter++;
				}
			}
		}
	}
	counter = 0;
	//printf("Read2\n");
		for (i = 0; i < 64; i++) {
			for (j = 0; j < 64; j++) {
				for (k = 0; k < 3; k++) {
					for (l = 0; l < 3; l++) {

						wc2[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc2_h[counter];;
						counter++;
					}
				}
			}
		}
	counter = 0;
	//printf("Read3\n");
			for (i = 0; i < 128; i++) {
				for (j = 0; j < 64; j++) {
					for (k = 0; k < 3; k++) {
						for (l = 0; l < 3; l++) {

							wc3[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc3_h[counter];;
							counter++;
						}
					}
				}
			}
	counter = 0;
	//printf("Read4\n");
			for (i = 0; i < 128; i++) {
				for (j = 0; j < 128; j++) {
					for (k = 0; k < 3; k++) {
						for (l = 0; l < 3; l++) {

							wc4[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc4_h[counter];
							counter++;
						}
					}
				}
			}
		counter = 0;
		//printf("Read5\n");
				for (i = 0; i < 256; i++) {
					for (j = 0; j < 128; j++) {
						for (k = 0; k < 3; k++) {
							for (l = 0; l < 3; l++) {

								wc5[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc5_h[counter];
								counter++;
							}
						}
					}
				}
		counter = 0;
		//printf("Read6\n");
						for (i = 0; i < 256; i++) {
							for (j = 0; j < 256; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++) {

										wc6[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc6_h[counter];
										counter++;
									}
								}
							}
						}
		counter = 0;
		//printf("Read7\n");
						for (i = 0; i < 256; i++) {
							for (j = 0; j < 256; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++) {

										wc7[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc7_h[counter];
										counter++;
									}
								}
							}
						}
		counter = 0;
		//printf("Read8\n");
						for (i = 0; i < 512; i++) {
							for (j = 0; j < 256; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++) {

										wc8[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc8_h[counter];
										counter++;
									}
								}
							}
						}
				counter = 0;
						//printf("Read9\n");
						for (i = 0; i < 512; i++) {
							for (j = 0; j < 512; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++) {
										//if (i%2==0){
											wc9[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc9_h[counter];
											counter++;

										//}
										//else{
										//	wc10[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] =-0.003*(i%4);
										//}
									}
								}
							}
						}
						counter = 0;
						//printf("Read10\n");
						for (i = 0; i < 512; i++) {
							for (j = 0; j < 512; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++) {
										///if (i%2==0){
											wc10[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc10_h[counter];
											counter++;

										//}
										//else{
										//	wc10[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] =0.003*(i%4);
										//}
									}
								}
							}
						}
						counter = 0;
						//printf("Read11\n");
						for (i = 0; i < 512; i++) {
							for (j = 0; j < 512; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++) {

										//if (i%2==0){
											wc11[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] =wc11_h[counter];
											counter++;

										//}
									//	else{
										//	wc11[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] =-0.003*(i%4);
									//	}
									}
								}
							}
						}
						counter = 0;
						//printf("Read12\n");
						for (i = 0; i < 512; i++) {
							for (j = 0; j < 512; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++)
										{
										//if (i%2==0){
											wc10[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] =wc10_h[counter];
											counter++;

									//	}
										//else{
										//	wc12[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] =0.003*(i%4);
									//	}
									}
								}
							}
						}
						counter = 0;
						//printf("Read13\n");
						for (i = 0; i < 512; i++) {
							for (j = 0; j < 512; j++) {
								for (k = 0; k < 3; k++) {
									for (l = 0; l < 3; l++) {
										//if (i%2==0){
											wc11[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] = wc11_h[counter];
											counter++;

										//}
										//else{
											//wc13[i][j][CONV_SIZE - k - 1][CONV_SIZE - l - 1] =-0.003*(i%4);
										//}


									}
								}
							}
						}

						//printf("bias13\n");



					//printf("Read dense block %d weights\n", 1);
					for (i = 0; i < 4096; i++) {
						for (j = 0; j < 4096; j++) {
						//	fscanf(iin, "%f", &dval);
							if(i%2==0){
								wd2[i][j] =0.003*(i%4);
							}
							else{
								wd2[i][j] =-0.003*(i%4);
							}
						}
					}


							//printf("Read dense block %d weights\n", 2);
							for (i = 0; i < 4096; i++) {
								for (j = 0; j < 1000; j++) {
									//fscanf(iin, "%f", &dval);
									if(i%2==0){
										wd3[i][j] =0.003*(i%4);
									}
									else{
										wd3[i][j] =-0.003*(i%4);
									}
							}

							}
}


void read_image() {
	int i, j, l;
	int counter = 0;
	/* Reading image */
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			for (l = 0; l < 3; l++) {

				image[l][i][j] = image_h[counter];
				counter++;
			}
		}
	}


}


void normalize_image() {
	int i, j, l;
	//printf("normalize");
	float coef[3] = { 103.939, 116.779, 123.68 };

	for (l = 0; l < 3; l++) {
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				image[l][i][j] -= coef[l];
			}
		}
	}

}


void convolution_3_x_3(float matrix[224][224], float kernel[3][3], int size, int ind) {
	int i, j;
	float sum;
	float zeropad[SIZE + 2][SIZE + 2] = { 0.0 };

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			zeropad[i + 1][j + 1] = matrix[i][j];
		}
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			sum = zeropad[i][j] * kernel[0][0] +
				zeropad[i + 1][j] * kernel[1][0] +
				zeropad[i + 2][j] * kernel[2][0] +
				zeropad[i][j + 1] * kernel[0][1] +
				zeropad[i + 1][j + 1] * kernel[1][1] +
				zeropad[i + 2][j + 1] * kernel[2][1] +
				zeropad[i][j + 2] * kernel[0][2] +
				zeropad[i + 1][j + 2] * kernel[1][2] +
				zeropad[i + 2][j + 2] * kernel[2][2];
			mem_block1[ind][i][j] += sum;
		}
	}


}
void convolution_3_x_3_2(float matrix[224][224], float kernel[3][3], int size, int ind) {
	int i, j;
	float sum;
	float zeropad[SIZE + 2][SIZE + 2] = { 0.0 };

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			zeropad[i + 1][j + 1] = matrix[i][j];
		}
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			sum = zeropad[i][j] * kernel[0][0] +
				zeropad[i + 1][j] * kernel[1][0] +
				zeropad[i + 2][j] * kernel[2][0] +
				zeropad[i][j + 1] * kernel[0][1] +
				zeropad[i + 1][j + 1] * kernel[1][1] +
				zeropad[i + 2][j + 1] * kernel[2][1] +
				zeropad[i][j + 2] * kernel[0][2] +
				zeropad[i + 1][j + 2] * kernel[1][2] +
				zeropad[i + 2][j + 2] * kernel[2][2];
			mem_block2[ind][i][j] += sum;
		}
	}



}


void add_bias_and_relu1(float bs, int size, int ind) {
	int i, j;
	//counter1=0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			////printf("%.12lf\n", out[i][j]);
			//counter1++;
			mem_block1[ind][i][j] += bs;
			if (mem_block1[ind][i][j] < 0)
				mem_block1[ind][i][j] = 0.0;

		}
	}
	////printf("layer x %d\n",counter1);
}

void add_bias_and_relu2(float bs, int size, int ind) {
	int i, j;
	//counter1=0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			////printf("%.12lf\n", out[i][j]);
			//counter1++;
			mem_block2[ind][i][j] += bs;
			if (mem_block2[ind][i][j] < 0)
				mem_block2[ind][i][j] = 0.0;

		}
	}
	////printf("layer x %d\n",counter1);
}
void add_bias_and_relu_flatten1(float bs[4096], int size, int relu) {
	int i;
	counter1 = 0;
	for (i = 0; i < size; i++) {
		mem_block2_dense[i] += bs[i];
		counter1++;
		if (relu == 1) {
			if (mem_block2_dense[i] < 0)
				mem_block2_dense[i] = 0.0;
		}
	}
	//printf("flatt x %d\n", counter1);
}

void add_bias_and_relu_flatten2(float bs[4096], int size, int relu) {
	int i;
	counter1 = 0;
	for (i = 0; i < size; i++) {
		mem_block1_dense[i] += bs[i];
		counter1++;
		if (relu == 1) {
			if (mem_block1_dense[i] < 0)
				mem_block1_dense[i] = 0.0;
		}
	}
	//printf("flatt x %d\n", counter1);
}
void add_bias_and_relu_flatten3(float bs[1000], int size, int relu) {
	int i;
	counter1 = 0;
	for (i = 0; i < size; i++) {
		mem_block2_dense[i] += bs[i];
		counter1++;
		if (relu == 1) {
			if (mem_block2_dense[i] < 0)
				mem_block2_dense[i] = 0.0;
		}
	}
	//printf("flatt x %d\n", counter1);
}

float max_of_4(float a, float b, float c, float d) {
	if (a >= b && a >= c && a >= d) {
		return a;
	}
	if (b >= c && b >= d) {
		return b;
	}
	if (c >= d) {
		return c;
	}
	return d;
}


void maxpooling1(float out[224][224], int size, int ind) {
	int i, j;
	for (i = 0; i < size; i += 2) {
		for (j = 0; j < size; j += 2) {
			out[i / 2][j / 2] = max_of_4(out[i][j], out[i + 1][j], out[i][j + 1], out[i + 1][j + 1]);
		}
	}
	for (i = 0; i < 224; i++)
		for (j = 0; j < 224; j++)
			mem_block1[ind][i][j] = out[i][j];
}

void maxpooling2(float out[224][224], int size, int ind) {
	int i, j;
	for (i = 0; i < size; i += 2) {
		for (j = 0; j < size; j += 2) {
			out[i / 2][j / 2] = max_of_4(out[i][j], out[i + 1][j], out[i][j + 1], out[i + 1][j + 1]);
		}
	}

	for(i =0; i<224;i++)
		for( j =0;j<224;j++)
			mem_block2[ind][i][j] = out[i][j];
}



void flatten(float in[512][SIZE][SIZE], float* out, int sh0, int sh1, int sh2) {
	int i, j, k, total = 0;
	for (i = 0; i < sh0; i++) {
		for (j = 0; j < sh1; j++) {
			for (k = 0; k < sh2; k++) {
				out[total] = in[i][j][k];
				total += 1;
			}
		}
	}
	for (i = 0; i < total; i++)
		mem_block1_dense[i] += out[i];
}


void dense(float* in,  float* out, int sh_in, int sh_out) {
	int i, j;
//#pragma omp parallel for private(j) schedule(dynamic,1) num_threads(numthreads)
	for (i = 0; i < sh_out; i++) {
		float sum = 0.0;
		for (j = 0; j < sh_in; j++) {
			if(i%2==0){
				sum += in[j] *(0.003*(i%4));
			}
			else{
				sum += in[j] *(-0.003*(i%4));
			}

		}
		out[i] = sum;
	}
}
void dense1(float* in, float weights[4096][4096], float* out, int sh_in, int sh_out) {
	int i, j;
//#pragma omp parallel for private(j) schedule(dynamic,1) num_threads(numthreads)
	for (i = 0; i < sh_out; i++) {
		float sum = 0.0;
		for (j = 0; j < sh_in; j++) {
			sum += in[j] * weights[j][i];
		}
		out[i] = sum;
	}
}
void dense2(float* in, float weights[4096][1000], float* out, int sh_in, int sh_out) {
	int i, j;
//#pragma omp parallel for private(j) schedule(dynamic,1) num_threads(numthreads)
	for (i = 0; i < sh_out; i++) {
		float sum = 0.0;
		for (j = 0; j < sh_in; j++) {
			sum += in[j] * weights[j][i];
		}
		out[i] = sum;
	}
}
void softmax(int sh_out) {
	int i;
	float max_val, sum;
	int counter =0;
	int class[1000];
	float result[1000];
	max_val = mem_block2_dense[0];
	for (i = 1; i < sh_out; i++) {
		if (mem_block2_dense[i] > max_val)
			max_val = mem_block2_dense[i];
	}
	sum = 0.0;
	for (i = 0; i < sh_out; i++) {
		mem_block2_dense[i] = exp(mem_block2_dense[i] - max_val);
		sum += mem_block2_dense[i];
	}
	for (i = 0; i < sh_out; i++) {
		mem_block2_dense[i] /= sum;
	}
	for (i = 0; i < 1000; i++) {



					class[i] = counter;
					result[i] = mem_block2_dense[i];
					//printf("class: %d\n",class[i]);
					//printf("result: %f\n",result[i]);


				if (counter == 999) {

					counter = -1;
				}
				counter = counter + 1;

		}
}


void get_VGG16() {
	int i, j;
	int level, cur_size;

	// Init intermediate memory
	reset_mem_block1();
	reset_mem_block2();
	reset_mem_block_dense1();
	reset_mem_block_dense2();

	// Layer 1 (Convolution 3 -> 64)
	level = 0;
	cur_size = SIZE;

	for (i = 0; i < 64; i++) {
		for (j = 0; j < 3; j++) {
			convolution_3_x_3(image[j], wc1[i][j], cur_size,i);
		}
		add_bias_and_relu1(bc1[i], cur_size, i);
	}

	// Layer 2 (Convolution 64 -> 64)
	level = 1;

	for (i = 0; i < 64; i++) {
		for (j = 0; j < 64; j++) {
			convolution_3_x_3_2(mem_block1[j], wc2[i][j], cur_size,i);
		}
		add_bias_and_relu2(bc2[i], cur_size, i);
	}
	reset_mem_block1();

	// Layer 3 (MaxPooling)

	for (i = 0; i < 64; i++) {
		maxpooling2(mem_block2[i], cur_size, i);
	}
	cur_size /= 2;

	// Layer 4 (Convolution 64 -> 128)
	level = 2;

	for (i = 0; i < 128; i++) {
		for (j = 0; j < 64; j++) {
			convolution_3_x_3(mem_block2[j], wc3[i][j], cur_size,i);
		}
		add_bias_and_relu1(bc3[i], cur_size, i);
	}
	reset_mem_block2();

	// Layer 5 (Convolution 128 -> 128)
	level = 3;

	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			convolution_3_x_3_2(mem_block1[j], wc4[i][j], cur_size,i);
		}
		add_bias_and_relu2(bc4[i], cur_size, i);
	}
	reset_mem_block1();

	// Layer 6 (MaxPooling)

	for (i = 0; i < 128; i++) {
		maxpooling2(mem_block2[i], cur_size, i);
	}
	cur_size /= 2;

	// Layer 7 (Convolution 128 -> 256)
	level = 4;

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 128; j++) {
			convolution_3_x_3(mem_block2[j], wc5[i][j], cur_size,i);
		}
		add_bias_and_relu1(bc5[i], cur_size, i);
	}
	reset_mem_block2();

	// Layer 8 (Convolution 256 -> 256)
	level = 5;

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			convolution_3_x_3_2(mem_block1[j], wc6[i][j], cur_size,i);
		}
		add_bias_and_relu2(bc6[i], cur_size, i);
	}
	reset_mem_block1();

	// Layer 9 (Convolution 256 -> 256)
	level = 6;

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			convolution_3_x_3(mem_block2[j], wc7[i][j], cur_size,i);
		}
		add_bias_and_relu1(bc7[i], cur_size, i);
	}
	reset_mem_block2();

	// Layer 10 (MaxPooling)

	for (i = 0; i < 256; i++) {
		maxpooling1(mem_block1[i], cur_size, i);
	}
	cur_size /= 2;

	// Layer 11 (Convolution 256 -> 512)
	level = 7;

	for (i = 0; i < 512; i++) {
		for (j = 0; j < 256; j++) {
			convolution_3_x_3_2(mem_block1[j], wc8[i][j],  cur_size,i);
		}
		add_bias_and_relu2(bc8[i], cur_size, i);
	}
	reset_mem_block1();

	// Layer 12 (Convolution 512 -> 512)
	level = 8;

	for (i = 0; i <512; i++) {
		for (j = 0; j < 512; j++) {
			convolution_3_x_3(mem_block2[j], wc9[i][j],cur_size,i);
		}
		add_bias_and_relu1(bc9[i], cur_size, i);
	}
	reset_mem_block2();

	// Layer 13 (Convolution 512 -> 512)
	level = 9;

	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			convolution_3_x_3_2(mem_block1[j], wc10[i][j], cur_size,i);
		}
		add_bias_and_relu2(bc10[i], cur_size, i);
	}
	reset_mem_block1();

	// Layer 14 (MaxPooling)

	for (i = 0; i < 512; i++) {
		maxpooling2(mem_block2[i], cur_size, i);
	}
	cur_size /= 2;

	// Layer 15 (Convolution 512 -> 512)
	level = 10;

	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			convolution_3_x_3(mem_block2[j], wc11[i][j], cur_size,i);
		}
		add_bias_and_relu1(bc11[i], cur_size, i);
	}
	reset_mem_block2();

	// Layer 16 (Convolution 512 -> 512)
	level = 11;

	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			convolution_3_x_3_2(mem_block1[j], wc10[i][j], cur_size,i);
		}
		add_bias_and_relu2(bc12[i], cur_size, i);
	}
	reset_mem_block1();

	// Layer 17 (Convolution 512 -> 512)
	level = 12;

	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			convolution_3_x_3(mem_block2[j], wc11[i][j],  cur_size,i);
		}
		add_bias_and_relu1(bc13[i], cur_size, i);
	}
	reset_mem_block2();

	// Layer 18 (MaxPooling)

	for (i = 0; i < 512; i++) {
		maxpooling1(mem_block1[i], cur_size, i);
	}
	cur_size /= 2;
	// Layer 19 (Flatten)
		flatten(mem_block1, mem_block1_dense, 512, cur_size, cur_size);

		// Layer 20 (Dense)
		level = 0;
		XTime_GetTime(&tStart2);
		dense(mem_block1_dense, mem_block2_dense, 25088, 4096);
		add_bias_and_relu_flatten1(bd1, 4096, 1);
		reset_mem_block_dense1(mem_block1_dense);
		// Layer 21 (Dense)
		level = 1;
		dense1(mem_block2_dense, wd2, mem_block1_dense, 4096, 4096);
		XTime_GetTime(&tStart2);
		add_bias_and_relu_flatten2(bd2, 4096, 1);
		XTime_GetTime(&tEnd2);

		reset_mem_block_dense2(mem_block2_dense);
		// Layer 22 (Dense)
		level = 2;

		dense2(mem_block1_dense, wd3, mem_block2_dense,4096, 1000);
		double ElapsedTime1;
		double ElapsedTime2;
		XTime_GetTime(&tStart1);
		add_bias_and_relu_flatten3(bd3, 1000, 1);
		softmax(1000);
		XTime_GetTime(&tEnd1);


		ElapsedTime1 = 1.0*(tEnd1- tStart1)/(COUNTS_PER_SECOND);
		ElapsedTime2 = 1.0*(tEnd2- tStart2)/(COUNTS_PER_SECOND);
		printf("Add Bias and ReLU Flattan2 function Took %.4f seconds to execute \n", ElapsedTime2);

		printf("Add Bias and ReLU Flattan3-Softmax function Took %.4f \n", ElapsedTime1);


		//XTime_GetTime(&tStart2);
		//add_bias_and_relu_flatten2(bd2, 4096, 1);
/*
		for (int i = 0; i<4096;i++){
				memblock1_in[i]= mem_block1_dense[i]; /// send mem_block2_dense to ip

				}
		for (int i = 0; i<4096;i++){
				bias_dense[i]= bd2[i]; /// send bias dense to ip

		}
		control_1[0] |=0x1; // start
		while((control_1[0]&0x2) != 0x2); // wait for done
		for (int i=0; i<4096;i++){
			mem_block1_dense[i] = memblock1_out[i];

		}
*/
/*
		for (int i = 0; i<1000;i++){
		    		soft_input[i]= mem_block2_dense[i]; /// send mem_block2_dense to ip

		    		}
		    for (int i = 0; i<1000;i++){
		        		soft_parameter[i]= bd3[i]; /// send bias dense to ip

		        		}


			soft_control[0] |=0x1; // start
			while((soft_control[0]&0x2) != 0x2); // wait for done
			//XTime_GetTime(&tEnd1);
		//	ElapsedTime1 = 1.0*(tEnd1- tStart1)/(COUNTS_PER_SECOND);

		//	//printf("Took %.4f seconds to execute \n", ElapsedTime1);
			for (int i=0; i<1000;i++){

						//printf("class: %d  ",soft_output[i]);
						//printf("result: %f\n",soft_output1[i]);

					}
*/


	return;
}




char *trimwhitespace(char *str)
{
	char *end;

	// Trim leading space
	while (isspace((unsigned char)*str)) str++;

	if (*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	// Write new null terminator
	*(end + 1) = 0;

	return str;
}


int main() {

	//xil_//printf("hata\n");
	int lvls = -1;
	double ElapsedTime;
	//time_t timeStart, timeEnd;
//	double deltaTime;

	read_weights(lvls);

	////printf("Reading weights:  sec\n");


	read_image();
	normalize_image();

	////printf("Infer image sec\n");
	//gettimeofday(&timeStart, NULL);
	XTime_GetTime(&tStart);
	get_VGG16();
	XTime_GetTime(&tEnd);
	ElapsedTime = 1.0*(tEnd- tStart)/(COUNTS_PER_SECOND);
	//gettimeofday(&timeEnd, NULL);
	//deltaTime = get_seconds(timeStart, timeEnd);
	////printf("Infer image %.3lf sec\n", deltaTime);
	/////printf("Took %.4f seconds to execute \n", ElapsedTime);
	////printf("Infer image sec\n");


	return 0;
}
