# -*- coding: utf-8 -*-
"""
Created on Mon Feb 25 10:56:15 2019

@author: ssuh
"""
#stupididly done brute force

ireverse, temp, count = 0, 0, 0
odds = [1, 3, 5, 7, 9]

for i in range(1, 1000000001):
    temp = i
    if temp % 10 == 0:
        continue
    ireverse = 0
    while temp > 0:
        ireverse = 10 * ireverse + temp % 10
        temp //= 10
    #print(i, ireverse)
    sums = i + ireverse
    while sums > 0:
        if (sums % 10) not in odds:
            break
        sums //= 10

    if sums == 0:
        #print(i, ireverse, (i + ireverse))
        count += 1

print(count)