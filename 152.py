# -*- coding: utf-8 -*-
"""
Created on Sun Apr 21 15:48:13 2019

@author: ssuh
"""

#something about the pronic number, 420, and its multiples of three...
#found this number as I was trying to find a method to avoid decimals.. 
n = []
q = []
results = []
sqrs = [0 for x in range(0, 81)]

def pronic_recurse(limit, start, total, s_str):
    #print('working?', end=' ')
    if total > limit:
        return 
    elif total == limit:
        if s_str in results:
            return
        temp = s_str.split(',')
        temp.pop(0)
        #print(temp)
#        for i in range(0, len(temp)):
#            if int(temp[i]) == 13:
#                print(temp)
#            sqrs[int(temp[i])] += 1
        print('found', s_str, end='          ')
        results.append(s_str)
        return
    for i in range(start, end):
        pronic_recurse(limit, (i + 1), (total + q[start]), (s_str + ',' + n[start]))
    return

for i in range(32760, 32761, 60):
    pronic = i
    print('Pronic number is ', pronic, end='          ')
    n = []
    q = []
    for j in range(2, 81):
        if pronic % j == 0:
            n.append(str(j))
            q.append((pronic * pronic) // (j * j))
    print(n, q)
    end = len(q)
    pronic_recurse((pronic * pronic) // 2, 0, 0, "")
    print(len(results))    
print(len(results))
print(sqrs)

for i in range(0, len(sqrs)):
    if sqrs[i] != 0:
        print(i, end=' ')

#will work but it is slow, will take eternity
#def use_recurse2(start, up, down, s):
#
#    if up == 1 and down == 2:
#        print(s)
#        return
#    elif down // up == 1:
#        return    
#    for i in range(start, 46):
#        tempup = up * i * i + down
#        tempdown = down * i * i
#        temp = math.gcd(tempup, tempdown)
#        #print(tempup, tempdown, temp)
#        #5input()
#        tempup //= temp
#        tempdown //= temp
#        use_recurse2((i + 1), tempup, tempdown, s + str(i) + ',')
#    return
#
#use_recurse2(3, 1, 4, "2,")
    
#using decimal is not accurate, and adding more precision 
#exponentially increases time.
#def use_recurse(start, current, s_str):
#    if current == Decimal(1 / 2) :
#        print(current)
#        print(s_str)
#        return
#    elif current > Decimal(1 / 2):
#        return
#    
#    for i in range(start, 46):
#        #print(Decimal(1) / Decimal(start * start))
#        use_recurse((i + 1), current + Decimal(1 / (start * start)),
#                    s_str + str(i) + ',')
#    
#    return
#
#if __name__ == '__main__':
#    getcontext().prec = 11 
#    use_recurse(2, Decimal(0), "")

    
        
        