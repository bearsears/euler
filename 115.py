"""
this quick and dirty recursion function was for 114. 
however it is effective in solving 115.
anything under couple million this function is really quick to solve.
"""
def blocks(n, m):
    count = 0;
    while m <= n:
        limit = n - m + 1
        i = 0
        while i < limit:
            count += 1
            #print('n is {}, m is {}, and m is at position {}'.format(n, m, i))
            count += blocks((n - m - 1 - i), 50)
            i += 1
        m += 1
        print('n is {}, m is {}'.format(n, m))
        
    return count

n = 168
m = 50
count = 1 # for some reason row with empty red blocks does count as one.

count += blocks(n, m)

print('The count should be {}.'.format(count))
