# utf-8

import socket
from config import my_port


for i in range(100):
    s = socket.socket()
    host = socket.gethostname()
    print(host)
    port = my_port

    s.connect((host, port))
    print("Connection Established at " + str(host) + "   " + str(port))

