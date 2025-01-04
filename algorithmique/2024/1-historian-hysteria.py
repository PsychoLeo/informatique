a, b = [], []
cnt = dict()

for i in range (1000) :
    x, y = list(map(int, input().split()))
    a.append(x)
    b.append(y)
    if x not in cnt :
        cnt[x] = 0
    if y not in cnt :
        cnt[y] = 1
    else :
        cnt[y] += 1

a.sort()
b.sort() 

# s = 0

# for i in range (1000) :
#     s += abs(a[i]-b[i])

# print(s)

s = 0
for i in range (1000) :
    s += cnt[a[i]] * a[i]
print(s)

