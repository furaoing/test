# utf-8

import socket
from config import my_port
from config import my_host
import random
import string
import time


s = socket.socket()

port = my_port
host = my_host

s.connect((host, port))
print("Connection Established at " + str(host) + "   " + str(port))
count = 0
for i in range(1000):
    test_str = "".join(random.choice(string.ascii_letters) for j in range(5))
    s.send(test_str)
    count += len(test_str)
    time.sleep(0.001)

print("ALL CHAR Count:" + str(count))

time.sleep(10)
s.send("Msg after 10s pause")

s.close()
