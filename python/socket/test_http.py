import socket
import time

HOST, PORT = '', 8891

listen_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#listen_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
listen_socket.bind((HOST, PORT))
listen_socket.listen(1)
# listening to the specified socket, all incoming connection will be queued
print 'Serving HTTP on port %s ...' % PORT
while True:
    client_connection, client_address = listen_socket.accept()
    # Establish a tcp connection, assign a python object to represent this connection
    print("Tcp Connection Established")
    print("Client Address:" + str(client_address) + "\n")
    request = client_connection.recv(1024)
    print request
    print("Processing Request")
    http_response = """\
HTTP/1.1 200 OK

Hello, World!
"""
    client_connection.sendall(http_response)
    client_connection.close()
    print("\nConnection Closed\n")
