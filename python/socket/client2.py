# utf-8

import socket
from config import my_port


s = socket.socket()
host = socket.gethostname()
print(host)
port = my_port

s.connect((host, port))
while True:
    msg = raw_input()
    s.send(msg)

s.close()
