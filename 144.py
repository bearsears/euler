# -*- coding: utf-8 -*-
"""
Created on Thu Feb 21 15:19:49 2019

@author: ssuh
"""

from decimal import Decimal, getcontext
import math

getcontext().prec = 100
x = Decimal(1.4)
y = Decimal(-9.6)
m2 = Decimal(-197/14)

for i in range(0, 1000):
    print(x, y)
    print()
    m1 = Decimal(-4 * x / y)
    R = Decimal((m2 - m1) / (1 + m2 * m1))
    m3 = Decimal((m1 - R) / (1 + R * m1))
    #print(m2, m1, R, m3)
    b3 = Decimal(Decimal(y) - m3 * Decimal(x))
    #print(b3)
    
    xtemp1 = Decimal((-b3 * m3 - 2 * Decimal(math.sqrt(100 + 25 * m3 ** 2 - b3 ** 2))) / (m3 ** 2 + 4))
    xtemp2 = Decimal((-b3 * m3 + 2 * Decimal(math.sqrt(100 + 25 * m3 ** 2 - b3 ** 2))) / (m3 ** 2 + 4))
#    print(xtemp)
    if abs((abs(x) - abs(xtemp1))) > abs((abs(x) - abs(xtemp2))):
        x = xtemp1
    else:
        x = xtemp2
    
    y = m3 * x + b3
    m2 = m3
    if x < 0.01 and x > -0.01 and y > 0:
        print(x, y)
        break
    #print(x, y)

print(i)




