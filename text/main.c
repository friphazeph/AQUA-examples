
#include "root.h"
#include "lib/layer.h"
#include "lib/fast/pointer.h"

#define TITLE "Hello!"
#define SUBTITLE "This program shows off text in AQUA (ħ UTF8 support ħ)"

var main(void) {
	font_t big = new_font(PATH"fonts/main.ttf", video_width() / 20);
	font_t small = new_font(PATH"fonts/main.ttf", video_width() / 20);
	
	layer_t title;
	new_layer(&title);
	
	print("Title    width = %lld,\theight = %lld\n", get_font_width(big, TITLE), get_font_height(big, TITLE));
	
	layer_set_text(&title, big, TITLE);
	layer_init(&title);
	
	layer_t subtitle;
	new_layer(&subtitle);
	
	print("Subtitle width = %lld,\theight = %lld\n", get_font_width(small, SUBTITLE), get_font_height(small, SUBTITLE));
	
	layer_set_text(&subtitle, small, SUBTITLE);
	layer_init(&subtitle);
	
	var x = 0;
	var dir = 1;
	
	event_list_t events;
	
	while (1) {
		x += dir;
		video_clear_colour(-1, 0, x * (_UI64_MAX / 256), -1);
		video_clear();
		
		if (x >= 255) dir = -1;
		if (x <= 0) dir = 1;
		
		layer_draw(&title);
		layer_draw(&subtitle);
		
		video_flip();
		
		get_events(&events);
		
		if (events.quit) {
			break;
			
		}
		
		layer_set_xa(&subtitle, POINTER_X(events.pointer_x));
		layer_set_ya(&subtitle, POINTER_Y(events.pointer_y));
		
	}
	
	layer_dispose(&title);
	layer_dispose(&subtitle);
	
	font_remove(big);
	font_remove(small);
	
	return 0;
	
}
