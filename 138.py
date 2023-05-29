# -*- coding: utf-8 -*-
"""
Created on Fri Feb  1 16:38:19 2019

@author: ssuh
"""
import math
L = 305
dvd = 305
dvs = 38
total = 17

for i in range(1, 12):
    total += L
    print(L, end="\t")
    dvd = L
    b = int(math.sqrt(5 * L * L - 1))
    temp = b
    L = b * dvd // dvs
    dvs = temp
    
print(total)
"""
while L in range(17, 1000000000):
    quad = 5 * L * L - 1
    b = int(math.sqrt(quad))
    if b * b == quad:
        b1 = 2 * b - 4
        b2 = 2 * b + 4
        if b1 % 5 == 0 or b2 % 5 == 0:
            print(L, b, b1, b2)
            L = b * 8
    L += 1
"""