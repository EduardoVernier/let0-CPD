import pylab as pl
from math import log10

f = open ("arq.txt", 'r')

fx = []
fy = []
cfy = []
sfy = []
gx = []
gy = []
cgy = []
sgy = []
hx = [0,1,2,3,4,5]
arrayKind = int (f.readline())


s1 = int(f.readline())
for i in range (4):
    x = f.readline()
    x = x.split()
    fx.append (int(x[0]))
    #print fx
    fy.append (1000000000*int(x[1])+int(x[2]))
    cfy.append (int(x[3]))
    sfy.append (int(x[4]))
    #print fy


s2 = int(f.readline())
for i in range (4):
    x = f.readline()
    x = x.split()
    gx.append (int(x[0]))
    #print gx
    gy.append (1000000000*int(x[1])+int(x[2]))
    #print gy
    cgy.append (int(x[3]))
    sgy.append (int(x[4]))

print fy
print gy

if s1 == 1:
    ss1 = "insertionSort"
elif s1 == 2:
    ss1 = "shellSort"
elif s1 == 3:
    ss1 = "bubbleSort"
elif s1 == 4:
    ss1 = "heapSort"

if s2 == 1:
    ss2 = "insertionSort"
elif s2 == 2:
    ss2 = "shellSort"
elif s2 == 3:
    ss2 = "bubbleSort"
elif s2 == 4:
    ss2 = "heapSort"

fx=map (log10,fx)
gx=map (log10,gx)
pl.subplot(311)
plot1 = pl.plot(fx,fy,'r', label = ss1)
plot2 = pl.plot(gx,gy,'b', label = ss2)
pl.xlabel("elements")
pl.ylabel("nanoseconds")
pl.legend( loc='upper left', numpoints = 1 )

pl.subplot(312)
plot3 = pl.plot(fx,cfy,'--r')
plot4 = pl.plot(gx,cgy,':b')
#pl.title("Compares")


pl.subplot(313)
plot5 = pl.plot(gx,sfy,'--r')
plot6 = pl.plot(gx,sgy,':b')
pl.show()
