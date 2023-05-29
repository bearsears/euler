import itertools

sums = 1 #when you have perfect blue disks
turns = 5
limit = (turns - 1) // 2 + 1

for i in range(1, (limit + 0)):
    results = itertools.product(range(1, (turns + 1)), repeat=i)
    for each in results:
        print(each, sum(each), sums)
        sums += sum(each)
print(sums, limit)
p = 1
for i in range(2, (turns + 2)):
    print(i, end=" ")
    p *= i
print((p - sums)/sums)
print(p)
