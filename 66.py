# -*- coding: utf-8 -*-
"""
Created on Wed Nov 28 14:57:17 2018

@author: ssuh
"""

import math

hnmax = 1
dmax = 1

for n in range (2, 1001):
    a = 1
    while a * a < n:
        a += 1
    if a * a == n:
        continue
    a -= 1

    topleft= math.sqrt(n)
    topright = -a
    bottom = 1
    
    hn, hnm1, hnm2 = 0, 1, 0
    kn, knm1, knm2 = 0, 0, 1
    
    hn = a * hnm1 + hnm2
    kn = a * knm1 + knm2
    hnm2 = hnm1
    hnm1 = hn
    knm2 = knm1
    knm1 = kn
    
    while (hn * hn - n * kn * kn) != 1:
        a = math.floor(bottom / (topleft + topright))
        bottom = (n - topright * topright) / bottom
        topright = -1 * topright - bottom * a
        #print('a {}, topleft {}, topright {}, bottom {}'.format(a, topleft,
        #      topright, bottom))
        hn = a * hnm1 + hnm2
        kn = a * knm1 + knm2
        hnm2 = hnm1
        hnm1 = hn
        knm2 = knm1
        knm1 = kn
    
    print('{} --> x is {} and y is {}'.format(n, hn, kn))
    if hn > hnmax:
        hnmax = hn
        dmax = n

print('hnmax is {}, n is {}'.format(hnmax, dmax))
