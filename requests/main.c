
#include "lib/requests.h"

var main(void) {
	requests_t requests;
	new_requests(&requests);
	
	chr* result = requests_get(&requests, "https://www.google.com/");
	
	if (result) {
		print("%s\n", result);
		
	}
	
	requests_free(&requests);
	return 0;
	
}
