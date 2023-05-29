import math

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

pone = 5
ptwo = 0
m = 1 
temp = 0
sums = 0

while pone < 1000000:
    ptwo = pone + 2

    while prime(ptwo) == False:
        ptwo += 2

    m = 1
    temp = pone
    while temp != 0:
        m *= 10
        temp //= 10

    n = 1
    temp = n * m + pone
    while temp % ptwo != 0:
        n += 1
        temp = n * m + pone

    sums += temp
    print(pone, ptwo, temp)
    pone = ptwo
    
print(sums)


