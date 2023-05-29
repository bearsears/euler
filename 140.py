# -*- coding: utf-8 -*-
"""
Created on Tue Feb  5 10:01:55 2019

@author: ssuh
"""


"""
How did I solve 137
After researching about power series and convergence, the equation is
1 / (1 - r), fibonnaci is (phi^n - (1 - phi)^n ) / sqrt(5) , where
phi is a golden ratio . put them together
and arrived to A = x / (1 - x - x * x). Solved for x using quadratic equation,
you get x = -(1 + A) +/- sqrt(5A^2 + 2A + 1). You realize the 
sqrt(5A^2 + 2A + 1) is always a fibonacci, and solve for A using quadratic 
equation again. A = (-1 +/- sqrt(5*fib^2 - 4)) / 5
Lots of trial and error, and experiments.

How I solve 140
first solve fib = (a * phi^n - b * (1 - fib)^n) / sqrt(5) then find
a = (3 * sqrt(5) - 1) / 2, b = (-3 * sqrt(5) - 1) / 2
solve for series convergence using  1 / (1 - r), then get to generating 
function of A = (3 - 2x) / (1 - x - x^2) - 3. let A3 = A + 3
Strangely solving for x  = ((2 - A3) + sqrt(5 * A3 ^ 2 - 16 * A3 + 4)) / 2 * A3
This time, sqrt(5 * A3 ^ 2 - 16 * A3 + 4) is modified fibonnacci or the 
(ans[length - 1] * ans[length - 2]) // ans[length - 3]
Solve for the A3, then you get A3 = ( 8 + sqrt(44 + 5 * modfib ^ 2)) / 5
Another painful one.
"""
import math

fib = [1, 4]

for i in range(1, 100):
    fib.append(fib[i] + fib[i - 1])

print(fib)
    
Ag = []
ans = []

for A in range(1, 1000000):
    a3 = A + 3
    quad = 5 * a3 * a3 - 16 * a3 + 4
    sqr = int(math.sqrt(quad))
    if sqr * sqr == quad:
        print(A, a3, quad, sqr) 
        Ag.append(A)
        ans.append(sqr)
    
print(Ag)
print(ans)

for i in range(0, 16):
    length = len(ans)
    print(length)
    if length % 2 == 0:
       nans = (ans[length - 1] * ans[length - 2]) // ans[length - 3] + 1
       quad = 0
       for j in range(1, 10):
           quad = 44 + 5 * nans * nans
           sqr = int(math.sqrt(quad))
           if sqr * sqr == quad:
               break
           nans -= 1
       nAg = (8 + sqr) // 5
       print(nAg, nans)
       Ag.append(nAg - 3)
       ans.append(nans)
    else:
        nans = fib[fib.index(ans[length - 2]) + 4]
        nAg = (8 + int(math.sqrt(44 + 5 * nans * nans))) // 5
        print(nAg, nans)
        Ag.append(nAg - 3)
        ans.append(nans)
    
print(Ag)
print(ans)
print(len(Ag))
print(sum(Ag))
       
     

#a3 = 211345368
#quad = 5 * a3 * a3 - 16 * a3 + 4
#print(A, a3, quad, math.sqrt(quad)) 

"""
sqr = 2
A = 0
for i in range(2, 150):
    quad = 5 * fib[i] * fib[i] - 4
    A = int(math.sqrt(quad))
    #print(fib[i], A)
    if A * A == quad:
        A -= 1
     #   print(A)
        if A % 5 == 0:
            A //= 5
            print(fib[i], A)
            

phi = (1 + math.sqrt(5))/2
modfib = 0
for i in range(1, 20):
    modfib = ((3 * math.sqrt(5) - 1) * phi ** i - 
              (-3 * math.sqrt(5) - 1) * (1 - phi) ** i) / (2* math.sqrt(5))
#    modfib = (phi ** i - (1 - phi) ** i) / math.sqrt(5)
    print(i, modfib)
"""
