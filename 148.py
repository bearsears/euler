# -*- coding: utf-8 -*-
"""
Created on Tue Apr  9 13:54:31 2019

@author: ssuh
"""
import math


#def trimmed_sum(n, rows):
#    total = 0
#    for i in range(0, rows):
#        total += n
#        n -= 1
#    return total
#
pascal = [1, 3]
end = 1000000000
count = 0
#for i in range(5, (end + 1)):
#    last = pascal[-1]
#    j = len(pascal) - 1
#    streak = 0
#    while j > 0:
#        pascal[j] = pascal[j] + pascal[j - 1]
#        j -= 1 
#    if i % 2 != 0:
#        pascal.append(last * 2)  
#    for j in range(0, len(pascal)):
#        if pascal[j] % 7 == 0:
#            #print(pascal[j], end='* ')
#            count += 1
#        #else:
#            #print(pascal[j], end='  ')
#    if i % 2 != 0:
#        j = len(pascal) - 2
#    else:
#        j = len(pascal) - 1
#    while j >= 0:
#        if pascal[j] % 7 == 0:
#            #print(pascal[j], end='* ')
#            count += 1
#        #else:
#            #print(pascal[j], end='  ') 
#        j -= 1
#    #print()
#    print((i - 1), count, end=' :: ')

print()
print(count)
sevens = []
sevensums = []
temp = 0
i = 7
while i < 1000000000:
    sevens.append(i)
    temp = i - 1
    sevensums.append(i * ((i - 1) // 2))
    i *= 7
print()
print(sevens)
print(sevensums)
print()

total = 0
line_total = 0
start = 0
n, d, r, m = 0, 0, 0, 0
line = 0
seed = 1
nseed = 1
for i in range(0, 1):
    seed = 1
    line = 0
    line_total = 0
    while line < end:
        for j in range(1, 8):
            nseed = seed * j
            for k in range(1, 7):
                line += sevens[i]
                if line >= end:
                    break
                line_total += nseed * k
                print(line, (nseed * k), end=' ::: ')
            line += sevens[i]
            if line >= end: break
            print()
        seed += 1
    print(line_total * sevensums[i])
    total += line_total * sevensums[i]
print(total)
total = 0
#from this code below found a hopefully correct, and definitely faster method.
#6th attempt
for i in range(7, end, 7):
    j = 9 #9 is the end of the sevens
    while sevens[j] > i:
        j -= 1
    n = i 
    m = 1
    #print(n, end=' --> ')
    while n != 0:
        d = n // sevens[j]
        n = n % sevens[j] 
        m *= (d + 1)
        j -= 1
        #print(n, m, end=' --> ')        
    m = (m // (d + 1)) * d
    j += 1
    #print(sevens[j], m)
    total += m * sevensums[j]

print(total)
print(500000000500000000 - total)

# works up to row 343and  it is slow... this is a 5th attempt
#for i in range(7, end, 7):
#    j = len(sevens) - 1
#    while sevens[j] > i:
#        j -= 1
#    start = j
#    n = i
#    print(n, end=' => ')
#    end_count = end - i
#    if end_count > 7:
#        end_count = 8
#    else:
#        end_count += 1       
#    while j >= 0:
#        if j == start or j == 0:
#            d = n // sevens[j]
#            r = n % sevens[j]        
#        else:
#            d = (n // 2) // sevens[j]
#            r = (n // 2) % sevens[j]
#        row_total = d * sevens[j] - d * r   
#        print(n, d, r, row_total, sevens[j], end=' => ')
#        n = n - row_total
#       
#        for k in range(1, end_count):
#            total += row_total - d * k
#        
#        j -= 1
#    #print(i, total, end=' => ')
#    print()


##Below is another failure attempt ^ ^ third or fourth try. 

#print()
#print(count)
#sevens = []
#sevensums = []
#temp = 0
#i = 7
#while i < 1000000000:
#    sevens.append(i)
#    temp = i - 1
#    sevensums.append(i * ((i - 1) // 2))
#    i *= 7
#print()
#print(sevens)
#print(sevensums)
#print()
#j = 0
#total = 0
#end = 1000000000
#spaces = 0
#for i in range(7, end, 7):
#    j = len(sevens) - 1
#    while sevens[j] > i:
#        j -= 1
#    #print(i, sevens[j])
#    spaces = i // sevens[j] + 1
#    if i % sevens[j] == 0:
#         total += sevensums[j] * (i // sevens[j])
#    
#    temp = i - sevens[j] * (i // sevens[j])
#    j -= 1
#    #print(temp, total)
#    
#    while j >= 0:
#        if temp % sevens[j] == 0:
#            total += sevensums[j] * spaces * (temp // sevens[j])
#        temp -= sevens[j] * (temp // sevens[j])
#        j -= 1
#    #print(total)

    
#j = len(sevens) - 1
#while sevens[j] > end:
#    j -= 1
#spaces = end // sevens[j] + 1
#for i in range(1, ((sevens[j] * (end // sevens[j] + 1))) - end):
#    print(i, total, end=' ')
#    total -= i * (end // sevens[j])
#
#end = end - sevens[j] * (end // sevens[j])
#print(end)
#while j > 0:
#    while sevens[j] > end:
#        j -= 1
#        if j  < 0:
#            break
#    if j < 0:
#        break
#    print(sevens[j])
#    for i in range(1, (sevens[j] * (end // sevens[j] + 1)) - end - 1):
#        print(i, total, end=' ')
#        total -= i * spaces * (end // sevens[j])
#    end -= sevens[j] * (end // sevens[j])

#while j > 0:
#    while sevens[j] > temp:
#        j -= 1
#    if j < 0:
#        break
#    print(sevens[j], end // sevens[j])
#    for i in range(1, ((sevens[j] * (temp // sevens[j] + 1)) - end - 1)):
#        print(i, end=' ')
#        total -= i * (end // sevens[j])
#    temp -= sevens[j] *(temp // sevens[j])
#    print(temp)
#    j -= 1



#second attempt below
#fseven, mtp, sqd, discount = 0, 0, 0, 0
#total = 0
#
#for r in range(1, 100):
#    if r % 7 == 0:
#        fseven = 6
#        mtp = r // 7 - discount
#        if r % 49 == 0:
#            sqd = r - 1
#            discount = r // 7
#            mtp = mtp - discount
#        total += fseven * mtp + sqd
#        print(fseven, mtp, total, fseven * mtp)
#        if discount > 0:
#            discount -= 1
#    else:
#        total += fseven * mtp + sqd
# 
#          
#    if fseven > 0:
#        fseven -= 1
#    if sqd > 0:
#        sqd -= 1
#    print('row', r, 'total', total)
    
  
#below is all the test codes to get an idea about the problem.
#total = 0
#discount = 0
#end = 101
#
#for i in range(8, end, 7):
#    #any multiples of 49 a squared 7, will have its row all divisible.
#    temp = int(math.sqrt(i - 1))
#    if (i - 1) % 49 == 0:
#        discount = temp - 1
#        temp = (i - 2)
#        while temp > 0:
#            total += temp
#            temp -= 1
#        print(discount, i - 1)
#        continue
#
#    total += 21 * ((i - 1) // 7 - discount)
#    print(discount, i - 1, (i - 1) // 7, total)
#    if discount > 0:
#        discount -= 1
#    #deal with runoffs at the end of row. 
#    if (end - i) < 7:
#        temp = 6 - (end - i)
#        while temp > 0:
#            total -= temp * ((i - 1) // 7 - discount)
#            temp -= 1
#
#x = ((end - 1) // 49 ) * 49
#discount_runoffs = 2 * x - end
#print(x, discount_runoffs)
#while discount_runoffs > 0:
#    total -= discount_runoffs
#    discount_runoffs -= 1
#  
#print(total,  5050 - total ) 
#
