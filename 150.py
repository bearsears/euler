# -*- coding: utf-8 -*-
"""
Created on Thu Apr 18 20:39:52 2019

@author: ssuh
"""

rows = [0, 1]
for i in range(1, 1000):
    rows.append(i + rows[-1])

#print(rows)

modulo = 2 ** 20
subtract = 2 ** 19
sk = [0]
t = 0
for k in range(1, 500501):
    t = (615949 * t + 797807) % modulo
    sk.append(t - subtract)
    
#for i in range(0, 10):
#    #print(sk[rows[i]], sk[rows[i + 1]])
#    for j in range(rows[i], rows[i + 1]):
#        print(sk[j], end='\t')
#    print()
        
what_row = 0
current_sub_row = 0
end_row = 10
maxmin = -10
for i in range(1, 500500):
    what_row = 1
    while i >= rows[what_row]:
        what_row += 1
    what_row -= 1
    count_min = 0
#    print()
    print(i, what_row)
    current_sub_row = 1
    sub_index = i
#    print(sk[sub_index])
    count_min += sk[sub_index]
    sub_index += what_row
    current_sub_row += 1
    #print(sub_index)
    while sub_index < 500500:
        for j in range(0, current_sub_row):
#            print(sk[sub_index], end='\t')
            count_min += sk[sub_index]
            sub_index += 1
        sub_index -= 1
#        print()
#        print(count_min)
        if count_min < maxmin:
            maxmin = count_min
        #print(j, sub_index, current_sub_row)
        sub_index += what_row
        current_sub_row += 1
    if count_min < maxmin:
        maxmin = count_min
    print(maxmin)

print()
print(maxmin)
    
##print(sk)
#end = 0 # sets where the last row is.
#total = 0
#for r in range(2, 1001):
#    end = 1001 - r
#    for s in range(1, end):
#        start = rows[s]
#        while start < rows[s + 1]:
#            for i in range(0, r):
#                triangle = sk[sk[start] + i]
#                total = triangle
#            total = 
#            start] += 1