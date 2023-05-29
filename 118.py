import math

def permutation(elements, l):
    copy = []
    for i in range (0, l):
        copy.append(0);
    i = 0
    temp = 0
    results = []
    sets(elements, l, results)
    print(elements)
    
    while i < l:
        if copy[i] < i:
            if (i % 2 == 0):
                temp = elements[0]
                elements[0] = elements[i]
                elements[i] = temp
            else:
                temp = elements[copy[i]]
                elements[copy[i]] = elements[i]
                elements[i] = temp
            
            if (elements[8] % 2 == 1):
                #print(elements, count)
                sets(elements, l, results)
            copy[i] += 1
            i = 0
        else:
            copy[i] = 0
            i += 1
   
    i = 0
    while i < len(results):
        results[i].sort()
        i += 1

    i, j = 0, 0
    while i < (len(results) - 1):
        j = i + 1
        while j < len(results):
            if results[i] == results[j]:
                #print(results[j])
                del results[j]
                j -= 1
            j += 1
        i += 1
    print(results)
    print(len(results))

def sets(elements, l, res):
    a, b, c, temp = 0, 0, 0, 0
    #9 digit set
    
    for i in range(0, l):
        a = a * 10 + elements[i]
    if prime(a) == True:
        res.append([a])
        print(a)

    a, b, c, temp = 0, 0, 0, 0
    #1 and 8 digit set
    if prime(elements[0]) == True:
        for i in range (1, l):
            a = a * 10 + elements[i]
        if prime(a) == True:
            res.append([elements[0], a])
            #print(elements[0], a)

    a, b, c, temp = 0, 0, 0, 0
    #2 and 7 digit set
    for i in range(0, 2):
        a = a * 10 + elements[i]
    if prime(a) == True:
        for i in range(2, l):
            b = b * 10 + elements[i]
        if prime(b) == True:
            res.append([a, b])
            #print(a, b)

    a, b, c, temp = 0, 0, 0, 0
    #1, 1, and 7 digit set
    if prime(elements[0]) == True and prime(elements[1]) == True:
        for i in range(2, l):
            a = a * 10 + elements[i]
        if prime(a) == True:
            res.append([elements[0], elements[1], a])
            #print(elements[0], elements[1], a)
            
    a, b, c = 0, 0, 0
    #3, and 6 digit set
    for i in range(0, 3):
        a = a * 10 + elements[i]
    if prime(a) == True:
        for i in range(3, l):
            b = b * 10 + elements[i]
        if prime(b) == True:
            res.append([a, b])
            #print(a, b)
            
    a, b, c = 0, 0, 0
    #1, 2, and 6 digit set
    if prime(elements[0]) == True:
        for i in range(1, 3):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(3, l):
                b = b * 10 + elements[i]
            if prime(b) == True:
                res.append([elements[0], a, b])
                #print(elements[0], a, b)
    
    a, b, c = 0, 0, 0
    #1, 1, 1, and 6 digit set
    if prime(elements[0]) == True and prime(elements[1]) == True \
        and prime(elements[2]) == True:
        for i in range(3, l):
            a = a * 10 + elements[i]
        if prime(a) == True:
            res.append([elements[0], elements[1], elements[2], a])
            #print(elements[0], elements[1], elements[2], a)

    a, b, c, d, e = 0, 0, 0, 0, 0
    #4, and 5 digit set
    for i in range(0, 4):
        a = a * 10 + elements[i]
    if prime(a) == True:
        for i in range(4, l):
            b = b * 10 + elements[i]
        if prime(b) == True:
            res.append([a, b])
            #print(a, b)
    
    a, b, c, d, e = 0, 0, 0, 0, 0
    #1, 3, and 5 digit set
    if prime(elements[0]) == True:
        for i in range(1, 4):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(4, l):
                b = b * 10 + elements[i]
            if prime(b) == True:
                res.append([elements[0], a, b])
                #print(elements[0], a, b)
  
    a, b, c, temp = 0, 0, 0, 0
    #!!! there is a symmetry here, 
    #2, 2, and 5 digit set
    for i in range(0, 2):
        a = a * 10 + elements[i]
    if prime(a) == True:
        for i in range(2, 4):
            b = b * 10 + elements[i]
        if prime(b) == True:
            for i in range(4, l):
                c = c * 10 + elements[i]
            if prime(c) == True:
                res.append([a, b, c])
                #print(a, b, c)

    a, b, c = 0, 0, 0
    #!!! symmetry here
    #1, 1, 2, and 5 digit set
    temp = 0
    if prime(elements[0]) == True and prime(elements[1]) == True:
        for i in range(2, 4):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(4, l):
                b = b * 10 + elements[i]
            if prime(b) == True:
                res.append([elements[0], elements[1], a, b])
                #print(elements[0], elements[1], a, b)

    #This set does not exist.  
    #1, 1, 1, 1, and 5 digit set
    a, b, c = 0, 0, 0
    temp = 0
    if prime(elements[0]) == True and prime(elements[1]) == True and prime(elements[2]) == True and prime(elements[3]) == True:
        for i in range(4, l):
            a = a * 10 + elements[i]
        if prime(a) == True:
            res.append([elements[0], elements[1], elements[2], elements[3], a])
            #print(elements[0:4], a)

    a, b, c, d, e = 0, 0, 0, 0, 0
    #1, 4, and 4 digit set
    temp = 0
    if prime(elements[0]) == True:
        for i in range(1, 5):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(5, l):
                b = b * 10 + elements[i]
            if prime(b) == True:
                res.append([elements[0], a, b])
                #print(elements[0], a, b)

    a, b, c, d, e = 0, 0, 0, 0, 0
    #2, 3, and 4 digit set
    for i in range(0, 2):
        a = a * 10 + elements[i]
    if prime(a) == True:
        for i in range(2, 5):
            b = b * 10 + elements[i]
        if prime(b) == True:
            for i in range(5, l):
                c = c * 10 + elements[i]
            if prime(c) == True:
                res.append([a, b, c])
                #print(a, b, c)

    a, b, c, temp = 0, 0, 0, 0
    #1, 1, 3, and 4 digit set
    temp = 0
    if prime(elements[0]) == True and prime(elements[1]) == True:
        for i in range(2, 5):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(5, l):
                b = b * 10 + elements[i]
            if prime(b) == True:
                res.append([elements[0], elements[1], a, b])
                #print(elements[0], elements[1], a, b)

    a, b, c, temp = 0, 0, 0, 0
    #1, 2, 2, and 4 digit set
    if prime(elements[0]) == True:
        for i in range(1, 3):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(3, 5):
                b = b * 10 + elements[i]
            if prime(b) == True:
                for i in range(5, l):
                    c = c * 10 + elements[i]
                if prime(c) == True:
                    res.append([elements[0], a, b, c])
                    #print(elements[0], a, b, c)

    a, b, c, temp = 0, 0, 0, 0
    #1, 1, 1, 2, and 4 digit set
    if prime(elements[0]) == True \
        and prime(elements[1]) == True \
        and prime(elements[2]) == True:
        for i in range(3, 5):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(5, l):
                b = b * 10 + elements[i]
            if prime(b) == True:
                res.append([elements[0], elements[1], elements[2], elements[3], a, b])
                #print(elements[0:3] , a, b)

    a, b, c, temp = 0, 0, 0, 0
    #3, 3, and 3 digit set
    for i in range(0, 3):
        a = a * 10 + elements[i]
        b = b * 10 + elements[(i + 3)]
        c = c * 10 + elements[(i + 6)]
    if prime(a) == True and prime(b) == True and prime(c) == True:
        res.append([a, b, c])
        #print(a, b, c)

    a, b, c, temp = 0, 0, 0, 0
    #1, 2, 3, and 3 digit set
    if prime(elements[0]) == True:
        for i in range(1, 3):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(3, 6):
                b = b * 10 + elements[i]
            if prime(b) == True:
                for i in range(6, l):
                    c = c * 10 + elements[i]
                if prime(c) == True:
                    res.append([elements[0], a, b, c])
                    #print(elements[0], a, b, c)

    a, b, c, temp = 0, 0, 0, 0
    #1, 1, 1, 3, and 3 digit set
    if prime(elements[0]) == True and prime(elements[1]) == True \
        and prime(elements[2]) == True:
        for i in range(3, 6):
            a = a * 10 + elements[i]
            b = b * 10 + elements[i + 3]
        if prime(a) == True and prime(b) == True:
            res.append([elements[0], elements[1], elements[2], a, b])
            #print(elements[0:3], a, b)

    a, b, c, temp = 0, 0, 0, 0
    #1, 1, 2, 2, and 3 digit set
    if prime(elements[0]) == True and prime(elements[1]) == True:
        for i in range(2, 4):
            a = a * 10 + elements[i]
            b = b * 10 + elements[i + 2]
        if prime(a) == True and prime(b) == True:
            for i in range(6, l):
                c = c * 10 + elements[i]
            if prime(c) == True:
                res.append([elements[0], elements[1], a, b, c])
                #print(elements[0], elements[1], a, b, c)

    a, b, c, d = 0, 0, 0, 0
    #2, 2, 2 and 3 digit set
    for i in range(0, 2):
        a = a * 10 + elements[i]
        b = b * 10 + elements[i + 2]
        c = c * 10 + elements[i + 4]
    if prime(a) == True and prime(b) == True and prime(c) == True:
        for i in range(6, l):
            d = d * 10 + elements[i]
        if prime(d):
            res.append([a, b, c, d])
            #print(a, b, c, d)

    a, b, c, d = 0, 0, 0, 0
    #1, 1, 1, 1, 2, and 3 digit set
    if prime(elements[0]) == True and prime(elements[1]) == True \
        and prime(elements[2]) == True and prime(elements[3]) == True:
        for i in range(4, 6):
            a = a * 10 + elements[i]
        if prime(a) == True:
            for i in range(6, l):
                b = b * 10 + elements[i]
            if prime(b) == True:
                res.append([elements[0], elements[1], elements[2], elements[3],
                    a, b])
                #print(elements[0], elements[1], elements[2], elements[3], a, b)

    a, b, c, d, temp = 0, 0, 0, 0, 0
    #1, 2, 2, 2, and 2 digit set
    if prime(elements[0]) == True:
        for i in range(1, 3):
            a = a * 10 + elements[i]
            b = b * 10 + elements[i + 2]
            c = c * 10 + elements[i + 4]
            d = d * 10 + elements[i + 6]
        if prime(a) == True and prime(b) == True and prime(c) == True \
            and prime(d) == True:
            res.append([elements[0], a, b, c, d])
            #print(elements[0], a, b, c, d)

    a, b, c = 0, 0, 0
    #1, 1, 1, 2, 2 and 2 digit set
    if prime(elements[0]) == True and prime(elements[1]) == True \
        and prime(elements[2]) == True:
        for i in range(3, 5):
            a = a * 10 + elements[i]
            b = b * 10 + elements[i + 2]
            c = c * 10 + elements[i + 4]
        if prime(a) == True and prime(b) == True and prime(c) == True:
            res.append([elements[0], elements[1], elements[2], a, b, c])
            #print(elements[0], elements[1], elements[2], a, b, c)

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

pd = [9, 8, 7, 6, 5, 4, 3, 2, 1]
#pd = [1, 2, 3, 4, 5, 6, 7, 8, 9]
length = len(pd)
permutation(pd, length)
"""
primes = []
count = 0
for i in range(0, 1000):
    if prime(i) == True:
        primes.append(i)
        count += 1

print(primes, count)
"""
