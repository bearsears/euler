# -*- coding: utf-8 -*-
"""
Created on Tue Jan 22 15:57:48 2019

@author: ssuh
"""
import math

def pc(x):
    #pc stands for prime check
    #even numbers check, failsafes
    if x % 2 == 0 or x <= 2:
        return 0
    #odd numbers,
    limit = math.floor(math.sqrt(x)) + 1

    for y in range(3, limit, 2):
        if not (x % y):
            return 0

    return 1

a = [1, 1, 1, 1, 1, 1]
b = [2, 3, 4, 5, 6, 7]
bcorner = []
bcorner.extend(b)
c = [8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
last = c[-1] + 1
length = len(c)
spacing = 1
count = 1

#for i in range(0, 50):
while count < 100:
#    print(a, b, c)
#    print(bcorner)
#    print()
    cstart, astart, PD = -1, 0, 0
    
    for j in range(0, len(b)):
        #print(b[j], end=": ")
        if b[j] in bcorner:         
            PD += pc(abs(c[cstart] - b[j])) + pc(abs(c[cstart + 1] - b[j]))
            PD += pc(abs(c[cstart + 2] - b[j])) + pc(abs(b[j - 1] - b[j]))
            #print(abs(c[cstart] - b[j]), abs(c[cstart + 1] - b[j]))
            if j == (len(b) - 1):
                PD += pc(abs(b[0] - b[j]))
            else:
                PD += pc(abs(b[j + 1] - b[j]))
            PD += pc(abs(a[astart] - b[j]))
            cstart += 2
        else:
            PD += pc(abs(c[cstart] - b[j])) + pc(abs(c[cstart + 1] - b[j]))
            PD += pc(abs(b[j - 1] - b[j])) + pc(abs(a[astart] - b[j]))
            
            if j == (len(b) - 1):
                PD += pc(abs(b[0] - b[j]))
            else:
                PD += pc(abs(b[j + 1] - b[j]))
            
            if astart == (len(a) - 1):
                PD += pc(abs(a[0] - b[j]))
            else:
                PD += pc(abs(a[astart + 1] - b[j]))
            cstart += 1
            astart += 1
        if PD == 3:
            count += 1
            print(b[j], count)
            
        PD = 0
              
    #setting up for next cycle.    
    a = []
    a.extend(b)
    b = []   
    b.extend(c)
    
    #set up next bcorner
    bcorner = []
    j = 0
    while j < length:
        bcorner.append(b[j])
        j += spacing + 1
    spacing += 1
    
    #set up next c
    c = []
    length += 6
    for j in range(0, length):
        c.append(last)
        last += 1

    

