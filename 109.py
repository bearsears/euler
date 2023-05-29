# -*- coding: utf-8 -*-
"""
Created on Wed Nov 21 16:13:32 2018

@author: ssuh
"""


n, tempn, count, limit1, limit2 = 100, 0, 0, 0, 0
darts = [0, 0]
for n in range(2, 100):
    print('n is {}'.format(n))
    limit1 = n
    if limit1 > 20:
        limit1 = 21
    for i in range(1, limit1):
        darts[0] = 0
        darts[1] = 0
        for j in range(1, 4):
            darts[0] = i * j
            tempn = n - darts[0]
            if tempn < 0:
                break
            elif tempn == 0 and j == 2:
                print('{}, 0, 0 /// {}, 0, 0 /// {}'.format(darts[0], j, i))
                count += 1
                break
            limit2 = n
            if limit2 > 20:
               limit2 = 21
            for k in range(1, limit2):
                for l in range(1, 4):
                    darts[1] = k * l
                    tempn = n - darts[0] - darts[1]
                    if tempn == 0 and l == 2:
                        print('{}, {}, 0 /// {}, {}, 0 /// {}, {}, 0'.format(darts[0], darts[1], j, l, i, k))
                        count += 1
                        break
                    elif tempn < 0 or tempn > 40:
                        break
                    elif tempn > 0 and tempn % 2 == 0:
                        if i > k:
                            continue
                        if i == k and j > l:
                            continue
                        else:
                            print('{}, {}, {} /// {}, {}, 2 /// {}, {}, {}'.format(darts[0], darts[1], tempn, j, l, i, k, tempn / 2))
                            count += 1
    #print('{} is the count for {}'.format(count, n))
    #count = 0
            
print('{} is the total count'.format(count))