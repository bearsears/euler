length = 4
digits = [0 for _ in range(length)]

digits[0] = 1
count = 0

while digits[0] != 2:
    i = 0
    #print(digits, end='\t')
    while i < length - 2:
        if digits[i] + digits[i + 1] + digits[i + 2] >= 10:
            print(digits, end='\t')
            break
        i += 1
    
    if i == length - 2:
        #print(digits, end='\t')
        count += 1
    
    digits[-1] += 1
    i = length - 1
    while i > 0 and digits[i] > 9:
        digits[i] = 0
        digits[i - 1] += 1
        i -= 1

print(count)
