
#include "root.h"
#include "lib/ratio.h"

#define STRING "Hello world!"

var main(void) {
	font_t font = new_font(PATH"fonts/main.ttf", video_width() / 20);
	texture_t texture = create_texture_from_font(font, STRING);
	
	var width  = ratio_x(get_font_width( font, STRING));
	var height = ratio_y(get_font_height(font, STRING));
	
	surface_t surface;
	surface_new(&surface, -(width / 2), -(height - 2), width, height);
	
	surface_set_texture(&surface, texture);
	
	event_list_t events;
	while (1) {
		video_clear();
		surface_draw(&surface);
		video_flip();
		
		get_events(&events);
		
		if (events.quit) {
			break;
			
		}
		
	}
	
	texture_remove(texture);
	font_remove(font);
	surface_free(&surface);
	
}
