# -*- coding: utf-8 -*-
"""
Created on Thu Dec 13 15:07:52 2018

@author: ssuh
"""


bouncy, temp, last, toggle = 0, 0, 0, 0
nextlast, count = 0, 0
for n in range(1, 2000000):
    temp = n
#    print(temp, end=" ")
    last = temp % 10
    temp = temp // 10
    toggle = 0
    while toggle == 0:
#        print(temp, end=" ")
        nextlast = temp % 10
        if nextlast > last:
            toggle = 1
            last = nextlast
        elif nextlast < last:
            toggle = -1
            last = nextlast
        temp = temp // 10
#    print(temp, end=" ")
    while temp > 0:
        nextlast = temp % 10
#        print(temp, end=" ")        
        if nextlast > last and toggle == -1:
#            print('bouncy', end=" ")
            count += 1
            break
        elif nextlast < last and toggle == 1:
#            print('bouncy', end=" ")
            count += 1
            break
        last = nextlast
        temp = temp // 10
#    print('{} / {}'.format(count, n), end=" ")
    if (count * 100 / n == 99 and count * 100 % n == 0):
        print('{} / {}'.format(count, n))
        break
print(count)