n = int(input())
l = []
for i in range (n):
    x = int(input())
    l.append(x)

r = 0
occurences = {}
for i in range (n-3) :
    # print(l[i:i+4])
    if tuple(l[i:i+4]) not in occurences :
        occurences[tuple(l[i:i+4])] = 1
        r = max(1, r)
    else :
        occurences[tuple(l[i:i+4])] += 1
        r = max(occurences[tuple(l[i:i+4])], r)
print(r)