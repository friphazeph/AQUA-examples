
#include "root.h"
#include "lib/fast/text.h"

var main(void) {
	font_t font = new_font(PATH"fonts/main.ttf", video_width() / 20);
	
	text_t text;
	new_text(&text, font, "Hello world!", theme_default(), 0);
	
	event_list_t events;
	while (1) {
		video_clear();
		text_draw(&text, video_fps());
		video_flip();
		
		get_events(&events);
		
		if (events.quit) {
			break;
			
		}
		
	}
	
	dispose_text(&text);
	font_remove(font);
	
	return 0;
	
}
