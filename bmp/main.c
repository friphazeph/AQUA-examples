
#include "root.h"
#include "lib/layer.h"

var main(void) {
	print("Video attributes:\n");
	print("\twidth  = %llu\n", video_width());
	print("\theight = %llu\n", video_height());
	
	event_list_t events;
	var x = 0;
	
	layer_t layer;
	new_layer(&layer);
	
	layer.stretch = 1;
	
	layer_set_bitmap(&layer, (var*) "test.bmp");
	layer_init(&layer);
	
	while (1) {
		video_clear_colour((++x) * (_UI64_MAX / 256), 0, -1, -1);
		video_clear();
		
		layer_draw(&layer);
		video_flip();
		
		x %= 256;
		
		get_events(&events);
		
		if (events.quit) {
			break;
			
		}
		
	}
	
	layer_dispose(&layer);
	return 0;
	
}
