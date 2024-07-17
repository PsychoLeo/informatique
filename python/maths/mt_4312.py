la = [2, 4]

for a in la :
    u = [1, a]
    for n in range (3, 20) :
        u.append((2*n+1)*u[-1] - (n*n-1)*u[-2])
        if u[-1] % u[-2] != 0 :
            print()
    print(u)