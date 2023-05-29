
limit = 10000
limit_cubes = 20000
c = [0 for x in range(limit_cubes + limit_cubes // 10)]
corners = [0, 0, 0]
sides = [0]
i = 1
while corners[-1] <= (limit_cubes ):
    corners.append(corners[-1] + i * 4 * 2)
    i += 1

for i in range(1, (limit_cubes // 4)):
    sides.append(4 * (i - 1))
print(corners)

for i in range(1, limit):
    n = 0
    layer = 1
    surface = 2 * (2 * i + 1)
    ijk = i + 2
    n = (surface + (sides[layer] * ijk) + corners[layer])
    while n < limit_cubes:
        njdiff = 2 * (i + 1) + sides[layer]
        for j in range(1, (i + 1)):
            if n > limit_cubes:
                break
            c[n] += 1 
            k = 2
            nkdiff = 2 * (i + j) + sides[layer]
            nk = n + nkdiff
            while k <= j:
                if nk > limit_cubes:
                     break
                c[nk] += 1
                k += 1
                nk += nkdiff
            n += njdiff
        layer += 1
        n = (surface + (sides[layer] * ijk) + corners[layer])

        """
        for k in range(1, (j + 1)):
            layer = 1
            surface = 2 * (i * k + i * j + k * j)
            ijk = i + j + k
            n = (surface + (sides[layer] * ijk) + corners[layer]) 
            while n < limit_cubes:
                print(i, j, k,  layer, n, end="\t")
                c[n] += 1
                layer += 1
                n = (surface + (sides[layer] * ijk) + corners[layer]) 
        """

for i in range(1, limit_cubes):
    #if c[i] > (limit * 3 // 4):
    if c[i] == 1000:
        print('c[{}] = {}'.format(i, c[i]), end="\t")
