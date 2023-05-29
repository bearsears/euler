import math

def rad(n, p):
    i = 0
    tempn = n
    product = 1
    while tempn > 1:
        if tempn % p[i] == 0:
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
limit = 100001
for i in range(1, limit):
    if prime(i) == True:
        primes.append(i)

rads = [0]
for n in range(1, limit):
    rads.append(rad(n, primes))

print(rads)

for key in range(1, limit):
    rank = 1
    mrad = rad(key, primes)
    for n in range(1, limit):
        if n == key:
            continue
        if mrad > rads[n]:
            rank += 1
        elif mrad == rads[n] and key > n:
            rank += 1
    print(key, rank)
    if rank == 10000:
        break

