# -*- coding: utf-8 -*-
"""
Created on Sat Apr  6 10:14:10 2019

@author: ssuh
"""

def return_cross_square(col, row):
    ccol = col - 2
    crow = row - 2
    #can't have negative dimensions, 
    #it can happen for slim boxes.
    if ccol < 0:
        ccol = 0
    if crow < 0:
        crow = 0
    side = 2 + ccol + crow
    if row == 1:
        side -= 1
    #print(side, ccol, crow)
    csquare = [[1 for x in range(side)] for y in range(side)]
    
    for i in range(0, crow):
        maxi = crow - i
        for j in range(0, maxi):
            csquare[i][j] = 0
            csquare[side - 1 - j][side - 1 - i] = 0
            
    for i in range(0, ccol):
        maxi = ccol - i
        for j in range(0, maxi):
            csquare[i][side - 1 - j] = 0
            csquare[side - 1 - j][i] = 0
            
#    for i in range(0, side):
#        for j in range(0, side):
#            print(csquare[i][j], end=' ')
#        print()
    
    return csquare

def count_cross_square(startx, starty, endx, endy, cs):

    for y in range(starty, endy):
        for x in range(startx, endx):
            #no need to count every square, return false at first sign of 0
            if cs[y][x] == 0:
                return False
    return True

total = 1 #1 is for 1 x 1,
xend, yend = 48, 44 #increment 1 more than the specification. 

for x in range(2, xend):
    for y in range(1, yend):
        if y > x:
            break
        print(x, y)
        csqr = return_cross_square(x, y)
        length = len(csqr)
#        for i in range(0, length):
#            for j in range(0, length):
#                print(csqr[i][j], end=' ')
#            print()
        
        square_sizes = []
        for i in range(1, length + 1):
            for j in range(i, length + 1):
                square_sizes.append([i, j])
        
        larger_squares_count = 0
        for i in range(0, x):
            for j in range(0, y):
                larger_squares_count += (x - i) * (y - j)
            
        smaller_squares_count = 0
        for i in range(0, len(square_sizes)):
            area = square_sizes[i][1] * square_sizes[i][0]
            #print(square_sizes[i], area)
            for j in range(square_sizes[i][0], length + 1):
                for k in range(square_sizes[i][1], length + 1):
                    startx = k - square_sizes[i][1]
                    starty = j - square_sizes[i][0]
                    if count_cross_square(startx, starty, k, j, csqr) == True:
                        #below is to check for symmetry
                        if square_sizes[i][0] != square_sizes[i][1]:
                            smaller_squares_count += 2
                        else:
                            smaller_squares_count += 1
                    #print(j, k, '-', starty, startx, '-->', temp, end='\t\t')
                #print()
        
        print('The total larger square in is', larger_squares_count) 
        print('The total smaller square in cross square is', smaller_squares_count)
        total += (larger_squares_count + smaller_squares_count)
        #take advantage of symmetry 3 x 2 is same as 2 x 3.
        if x > y and x < yend:
            #print('in the if statement')
            total += (larger_squares_count + smaller_squares_count)

print(total)  