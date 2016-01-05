from gevent import monkey; monkey.patch_all()
import gevent
import urllib2


def f(url):
    print('GET: %s' % url)
    resp = urllib2.urlopen(url)
    gevent.sleep(0)
    data = resp.read()
    print('%d bytes received from %s.' % (len(data), url))


g1 = gevent.spawn(f, 'https://www.python.org/')
g2 = gevent.spawn(f, 'https://www.yahoo.com/')
g3 = gevent.spawn(f, 'https://github.com/')


g1.join()
g2.join()
g3.join()

