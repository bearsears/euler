# -*- coding: utf-8 -*-
"""
Created on Thu Feb  7 12:00:59 2019

@author: ssuh
"""
count = 0

import math

d = 0

for i in range(2, 1000000):
    n = i * i 
    limit = int(math.sqrt(i)) + 1
    for r in range(1, limit):
        if n % r == 0:
#            print(n, i, limit, r)
            r2 = r * r
            for m in range(1, 4):
                d3 = (n * m * r2 - (m * r2) ** 2) 
                d = int(d3 ** (1 / 3)) + 1
#                print(d)
                if d ** 3 != d3:
                    continue
                if d <= (m * r2):
                    continue
                if d3 % (m * r2) == 0:
                    print(n, i, d3, d, r2, m)
                    count += n
                    break

print(count)
"""
for i in range(2, 1000000):
    for j in range(1, i):
        if (i * i) % j == 0:
            k = (i * i) // j
            n = k * i + j
            sqr = int(math.sqrt(n))
            if sqr * sqr == n:
                print(n, k, i, j)
                break

#sqrd = [x * x for x in range(1, 1000001)]
#print(sqrd)

dqr = [0, 0, 0]
count = 0

for limit in range(1, 10000):
    n = limit * limit
#    if n % 9 != 0:
#        continue
    for d in range(1, limit):
        if n % d == 0:
            continue
        
        dqr[0] = d
        dqr[1] = n // d
        dqr[2] = n % d
        dqr.sort()
        ratio1 = int(100000000 * dqr[1] / dqr[0])
        ratio2 = int(100000000 * dqr[2] / dqr[1])
        if ratio1 == ratio2:
            print(d, n // d, n % d)
            print(n, limit, dqr,  dqr[1] / dqr[0], dqr[2] / dqr[1])
            count += n
print(count)
"""