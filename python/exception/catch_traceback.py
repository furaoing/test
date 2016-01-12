# -*- coding: utf-8 -*-

import traceback

if __name__ == "__main__":
    file_pth = "traceback.log"
    traceback_f = open(file_pth, "a")
    try:
        1/0
    except Exception, err:
        traceback.print_exc(100, traceback_f)

    print("The last statement")