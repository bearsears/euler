"""
a = 3
rmax = 0
while a < 20:
    n = 1
    r = 0
    trmax = 0
    print(a * a)
    while n < 20:
        r = ((a - 1) ** n + (a + 1) ** n) % (a * a)
        if trmax < r:
            print('a is {}, n is {}, and remainder is {}'.format(a, n, r))
            trmax = r
        n += 1
    rmax += trmax
    a += 1
print('rmax is {}'.format(rmax))
"""

rmax = 0
a = 3
while a < 1001:
    r = 3 * ((a - 1) + (a + 1)) 
    limit = a * a
    m = 3
    while r < limit:
        r = r * (m + 2) // m
        m += 2
    m -= 2
    r = r * m // (m + 2)
    if (r * (m + 1) // m) < limit:
        r = r * (m + 1) // m
  #  print('a is {}, and remainder is {}'.format(a, r))
    rmax += r
    a += 1
print('rmax is {}'.format(rmax))
