# utf-8

import socket
from config import my_port
from config import my_host

s = socket.socket()

port = my_port
host = my_host

s.connect((host, port))
print("Connection Established at " + str(host) + "   " + str(port))
while True:
    msg = raw_input()
    s.send(msg)

s.close()
