# -*- coding: utf-8 -*-
"""
Created on Mon Dec 10 16:23:43 2018

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

##below is to figure out M(10, d) == 8
#n = [1111111100, 1111111010, 1111110110, 1111101110, 1111011110, 1110111110,
#     1101111110, 1011111110,  111111110, 1111111001, 1111110101, 1111101101,
#     1111011101, 1110111101, 1101111101, 1011111101,  111111101, 1111110011,
#     1111101011, 1111011011, 1110111011, 1101111011, 1011111011,  111111011,
#     1111100111, 1111010111, 1110110111, 1101110111, 1011110111,  111110111,
#     1111001111, 1110101111, 1101101111, 1011101111,  111101111, 1110011111, 
#     1101011111, 1011011111,  111011111, 1100111111, 1010111111,  110111111, 
#     1001111111,  101111111,   11111111]
#
#i = 0
#end = len(n)
#left, right, temp = 0, 0, 0
#d, l, r = 8, 0, 0
#sum = 0
#while i < end:
#    temp = n[i]
##    print('start {}'.format(temp), end="\n")
#    left = 1
#    right = 1
#    while (temp % 10 != 0):
#        temp = temp // 10
##        print(temp, end=" ")
#        left *= 10
#        right *= 10
#    left *= 10
#    temp = temp // 10
##    print()
#    while (temp % 10 != 0):
#        temp = temp // 10
##        print(temp, end=" ")
#        left *= 10
##    print(left + right, end=" ")
#    
#    l = 0
#    while l < 10:
#        r = 0
#        while r < 10:
#            temp = d * n[i] + l * left + r * right
#            if prime_check(temp) == True:
#                print(temp, end=" ")
#                sum += temp
##            print(temp, end=" ")
#            r += 1
#        l += 1
#        
#    i += 1
#    print()
#print(sum)

#This below is to figure out M(10, d) == 9
left, right, tens, shift, i, j, k = 0, 0, 0, 0, 1, 0, 0
sum = 0
while i < 10:
    left = 1000000000 * i
    right = 0
    tens = 100
    shift = 1
    while (right <= (111111111 * i)):
        j = 0
        while j < 10:
            n = left + j * shift + right * i
#            print(n, end=" ")
            if prime_check(n) == True:
                print(n, end=" ")
                sum += n
            j += 1
        right = right * 10 + 1
        left = left - (left % tens)
        tens = tens * 10
        shift = shift * 10
    print()
    i += 1
print(sum)

#This was done to figure out M(10,d), and N(10, 0)
#n, tempn = 1000000000, 0
#i = 1
#while i < 10:
#    n = 1000000000 * i
#    j = 1
#    while j < 100:
#        tempn = n + j
#        if prime_check(tempn) == True:
#            print(tempn, end=" ")
#        j += 2
#    print()
#    print()
#    i += 1
 
#max = 100000
#a = [2, 3, 5, 7, 11, 13, 17, 19]
#i = 21
#j, limit, length = 0, 0, 8
#while i < max:
#    j = 1
#    limit = math.floor(math.sqrt(i))
#    while a[j] <= limit:
#        if i % a[j] == 0:
#            break
#        j += 1
#    if a[j] > limit:
#        a.append(i)
#        length += 1
#    i += 2
#
#i = 0
#while i < length:
#    print(a[i], end=" ")
#    i += 1
#print()