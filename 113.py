
count = 0
def recurse_bouncy(n):
    global count
    if n > 100000:
        return
    i = n % 10
    #print(i)
    temp = n
    while i >= 0:
        temp = n * 10 + i
        print(temp, end="\t")
        i -= 1
        count += 1
        recurse_bouncy(temp)
    print()
    

    return 
"""
recurse_bouncy(2)
count += 1
print(count)
"""

#
def non_bouncy(n, p):
    #n is the single digit number that expands to the pth power
    r = 10 - n
    i = 3
    b = []
    count = r 
    while r > 0:
        b.append(r)
        count += r
        r -= 1
#    for j in range(len(b)):
#        print(b[j], end=" ")
#    print()
    while i < p:
        j = 0;
        a = []
        while j < len(b):
            temp = b[j]
            while temp > 0:
        #        print(temp, end=",")
                a.append(temp)
                count += temp
                temp -= 1
            j += 1
        j = 0 
        #print()
        while j < len(a):
        #    print(a[j], end=" ")
            j += 1
        b = a.copy()
        #print()
        i += 1
    count += 1 # for the single digit
    print(count, end=" and ")
    #there is a symmetry here. increasing with starting digit one
    #will have a same count as decresing with starting digit eight
    #decreasing,  increasing
    #1, 8
    #2, 7
    #3, 6
    #4, 5
    #5, 4
    #6, 3
    #7, 2
    #8, 1
    #decreasing with zero as start does not exist.
    #decreasing with 9 needs its own function
    count -= p 
    if n < 9 and n > 0:
        count *= 2
    count += p 
    print(count)
    print()
    return count

def second(n, p):
    numbers = []
    i = n
    while i > 0:
        numbers.append(i)
        i -= 1
    counts = []
    for i in range(0, n):
        counts.append(1)
    additions = []
    for i in range(0, n):
        additions.append(i)
#    for i in range(0, n):
#        print('{}, {}, {}'.format(numbers[i], counts[i], additions[i]))
    total = n
    sums = 0
    for i in range(2, p):
        #for j in range(0, n):
        #    print('{}, {}, {}'.format(numbers[j], counts[j], additions[j]))
        #print()
        sums = 0
        for j in range(0, n):
            sums += numbers[j] * counts[j]
        total += sums
        for j in range(0, n):
            counts[j] = counts[j] + additions[j]
        for j in range(1, n):
            additions[j] = additions[j - 1]  + additions[j]
    total += 1
    total -= p
    if n > 1 and n < 10:
        total *= 2
    total += p
    print('total is {}'.format(total))
    return total

count = 0
p = 100

for n in range(1, 11):
    count += second(n, p)
count -= p
print(count)

"""
count = 0
for n in range(0, 10):
    count += non_bouncy(n, p) 
count -= p
print(count)
"""
