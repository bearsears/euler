#this is a brute force, and becomes exponentially slow.
def binary_multiplier(lst, n, option):
    temp = []
    temp.extend(lst)

    while temp[-1] < n:
        if temp[-1] * 2 <= n:
            temp.append(temp[-1] * 2)
            continue
        i = len(temp) - 1
        while i >= 0:
            i -= 1
            if (temp[-1] + temp[i]) <= n:
                temp.append(temp[-1] + temp[i])
                break;
    #print(temp)
    #option 0 will return len, 1 will return the list
    if option == 0:
        return len(temp) - 1
    elif option == 1:
        return temp

number = 3
total = 1
a = [[1, 2]]

while number <= 200:
    print(number, end=" ")
    mx = binary_multiplier(a[0], number, 0) 
    #find minimum.
    for i in range(1, len(a)):
        tmax = binary_multiplier(a[i], number, 0) 
        if mx > tmax:
            mx = tmax

    #add the paths that has the minimum lengths
    for i in range(0, len(a)):
        if mx == binary_multiplier(a[i], number, 0):
            a.append(binary_multiplier(a[i], number, 1))

    #remove duplicates
    for i in range(0, (len(a) - 1)):
        for j in range ((i + 1), len(a)):
            if a[i] == a[j]:
                del a[j]
                break;
    number += 1

    #add the minimum
    total += mx

print(a)
print(total)
