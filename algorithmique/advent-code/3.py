s = input()
n = len(s)-10
nums = "0123456789"
ans = 0
mode = True

for i in range (n) :
    c1 = 0
    c2 = 0
    if s[i:i+4] == "do()" :
        mode = True
    elif s[i:i+7] == "don't()" :
        mode = False
    if s[i:i+4] == "mul(" and mode:
        j = i+4
        while s[j] in nums :
            j += 1
        c1 = int(s[i+4:j])
        if s[j] != ',' :
            continue
        k = j+1
        while s[k] in nums :
            k += 1
        if s[k] != ')':
            continue
        c2 = int(s[j+1:k])
    ans += c1*c2

print(ans)