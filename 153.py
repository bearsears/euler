# -*- coding: utf-8 -*-
"""
Created on Thu Apr 25 19:24:33 2019

@author: ssuh
"""
import math
x = 1
y = 1
z = complex(1, 1)

print(4 / z)
s = 0
for n in range(1, 29):
    print(n, end=' = ')
    for x in range(1, (n + 1)):
        for y in range(0, n):
#            if (x * x + y * y) > n:
#                break
            z = n / complex(x, y)
            if z.real != round(z.real) or z.imag != round(z.imag):
                continue
#            print(z.real, float(int(z.real)))
            print(x, y, z, end=' ')
            if z.imag == 0:
                s += z.real
            else:
                s += z.real * 2
    print()
print('s', s)
end = 100000000
yend = 0
lmin = 0
gden = 0
mult = 0
total = 0
temp = 0
for x in range(1, end):
    yend = x + 1
    for y in range(0, yend):
        gden = math.gcd(x, y)
        if gden > 1:
            continue      
        lmin = x ** 2 + y ** 2
        if lmin > end:
            break
        temp = 0
        lend = end // lmin + 1
        xy = x + y
        #print(x, y, lmin, lend, xy, end='\t\t')
        for i in range(1, lend):
            mult = end // (lmin * i)
            temp += mult * i * xy
        if x != y and y != 0:
            temp *= 2
        total += temp
        
        
#        #print(x, y, lmin)
#        #print(x, y, lmin)
#        if lmin > end:
#            continue
#        mult = end // lmin
#        temp = mult * x + mult * y
#        if x != y and y != 0:
#            temp *= 2
#        total += temp
#        print(x, y, temp, total)
    
print(total)

        
        