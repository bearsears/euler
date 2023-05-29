# -*- coding: utf-8 -*-
"""
Created on Wed May  1 11:24:41 2019

@author: ssuh
"""

pascal = [1, 1]
end = 0
i = 0
count = 0
results = []
zeros = 0
for row in range(3, 101):
    
#    print(row, end='\t\t')
    i = len(pascal) - 1
    zeros = 0
    while i >= 0:
        #print(pascal[i], end=' ')
        i -= 1  
        if pascal[i] != 0:
            zeros += 1
    print('\t', (row - 1), '\t', zeros, ' / ', len(pascal), end=' ')
    print()
    i = len(pascal) - 1
    while i > 0:
        pascal[i] = (pascal[i] + pascal[i - 1]) % 7
        if pascal[i] == 0:
            count += 1
        i -= 1
    if (row + 1) % 7 == 0:
        results.append(count)
    pascal.append(1)   

print(count)
print(results)

sevens = [7 ** i for i in range(1, 12)]
print(sevens)
mult = 0
end = 1000000000
start = 0
end_remain = 0
total = 28
for row in range(8, end, 7):
    if sevens[start + 1] < row:
        start += 1
        print(row)
    temprow = row
    i = start 
    mult = 1
    while i >= 0:
        if temprow < sevens[i]:
            i -= 1
            continue
        mult *= (temprow // sevens[i] + 1)
        temprow %= sevens[i]        
#        tempmult = 0
#        while temprow > sevens[i]:
#            temprow -= sevens[i]
#            tempmult += 1
#        mult *= (tempmult + 1)
        i -= 1

    end_remain = end - row
    if end_remain > 7:
        total += (mult * 28)
    else:
        end_remain += 2
        for i in range(1, end_remain):
            #print('\t', row + i - 1, mult * i)
            total += mult * i
    #print(row, mult, end_remain) 
print(total)