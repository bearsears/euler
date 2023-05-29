import math

def rad(n, p):
    i = 0
    tempn = n
    product = 1
    #print('n is {}.'.format(n))
    while tempn > 1:
        if tempn % p[i] == 0:
            #print(p[i], end=" ")
            product *= p[i]
            while tempn % p[i] == 0:
                tempn //= p[i]
        i += 1
    return product

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

primes = []
limit = 120000
for i in range(1, limit):
    if prime(i) == True:
        primes.append(i)
rads = [0]
for i in range(1, limit):
    rads.append(rad(i, primes))
sums = 0
limith = limit // 2 + 1
count = 0
for b in range(2, limit):
    if b % 2 == 1:
        inc = 1
    else:
        inc = 2
    a = 1
    while a < b:
        c = a + b
        if c >= limit:
            break
        if math.gcd(a, b) > 1:
            a += inc
            continue
        #print(a, b, c, result)
        if math.gcd(a, c) == 1 and math.gcd(b, c) == 1:
            if rads[a] * rads[b] * rads[c] < c:
                print(a, b, c, (a * b * c))
                count += c
        a += inc

print(count)
