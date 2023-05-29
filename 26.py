mcount, mi = 0, 0
for i in range(3, 1000, 2):

    r, rr, pr, count = 1, 0, 1, 0 
    if i < 10:
        rr = 1
    elif i < 100:
        rr = 10
    else:
        rr = 100

    while (r * 10) // i == 0:
        r = (r * 10) % i
        count += 1
    while True:
        pr = r
        r = (r * 10) % i
        count += 1
        if r == 0 or r == pr or r == rr:
            break
        if count > i:
            break
    if count > mcount:
        mcount = count
        mi = i
    print("n = " + str(i) + " count " + str(count), mi, mcount)

print(mi, mcount)
