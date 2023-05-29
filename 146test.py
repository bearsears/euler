# -*- coding: utf-8 -*-
"""
Created on Tue Mar  5 17:07:49 2019

@author: ssuh
"""
import math

def prime_check(x):
    #even numbers check, failsafes
    if x % 2 == 0 or x <= 2:
        return False
    #odd numbers,
    limit = math.floor(math.sqrt(x)) + 1

    for y in range(3, limit, 2):
        if not (x % y):
            return False

    return True

i = 0
inc = [1, 3, 7, 9, 13, 27]
n10 = 0
for n in range(100001, 200000, 2):
#    n10 = n * 10
#    if n10 % 3 == 0 or n10 % 7 == 0 or n10 % 13 == 0:
#        continue 
    nsq = n * n * 100
    if nsq % 3 != 1 and nsq % 7 != 2:
        continue
    for i in range(0, len(inc)):
        if prime_check(nsq + inc[i]) == False:
            break
    if i == len(inc) - 1:
        print(n, nsq, nsq + inc[0], nsq + inc[1], nsq + inc[2], nsq + inc[3], \
              nsq + inc[4], nsq + inc[5])

"""
for n in range(1000000, 2000001, 10):
    nsq = n * n
    for i in range(0, len(inc)):
        if prime_check(nsq + inc[i]) == False:
            break
    if i == len(inc) - 1:
        print(n, nsq, nsq + inc[0], nsq + inc[1], nsq + inc[2], nsq + inc[3], \
              nsq + inc[4], nsq + inc[5])
"""