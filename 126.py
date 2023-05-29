import sys

def ijk(i, j, k, layer):
    #the six surfaces
    cubes = 2 * (i * k + i * j + k * j) 
    #the sides, 
    cubes += (4 * (layer - 1) * (i + j + k))
    #the corners
    for p in range(1, (layer - 1)):
        cubes += p * 4 * 2
        print(p, end=" ")
    print()

    return cubes

limit = 160
limit_cubes = 400
c = [0 for x in range(limit_cubes)]
corners = [0, 0]
i = 1
while corners[-1] <= limit_cubes:
    corners.append(corners[-1] + i * 4 * 2)
    i += 1
print(corners)

for i in range(1, limit):
    for j in range(1, (i + 1)):
        for k in range(1, (j + 1)):
            n = 0
            layer = 1
            while n <= limit_cubes:
                n = ijk(i, j, k, layer) + corners[layer]
                #print(i, j, k,  layer, n, end="\t")
                layer += 1
                if n < len(c):
                    c[n] += 1

for i in range(1, limit_cubes):
    #if c[i] > (limit * 3 // 4):
    #if c[i] >= 10:
    print('c[{}] = {}'.format(i, c[i]), end="\t")
