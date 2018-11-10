#include "root.h"
#include "lib/graph.h"

#define SCALE (1 << 0)

var main(void) {
	var width  = video_width()  / SCALE;
	var height = video_height() / SCALE;
	
	graph_t graph;
	new_graph(&graph, width, height);
	
	uvar colour = 0xFFFFFFFF77770000;
	var radius = width >> 2;
	
	var old_x = width  >> 1;
	var old_y = height >> 1;
	
	var float_to_radius = FLOAT_ONE / radius;
	flt rad = FLOAT(width >> 6);
	
	event_list_t events;
	
	var  degree;
	for (degree = -(FLOAT_TAU >> 1); degree < FLOAT_TAU >> 1; degree += FLOAT_TAU / ((radius * FLOAT_TAU) >> 19) * 1) {
		colour += 0xFFF     / 960;
		rad    += FLOAT_ONE / 6;
		
		graph_circle(&graph, colour, FLOAT_TO_INT(rad), \
			old_x + SIN_FLOAT(degree + (FLOAT_TAU >> 5)) / float_to_radius, \
			old_y + SIN_FLOAT(degree + (FLOAT_TAU >> 3)) / float_to_radius);
		
		video_clear();
		graph_draw(&graph);
		
		video_flip();
		get_events(&events);
		
		if (events.quit) {
			break;
			
		}
		
	}
	
	dispose_graph(&graph);
	return 0;
	
}
