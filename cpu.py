import sys
from random import randint
from time import time

n = int(sys.argv[1])
maxNum = int(sys.argv[2])
set = []
for i in range(n):
    set.append(randint(1, maxNum))
start = time()
set_one = 0
set_two = 0
which = ""
for i in range(n):
    if(set_one <= set_two):
        set_one += set[i]
        #which += '0'
    else:
        set_two += set[i]
        #which += '1'
end = time()
t = end-start

print(str(set_one)+" "+str(set_two))
print("Czas wykonania: " + str(t))