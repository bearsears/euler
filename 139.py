import math

asq = [a * a for a in range(0, 1000)]
#print(asq)    
count = 0
left = 0

for a in range(5, 50000000, 2):
    left = (a - 1) // 2 * (a + 1)
    b = int(math.sqrt(left)) + 1
    if left == b * (b - 1) :
        #if a * a == b * b + (b - 1) * (b - 1):
        print(a, b, (b - 1))
        count += 100000000 // (a + b + b - 1)
        print(count)

     
    """
    if asq[a] % 2 == 0:
        increment = 1
    else:
        increment = 2
    for x in range(1, (a + 1), increment):
        if a % x == 0:
            b = a - 1
            while b > x:
                if asq[a] == 2 * b * b - 2 * x * b + x * x:
                    print(a, b, (b - x), x, asq[a])
                    count += 1
                b -= 1
    """
print(count)
