# -*- coding: utf-8 -*-
"""
Created on Tue Feb 12 15:46:00 2019

@author: ssuh
"""
import math

results = [0, 0]
yhits = []
y = 0
end = 2000000
endsqrs = int(math.sqrt(2 * end)) + 2
sqrs = [x * x for x in range(0, endsqrs)]
sqrs[0] = -1
#print(sqrs)

for x in range(2, end):
    print(x, end="\t")
    yhits = []
    sqrindex = int(math.sqrt(2 * x))
    y = sqrs[sqrindex] - x
    
    while y > 0:
        if sqrs[int(math.sqrt(x - y))] == (x - y):
        #if (x - y) in sqrs:
            yhits.append(y)
        sqrindex -= 1
        y = sqrs[sqrindex] - x      
        
    if len(yhits) < 2:
        continue

    while len(yhits) > 1:
        j = len(yhits) - 2
        while j >= 0:
            if sqrs[int(math.sqrt(yhits[j] - yhits[len(yhits) - 1]))] == \
                (yhits[j] - yhits[len(yhits) - 1]) and \
               sqrs[int(math.sqrt(yhits[j] + yhits[len(yhits) - 1]))] == \
                (yhits[j] + yhits[len(yhits) - 1]) :
                break
            j -= 1          
        if j == -1:
            yhits.pop()
        else:
            break
    
    if len(yhits) > 1:
        print(x, yhits)
        break

#    if count > 0:
#        print(x, yhits)

print(sqrs)