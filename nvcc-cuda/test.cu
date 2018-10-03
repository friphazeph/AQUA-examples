
CUDA_PROGRAM((

__global__ void add(int n, float* x, float* y) {
	for (int i = threadIdx.x; i < n; i += blockDim.x) {
		y[i] += x[i];
		
	}
	
}

int main(void) {
	int ARRAY_SIZE = 1 << 24;
	
	float* x;
	float* y;
	
	cudaMallocManaged(&x, ARRAY_SIZE * sizeof(float));
	cudaMallocManaged(&y, ARRAY_SIZE * sizeof(float));
	
	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		x[i] = 1.0f;
		y[i] = 2.0f;
		
	}
	
	add<<<1, 1024>>>(ARRAY_SIZE, x, y);
	cudaDeviceSynchronize();
	
	cudaFree(x);
	cudaFree(y);
	
	return 0;
	
}

))
