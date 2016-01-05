# utf-8

import socket
import time
from config import my_port

s = socket.socket()
# create a socket object
host = socket.gethostname()
port = my_port
s.bind((host, port))
# bind our socket object to a certain port on this host

s.listen(5)
# start listening to the socket
con, addr = s.accept()
print("s.accept blocking here")
mystr = con.recv(1024)
con.close()
s.close()
