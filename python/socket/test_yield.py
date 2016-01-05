__author__ = 'rao'


def gen_1(x):
    for i in range(x):
        yield i


def createGenerator():
    print("OK")
    mylist = range(3)
    print(mylist)
    for i in mylist:
        yield i*i


g = createGenerator()
print(g.next())
print(g.next())

