
#include "root.h"
#include "lib/layer.h"
#include "lib/shader.h"
#include "lib/fast/fast.h"

var main(void) {
	print("NOTE This only works for OpenGL shading language 1.2\n");
	
	if (shader_support()) {
		event_list_t events;
		
		layer_t    image;
		new_layer(&image);
		
		image.fullscreen = true;
		
		layer_set_bitmap(&image, (var*) PATH"wallpaper/wallpaper.bmp");
		layer_init      (&image);
		
		shader_program_t shader;
		new_shader_program(&shader, R"shader-code(
			#version 120
			
			void main(void) {
				gl_TexCoord[0] = gl_MultiTexCoord0;
				gl_Position    = ftransform();
				
			}
		)shader-code", R"shader-code(
			#version 120
			
			uniform sampler2D sampler_texture;
			uniform int       has_texture;
			uniform int       time;
			
			void main(void) {
				vec4 colour;
				
				if (has_texture != 0) colour = texture2D(sampler_texture, gl_TexCoord[0].st); // * gl_Color;
				else                  colour = gl_Color;
				
				if (colour.w > 0.0f) {
					float random  = fract(sin(dot(gl_FragCoord.xy / time, vec2(12.9898, 78.233))) * 43758.5453123);
					float average = (colour.x + colour.y + colour.z) / 3 * random;
					gl_FragColor = vec4(average, average, average, colour.w);
					
				} else {
					discard;
					
				}
				
			}
		)shader-code", nullptr);
		
		set_shader(&shader);
		
		while (true) {
			clear(-1, 0, -1, -1);
			layer_draw(&image);
			
			video_flip();
			get_events(&events);
			
			if (events.quit) {
				break;
				
			}
			
		}
		
		dispose_layer (&image);
		dispose_shader(&shader);
		
	} else {
		print("WARNING Shaders are not supported on this platform\n");
		
	}
	
}
