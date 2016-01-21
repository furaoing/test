# -*- coding: utf-8 -*-

import traceback


def my_readline(f_pth):
    my_f = open(f_pth, "r")
    while True:
        s = my_f.readline()
        if not s:
            my_f.close()
            break
        yield s

for x in my_readline("test"):
    print(x)
    print(len(x))

if __name__ == "__main__":
    """
    file_pth = "traceback.log"
    traceback_f = open(file_pth, "a")
    try:
        1/0
    except Exception, err:
        traceback.print_exc(100, traceback_f)

    print("The last statement")
    """