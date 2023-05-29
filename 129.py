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

n = 999999
rem = 1 
count = 0

while count < 1000000:
    n += 2

    if math.gcd(n, 10) != 1:
        continue

    rem = 1
    count = 1
    while rem != 0:
        rem = rem * 10 + 1
        rem = rem % n
        count += 1
    
    print(count, n)
