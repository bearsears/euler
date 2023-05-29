# -*- coding: utf-8 -*-
"""
Created on Tue Jan 22 15:57:48 2019
I've realized that the only the number on the top of the ring and the 
next bottom right number has any chance of PD == 3
Then skip the rest and jump to next ring.
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

acol = 21
bcol = [2, 8]
ccol = [19, 37]
dcol = 36

spacing = 12
count = 3
PD = 0

while count <= 2000:
    PD = pc(acol - bcol[1]) + pc(ccol[0] - bcol[1]) + pc(ccol[1] - bcol[1])
    if PD == 3:
        print(bcol[1], count)
        count += 1
    
    PD = pc(dcol - ccol[0]) + pc(ccol[0] - bcol[1]) + pc(ccol[0] - bcol[0])
    if PD == 3:
        print(ccol[0], count)
        count += 1
    
    #to the next increment
    acol = acol + spacing + 6
    bcol[0] = bcol[1]
    bcol[1] += spacing
    ccol[0] = ccol[1]
    ccol[1] += (spacing + 12)
    dcol += (spacing + 12)
    spacing += 6
"""
while spacing < 40:
    #print(a, end=" ")
    a = a + spacing * 6
    print(a, (a - 1), end=" ")
    print()
    spacing += 
"""