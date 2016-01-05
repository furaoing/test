# utf-8
from gevent import monkey; monkey.patch_socket()
import gevent
import socket
from config import my_port
from config import max_c
import time


def handle_request(c, addr, sleep):
    while True:
        mystr = c.recv(1024)
        # c.recv is a non-blocking method
        sleep(0)
        if not mystr:
            break
        print(mystr)
        http_response = """\
        HTTP/1.1 200 OK
        Hello, World !
        """
        c.send(http_response)
        c.close()
    print("closed connection: %s" % str(addr))


def server(port, max_c):
    s = socket.socket()
    # create a socket object
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    host = "127.0.0.1"
    port = my_port
    s.bind((host, port))
    # bind our socket object to a certain port on this host

    s.listen(max_c)
    # start listening to the socket, maximum con= max_c

    while True:
        cli, addr = s.accept()
        # my_socket.accept() is a non-blocking method
        print("new connection: %s" % str(addr))
        gevent.spawn(handle_request, cli, addr, gevent.sleep)
    s.cloce()
    # s.close() will never be execuated

server(my_port, max_c)






