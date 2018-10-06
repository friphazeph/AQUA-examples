
#include "root.h"
#include "lib/layer.h"
#include "lib/framebuffer.h"
#include "lib/fast/fast.h"

var main(void) {
	if (framebuffer_support()) {
		event_list_t events;
		
		load_image(image, PATH"test.bmp");
		layer_set_size(&image, image.width / 2, image.height / 2);
		
		texture_t     texture     = texture_create(nullptr, 24, video_width(), video_height());
		framebuffer_t framebuffer = framebuffer_create(texture);
		
		framebuffer_bind(framebuffer);
		clear(0, -1, 0, -1);
		
		layer_draw(&image);
		framebuffer_unbind();
		
		load_framebuffer(frame, texture);
		layer_set_size(&frame, frame.width / 2, frame.height / 2);
		
		while (1) {
			clear(_UI64_MAX / 2, 0, -1, -1);
			layer_draw(&frame);
			
			video_flip();
			get_events(&events);
			
			if (events.quit) {
				break;
				
			}
			
		}
		
		layer_dispose(&image);
		layer_dispose(&frame);
		
		framebuffer_remove(framebuffer);
		texture_remove    (texture);
		
		return 0;
		
	} else {
		print("WARNING FBOs are not supported on this platform\n");
		return 1;
		
	}
	
}
