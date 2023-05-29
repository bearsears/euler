# -*- coding: utf-8 -*-
"""
Created on Mon Feb 25 15:24:57 2019

@author: ssuh
"""

from bisect import bisect_left
import math

#distincts = [[195, 264, 325]]
#print(distincts)
#distincts.append([264, 325, 440])
#print(distincts)
#print(distincts[1][1])

#qsieve = [x for x in range(0, 40001)]
#print(qsieve)
squares = [x * x for x in range(0, 70000)]
#print(squares)

def triangle_check(a, b, c, p, q, r):
    constant = math.sqrt(3) / 2
    #calculate angle B, C, A
    Ba = math.asin(constant * q / a) + math.asin(constant * p / c)
#    print(q, r, p, a, b, c)
    if math.degrees(Ba) >= 120:
        return False
    Ca = math.asin(constant * p / b) + math.asin(constant * r / a) 
    if math.degrees(Ca) >= 120:
        return False
    Aa = math.asin(constant * q / b) + math.asin(constant * r / c)
    if math.degrees(Aa) >= 120:
        return False
    is_it_180 = (math.degrees(Ba + Ca + Aa))
    print(is_it_180)
    is_it_180 = int(is_it_180)    
    if is_it_180 == 180 or is_it_180 == 179:
        return True
    return False

distincts = [[195, 264, 325], [264, 325, 440], [360, 1015, 3864],
            [384, 805, 1520], [435, 1656, 4669], [455, 1824, 2145], #20945
            [520, 3105, 8184], [688, 5187, 21840], [765, 1064, 5016],
            [817, 3440, 25935], [885, 9499, 12600], [1272, 2065, 4928], #128752
            [1357, 1800, 19320], [1785, 8415, 11704], [3128, 16320, 24955],
            [3264, 4991, 26040], [3515, 6528, 14800], [3864, 7296, 15295], #303129
            [4200, 10880, 15211], [4256, 5005, 20064], [4784, 5565, 59731],
            [5096, 11520, 30429], [5400, 5423, 57960], [5985, 8640, 12376], #575654
            [6307, 6765, 7208], [7616, 8415, 11704], [7752, 17575, 32640], 
            [9425, 21063, 30160], [13464, 27265, 39360], [16120, 28119, 38976], #905948
            [16575, 16905, 35728], [17424, 32725, 33915], [19600, 26741, 31395], 
            [20520, 29393, 42432]] #1229301

temp = 0
for i in range(0, len(distincts)):
    print(sum(distincts[i]))
    temp += sum(distincts[i])
print(distincts, temp)

"""

#for i in range(2, len(distincts)):  
#    q = distincts[i][0]
#    print(q)
#    while q < qend:
#        q += distincts[i][0]
#        rend = (end - q) // 2
#        for r in range((q + 1), rend):
#            a2 = q * q + r * r + q * r
#            temp = bisect_left(squares, a2)
#            if temp == len(squares) or squares[temp] != a2:      
#                continue
#                #print(temp, a2, q, r, p)
#            a = temp
#            pend = end - q - r
#            for p in range((r + 1), pend):
#                b2 = q * q + p * p + q * p
#                temp = bisect_left(squares, b2)
#                if temp == len(squares) or squares[temp] != b2:
#                    continue
#                b = temp
#                c2 = p * p + r * r + p * r
#                temp = bisect_left(squares, c2)
#                if temp == len(squares) or squares[temp] != c2:
#                    continue         
#                c = temp
#                
#                j = 0
#                while j < len(distincts):
#                    if distincts[j][0] > q:
#                        break
#                    j += 1
#            
#                for temp in range (0, j):
#                    if (r / q) == (distincts[temp][1] / distincts[temp][0]) and \
#                        (p / q) == (distincts[temp][2] / distincts[temp][0]):
#                        break
#
#                if temp < j:
#                    continue
#
#                print(q, r, p, a, b, c)
#                print(r / q, p / q)
#                if triangle_check(a, b, c, p, q, r) == True:
#                    qtemp = q
#                    sums += (q + r + p)   
#                print(sums)    
#                print()
#                break                  
#    print(sums)  


sums = 20785906
end = 1200001
qend = end // 3 
rend, pend = 0, 0
a2, b2, c2 = 0, 0, 0
a, b, c = 0, 0, 0
for q in range(27191, qend):
#    if qsieve[q] == 0:
#        continue
    rend = (end - q) // 2
    if q * 11 < rend:
        rend = q * 11
        
    for r in range((q + 1), rend):
        a2 = q * q + r * r + q * r
        temp = bisect_left(squares, a2)
        if temp == len(squares) or squares[temp] != a2:      
            continue
            #print(temp, a2, q, r, p)
        a = temp
        pend = end - q - r
        if r * 32 < pend:
            pend = r * 32

        for p in range((r + 1), pend):
            b2 = q * q + p * p + q * p
            temp = bisect_left(squares, b2)
            if temp == len(squares) or squares[temp] != b2:
                continue
            b = temp
            c2 = p * p + r * r + p * r
            temp = bisect_left(squares, c2)
            if temp == len(squares) or squares[temp] != c2:
                continue         
            c = temp
            print(q, r, p, a, b, c)
            print(r / q, p / q)
            if triangle_check(a, b, c, p, q, r) == True:
#                qtemp = q
#                while qtemp < len(qsieve):
#                    qsieve[qtemp] = 0
#                    qtemp += q
                sums += (q + r + p)   
            print(sums)    
            print()
            break
#print(qsieve)                   
print(sums)     

"""