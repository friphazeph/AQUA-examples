
#include "root.h"

#define LIST_PATH "."

var main(void) {
	char** list = fs_list      (PATH LIST_PATH);
	var count   = fs_list_count(PATH LIST_PATH);
	
	iterate(count) {
		printf("fs_list[%lld]:\t%s\n", i, list[i]);
		
	}
	
	fs_list_free(list, count);
	return 0;
	
}
