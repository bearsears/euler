# -*- coding: utf-8 -*-
"""
Created on Thu May  9 10:23:34 2019

@author: ssuh
"""

capacitors = {1:[(60, 1)], 2:[(30, 1), (120, 1)]}

print(capacitors[2][0][0])
print(capacitors[2][0][1])
print(len(capacitors[2]))

total_capacitor = 3
for i in range(1, (1 + total_capacitor // 2)):
    print(total_capacitor - i, i)
    