
#incldue "root.h"
#include "lib/compute/cuda/root.h"

var main(void) {
	cuda_code_t code =
		#include "test.cu"
	;
	
	cuda_bytecode_t bytecode;
	var             result;
	
	CUDA_COMPILE(code, bytecode);
	CUDA_EXECUTE      (bytecode, result);
	CUDA_FREE   (code);
	
	print("CUDA program compiled with NVCC and executed with error code %lld\n", result);
	return result;
	
}
