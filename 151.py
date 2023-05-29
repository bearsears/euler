# -*- coding: utf-8 -*-
"""
Created on Fri Apr 19 15:23:23 2019

@author: ssuh
"""
import random
 
from decimal import *
 
d = {
    (5,) : Decimal(0)
}
 
print(type(d))
def solve(curr_size):
    if curr_size in d:
       # print(curr_size, d, d[curr_size],'curr_size', 'd', 'd[curr_size]')
        return d[curr_size]
    result = Decimal(0)
    if len(curr_size) == 1:
        result += Decimal(1)
    
    #print(list(curr_size), 'list(curr_size)')
    p = Decimal(1) / Decimal(len(curr_size))
    #print(p, 'p')
    for i in curr_size:
        #print(i)
        tmp_curr = list(curr_size)
        #print(tmp_curr, 'temp_curr')
        tmp_curr.remove(i)
        while (i < 5):
            tmp_curr.append(i + 1)
            i += 1
        #print(tmp_curr, 'temp_curr')
        tmp_curr = tuple(sorted(tmp_curr))
        #input()
        result += p * solve(tmp_curr)
    #print(result, 'result', curr_size, 'curr_size')
    d[curr_size] = result
    #print(d[curr_size], 'd[curr_size]')
    return result
 
if __name__ == '__main__':
    result = solve((2,3,4,5))
    getcontext().prec = 6
    result = +result
    print("The result is:", result)
    
#total = 3633680706
#count_so_far = 650000000

#total = 0
#count_so_far = 0
#end = 1000000
#paper_sum = 0
#length = 0
#te = [4, 2, 1]
#tt = [2, 1]
#
#for j in range(1, 19):
#    for i in range(0, end):    
#        paper = [8, 4, 2, 1, 1]
#        paper_sum = 16
#        length = 5
#        #count = 0
#        while paper_sum > length:
#            #rs = random.randint(0, length - 1)
#            #print(rs, end=', ')
#            #ssize = paper[rs]
#            #print(ssize)
#            ssize = paper.pop(random.randint(0, length - 1))
#            if ssize == 2:
#                paper.append(1)
#            elif ssize == 4:
#                paper.extend(tt)
#            elif ssize == 8:
#                paper.extend(te)
##            else:
##                count += 1
#            #print(paper)
#            paper_sum -= 1
#            #print(paper, end=' :::: ')
#            length = len(paper)
#    #        if paper_sum == length:
#    #            break
#        #print(count)
#        #print(9 - length)
#        total += 9 - length
#        #print()
#    print(total,( end * j + count_so_far) * 14)
#    print(total / ((end * j + count_so_far) * 14))
#
#
