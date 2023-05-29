# -*- coding: utf-8 -*-
"""
Created on Mon Jan 28 15:24:02 2019

@author: ssuh
"""

"""
How did I solve this
After researching about power series and convergence, the equation is
1 / (1 - r), fibonnaci is (phi^n - (1 - phi)^n ) / sqrt(5) , where
phi is a golden ratio of fibonacci. put them together
and arrived to A = x / (1 - x - x * x). Solved for x using quadratic equation,
you get x = -(1 + A) +/- sqrt(5A^2 + 2A + 1). You realize the 
sqrt(5A^2 + 2A + 1) is always a fibonacci, and solve for A using quadratic 
equation again. A = (-1 +/- sqrt(5*fib^2 - 4)) / 5
Lots of trial and error, and experiments.
"""
import math

fib = [1, 1]

for i in range(1, 150):
    fib.append(fib[i] + fib[i - 1])

print(fib)
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
"""