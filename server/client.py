
import socket

HOST = "192.168.1.37"
PORT = 0xA55
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((HOST, PORT))

while 1:
	command = raw_input("> ")
	sock.sendall(command)
	
	if command == "exit":
		break
	
	elif command == "ping":
		print str(sock.recv(1024))

sock.close()
