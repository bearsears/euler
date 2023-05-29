# -*- coding: utf-8 -*-
"""
Created on Mon Jan 28 10:39:09 2019

@author: ssuh

This is a solution i saw from the second post of euler on this question, by
youjaes. 
"""

limit = 50000000
n = [0 for i in range(limit)]

for i in range (1, limit):
    for j in range((i // 3), (limit // 2)):
        nn = 3 * j * j + 2 * j * i - i * i
        if nn > 0:

            if nn < limit:
                n[nn] += 1
            else:
                break

asw = 0
for i in range(0, limit):
    
    if n[i] == 1:
        asw += 1
        #print(i, n[i])

print(asw)