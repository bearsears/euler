'''
n = 10
while n < 1000000000:
    temp = n
    sums = 0;
    while temp > 0:
        sums += temp % 10
        temp //= 10

    for i in range(0, 10):
        power = 0;
        temp = 1
        #print('{}, {}, {}', n, sums, power)

        while temp < n and sums > 1:
            temp *= sums
            power += 1

        if temp == n:
            print(n, sums, power)
        n += 1
        sums += 1
        '''

n = 2;
while n < 200:
    temp = n
    power = 1
    while temp < 10000000000000:
        temp *= n;
        sums = 0
        temp2 = temp;
        power += 1
        #print(temp, n, power)
        while temp2 > 0:
            sums += temp2 % 10
            temp2 //= 10
        if sums == n:
            print(temp, n, power)
            
    n += 1
