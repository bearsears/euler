"""
this quick and dirty recursion function was for 114. 
however it is effective in solving 115.
anything under couple million this function is really quick to solve.
"""
def blocks(n, m, z):
    if n < len(z):
        return z[n] - 1 # the return value has to be subtracted by one,
        #since count += 1 below. 
    count = 0;
    while m <= n:
        limit = n - m + 1
        i = 0
        while i < limit:
            count += 1
            if (n - m - 1 - i) > 2:
                count += blocks((n - m - 1 - i), 3, z)
            i += 1
        m += 1
    return count 

memoize = [] #for start, goes up to n = 4
count = 1 # for some reason row with empty red blocks does count as one.

for i in range (0, 51):
    #print('n is {}, count is {}'.format(i, (1 + blocks(i, 3, memoize))))
    memoize.append(1 + blocks(i, 3, memoize))
"""
for i in range(0, len(memoize)):
    print('{} -- {}'.format(i, memoize[i]), end="\t")
    """
print('{} -- {}'.format(len(memoize), memoize[len(memoize) - 1]))
