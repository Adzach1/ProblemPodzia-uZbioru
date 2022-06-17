from numba import cuda
import sys
from random import randint
from time import time
import numpy as np

n = int(sys.argv[1])
maxNum = int(sys.argv[2])
set = []
for i in range(n):
    set.append(randint(1, maxNum))

setnp = np.asarray(set)
set_one = 0
set_two = 0
which = 0
start = time()
@cuda.jit()
def main(set, set_one, set_two, which):
    for i in range(n):
        if(set_one <= set_two):
            set_one = set_one + set[i]
            which += 0
        else:
            set_two = set_two + set[i]
            which += 1

arr = np.asarray(set)
threadsperblock = 32
blockspergrid = (arr.size + (threadsperblock - 1)) // threadsperblock
main[blockspergrid, threadsperblock](setnp, set_one, set_two, which)
end = time()
t = end-start
print("Czas wykonania: " + str(t))