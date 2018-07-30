
#include "root.h"
#include "lib/layer.h"

#define SCALE (1 << 2)

var main(void) {
	print("Video attributes:\n");
	print("\twidth  = %llu\n", video_width());
	print("\theight = %llu\n", video_height());
	
	event_list_t events;
	
	var x = 0;
	var y = 0;
	
	layer_t canvas;
	new_layer(&canvas);
	
	canvas.stretch = 1;
	
	layer_set_canvas(&canvas, video_width() / SCALE, video_height() / SCALE);
	layer_init(&canvas);
	
	while (1) {
		video_clear_colour((++x) * (_UI64_MAX / 256), 0, -1, -1);
		layer_set_colour(&canvas, -1, (++y) * (_UI64_MAX / 256), 0);
		
		video_clear();
		layer_draw(&canvas);
		video_flip();
		
		x %= 256;
		y++;
		y %= 256;
		
		get_events(&events);
		
		if (events.quit) {
			break;
			
		} else if (events.pointer_click_type) {
			layer_canvas_set_pixel(&canvas, events.pointer_x / SCALE, events.pointer_y / SCALE, 0xFFFFFFFF);
			layer_canvas_flip(&canvas);
			
		}
		
	}
	
	layer_dispose(&canvas);
	return 0;
	
}
