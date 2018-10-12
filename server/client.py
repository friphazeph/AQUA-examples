
import socket

HOST = raw_input("What is the server's IP address? ")
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
