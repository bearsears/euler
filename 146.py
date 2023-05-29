import math

def prime_faster(n, a):
    if n % 2 == 0 or n <= 2:
        return False
    limit = int(math.sqrt(n) + 2)
    i = 0
    while a[i] <= limit:
        if n % a[i] == 0:
            return False
        i += 1
    return True

def prime(n):
    if n % 2 == 0 or n <= 2:
        return False
    limit = int(math.sqrt(n) + 2)
    for i in range(3, limit, 2): 
        if n % i == 0:
            return False
    return True

nsq = 1242490 * 1242490
for n in range(1242390, 1242590, 10):
    nsq = n * n
    if(nsq % 100 != 0):
        continue
    print(n, end='\t')
    for i in range(1, 29):
        if prime(nsq + i) == True:
            print((nsq + i), end='\t')
    print()
print("end")

a = [3, 5, 7, 11, 13]

for n in range(17, 150000000, 2):
    if prime_faster(n, a) == False:
        continue
    a.append(n)

i, j, nsq = 0, 0, 0
increments = [1, 3, 7, 9, 13, 27]
total = 0

while a[i] < 15000000:
    i += 1

i -= 1

while a[i] > 9000000:
    nsq = a[i] * a[i] * 100
    for j in range(0, len(increments)):
        if prime_faster((nsq + increments[j]), a) == False:
            break
    if j == len(increments) - 1:
        print(nsq, a[i])
        total += (nsq * 10)
    i -= 1

print(total)

#print(a)
print(len(a))
"""
total = 0
i = 0
for n in range(2, 1000000, 2):
    nsq = n * n
    for i in range(0, len(increments)):
        if prime(nsq + increments[i]) == False:
            break
    #print(n, i)
    if i == len(increments) - 1:
        print(n, nsq)
        total += n
"""
