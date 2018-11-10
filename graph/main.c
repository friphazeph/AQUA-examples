#include "root.h"
#include "lib/graph.h"

#define SCALE (1 << 0)

var main(void) {
	var width  = video_width()  / SCALE;
	var height = video_height() / SCALE;
	
	graph_t graph;
	new_graph(&graph, width, height);
	
	uvar colour = 0xFFFFFFFF77770000;
	
	var old_x = width  >> 1;
	var old_y = height >> 1;
	
	event_list_t events;
	always {
		video_clear_colour(70 * (_UI64_MAX / 256), 0, -1, -1);
		video_clear();
		
		graph_draw(&graph);
		
		video_flip();
		get_events(&events);
		
		if (events.quit) {
			break;
			
		}
		
		colour += 0xFFF / video_fps();
		
		graph_circle      (&graph,    colour, width >> 2,   events.pointer_x, events.pointer_y);
		graph_line_spacing(&graph, 1, 0xFFFF00000000FFFF, old_x, old_y, events.pointer_x, events.pointer_y);
		
		old_x = events.pointer_x;
		old_y = events.pointer_y;
		
	}
	
	dispose_graph(&graph);
	return 0;
	
}
