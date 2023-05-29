# -*- coding: utf-8 -*-
"""
Created on Sat May  4 12:32:59 2019

@author: ssuh
"""

def find_divisible(a, b, row):
    start = max(a, b, row)
    d = 1000000000000 
    """* a * b // start"""
    #print(a, b, c, start, d)
    start += 1
    r = 1
    for i in range(start, 200001):
        r = (r * i) % d
    if r != 0:
        print(a, b, start, d, r)

#def find_divisible(a, b, row):
#    
    

for b in range(0, 100001):
    a = 200000 - b
    #print(a, b, end=' xxx ')
    find_divisible(a, b, 0)
    