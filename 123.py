import math
def find_remainder(a, nmax):
    if (nmax % 2) == 0:
        return 2
    r = 3 * 2 * a
    n = 3
    while n <= nmax:
        r = r * (n + 2) // n
        n += 2
    n -= 2
    r = r * n //(n + 2)
    return r

def prime(n):
    if n == 1:
        return False
    if n == 2 or n == 3 or n == 5 or n == 7:
        return True
    if n % 2 == 0:
        return False
    limit = int(math.sqrt(n) + 2)

    for i in range (3, limit, 2):
        if n % i == 0:
            return False
    return True

number = 15 # 71059 is a 7037th prime
order = 6
remainder = 0

while remainder < 10000000000:
    if prime(number) == True:
        order += 1
        remainder = find_remainder(number, order)
        #print('number is {}, order is {}, and remainder is {}.'.format(number,
        #    order, remainder))
    number += 2

print('number is {}, and order is {}.'.format(number, order))
