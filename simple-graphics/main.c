
#include "root.h"

var main(void) {
	print("Video attributes:\n");
	print("\twidth  = %llu\n", video_width());
	print("\theight = %llu\n", video_height());
	
	event_list_t events;
	var x = 0;
	
	while (1) {
		print("FPS: %llu\n", video_fps());
		
		video_clear_colour((++x) * (_UI64_MAX / 256), 0, -1, -1);
		video_clear();
		video_flip();
		
		x %= 256;
		
		get_events(&events);
		
		if (events.quit) {
			break;
			
		}
		
	}
	
	return 0;
	
}
