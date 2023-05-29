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

p = 0
count = 0
nextc = 1
i = 0

while p < 1000000:
    p = 3 * i * i + 3 * i + 1
    if prime(p) == True:
        print(p, end=" ")
        count += 1 
    i += 1
print(count)
    
