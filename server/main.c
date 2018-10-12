
#include "root.h"
#include "lib/string/strcmp.h"

var main(void) {
	if (!socket_support()) {
		print("WARNING Sockets are not supported on this platform\n");
		return true;
		
	} else {
		socket_t socket;
		socket_server(&socket, nullptr, 0xA55);
		
		var pong_count = 0;
		chr pong_message[SOCKET_DEFAULT_BUFFER_SIZE / sizeof(chr)];
		
		always {
			chr* buffer = (chr*) socket_receive(&socket, SOCKET_DEFAULT_BUFFER_SIZE);
			
			if (strcmp(buffer, "exit", SOCKET_DEFAULT_BUFFER_SIZE) == 0) {
				print("Closing connection ...\n");
				break;
				
			} elif (strcmp(buffer, "ping", SOCKET_DEFAULT_BUFFER_SIZE) == 0) {
				sprintf((char*)                    pong_message, "pong %lld", pong_count++);
				print("ping %s\n",                 pong_message);
				socket_send(&socket, (const char*) pong_message, SOCKET_DEFAULT_BUFFER_SIZE);
				
			} else {
				print("%s\n", buffer);
				
			}
			
		}
		
		socket_close(&socket);
		return false;
		
	}
	
}
