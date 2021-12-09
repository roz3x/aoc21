import numpy as np
steps = [0,1,3]
for i in range(3, 2000):
    steps.append(steps[-1] + i)
f = open("input", "r").read()
a = np.array([int(i) for i in f.split(',')])
sums = []
for i in range(np.min(a), np.max(a)):
    sum =0
    for j in a:
        sum += steps[abs(i-j)]
    sums.append(sum)
np.min(sums)
