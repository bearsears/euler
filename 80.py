# -*- coding: utf-8 -*-
"""
Created on Wed Dec  5 11:20:36 2018

@author: ssuh
"""

n = 1
total = 0
while n < 100:
    n += 1
    print('n is now {}'.format(n))
    a = 1
    while a *a < n:
        a += 1
    if a * a == n:
        continue
    
    a -= 1
    total += a
    
    i = 1
    limit, temp, b = 0, 0, 0
     
    while i < 100:
        b = 0
        limit = n * 100 ** i - (a * 10) ** 2
        temp = 2 * a * 10
        while (temp + b) * b < limit:
            b += 1
        b -= 1
        a = a * 10 + b
        total += b
        i += 1
        #print('a is now {}'.format(a))
        
    #print('sum is {}'.format(total))
print('sum is {}'.format(total))