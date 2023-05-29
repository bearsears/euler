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

count = 0

for n in range(1, 1000000):
    if prime(n) == True:
        continue
    solutions = 0
    limit = int(math.sqrt(n) ) 
    diff = 0
    div = 0
    #print(n, limit)

    while div < limit:
        div += 1
        if (n % div) != 0:
            continue
        diff = n // div + div
        if diff % 4 == 0:
            solutions += 1
            diff //= 4
            #print(diff, div, (n // div))
            if diff < div:
                solutions += 1
            """
            if diff < (n // div):
                solutions += 1
        if solutions > 1:
            break
            """

    if limit * limit == n:
        solutions -= 1

    if solutions == 10:
        print(n, solutions) 
        count += 1
    
    """
    while i in range(0, len(factors)):
        if len(factors) < 10:
            break
        if (n // factors[i] + factors[i]) % 4 != 0:
            factors.pop(i)
            i -= 1
        diff = (n // factors[i] + factors[i]) // 4
        if diff >= factors[i]:
            #print(i)
            factors.pop(i)
            i -= 1
        i += 1
    #if i == 10:
    count += 1
    print(n, factors)
    """
    

print(count)
