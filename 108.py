# -*- coding: utf-8 -*-
"""
Created on Tue Nov  6 15:56:35 2018

@author: ssuh

#this is super slow and took more than an hour.
count, n, start, end, multiples, divider, quotient, remainder = 0, 37440, 0, 0, 0, 0, 0, 0
while count < 1000:
    count = 0
    n += 2
    end = n * 2
    x = n
    while x <= end:
        x += 1
        remainder = (x * n) % (x - n)
        if remainder == 0:
            count += 1
            print('1 / {} + 1 / {} = 1 / {}'.format(start, multiples, quotient))
    if count > 500:
        print('{} has {} distinct solutions.'.format(n, count))

print('{} has {} distinct solutions.'.format(n, count))    

"""

#The answer has 12 prime factorials, but since my program will skip some of the
#sequences, thus the answer was skipped..
#had to go to the excel spreadsheet and hack it out.
def prime_check(x):
    if x >= 2:
        for y in range(2, x):
            if not (x % y):
                return False
    else:
        return False
    return True

def diophantine(x):
    i = 2
    result = 0
    while x > 1:
        if prime_check(i) == False:
            i += 1
            continue
        #print('why has it stopped {}, x is {}'.format(i, x))   
        while x % i == 0:
            result += 1
            x /= i
            x = int(x)
        i += 1
        result *= 10
        result = int(result)
        
        if prime_check(x) == True:
            #print('the number is {}'.format(x))
            result += 1
            result *= 10
            result = int(result)
            x /= x
            x = int(x)
    
    result = result // 10
    
    print('\t\t the number is {}'.format(result))
    sol = 1
    while result > 0:
        sol *= (2 * (result % 10) + 1)
        result = result // 10
    sol = int(sol / 2 + 1)
    print('\t\t\t\t\t {} the distinct solutions are {}'.format(i, sol))
            
#diophantine(39248283995010090)
n = 2 * 3 * 5 

prime = 5
i = 3

while prime < 42:
    i = 1       
    while i <= prime:
        print('i is {}, and n is {}. the number is {}'.format(i, n, (n * i)))
        diophantine(n * i)
        (n * i)
        i += 1
    while prime_check(i) == False:
        print('\t i is {}, and n is {}. the number is {}'.format(i, n, (n * i)))
        diophantine(n * i)
        i += 1
    n *= i
    prime = i
