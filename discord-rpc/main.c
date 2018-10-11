
#include "root.h"
#include "lib/discord.h"

var main(void) {
	#define data discord_rpc_data(&rpc)
	discord_rpc_t rpc;
	
	if (new_discord_rpc(&rpc, "499960380949397507")) {
		print("WARNING Discord device does not seem to exist\n");
		return true;
		
	} else {
		data->state            = "Example program";
		data->details          = "Example of Discord RPC";
		data->large_image      = "glass";
		data->large_image_text = "Example";
		
		discord_rpc_update(&rpc);
		
		event_list_t events;
		always {
			discord_rpc_loop(&rpc);
			
			if (data->has_connection) {
				print("User connected: %s#%s\n", data->username, data->discriminator);
				
			}
			
			video_flip();
			get_events(&events);
			
			if (events.quit || events.pointer_click_type) {
				break;
				
			}
			
		}
		
		dispose_discord_rpc(&rpc);
		return false;
		
	}
	
}
