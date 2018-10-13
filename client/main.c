
/// USE IN CONJUNCTION WITH `server` EXAMPLE

#include "root.h"

#define SERVER_IP_ADDRESS "192.168.1.37" // put your server's local or public IP address here
#define SERVER_PORT       0xA55

var main(void) {
	if (!socket_support()) {
		print("WARNING Sockets are not supported on this platform\n");
		return true;
		
	} else {
		socket_t socket;
		socket_client(&socket, (ip_address_t) SERVER_IP_ADDRESS, SERVER_PORT);
		
		if (socket.error) {
			print("WARNING Failed to connect to server (maybe \"%s:%lld\" is the incorrect IP address?)\n", SERVER_IP_ADDRESS, SERVER_PORT);
			return true;
			
		} else {
			print("Connected to server, saying hi ...\n");
			socket_send(&socket, "Hello", SOCKET_DEFAULT_BUFFER_SIZE);
			
			event_list_t events;
			
			always {
				video_flip();
				get_events(&events);
				
				if (events.quit) {
					break;
					
				} elif (events.pointer_click_type) {
					socket_send(&socket, "ping",               SOCKET_DEFAULT_BUFFER_SIZE);
					print("ping %s\n", socket_receive(&socket, SOCKET_DEFAULT_BUFFER_SIZE));
					
				}
				
			}
			
			socket_send (&socket, "exit", SOCKET_DEFAULT_BUFFER_SIZE);
			socket_close(&socket);
			
			return false;
			
		}
		
	}
	
}
