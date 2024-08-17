with open("input", 'w') as f:
    f.write("8476\n")
    for n in range (1, 6) :
        for j in range((n+1)**n) :
            f.write(f"{n}\n")
            l = []
            k = j
            p = (n+1)**(n-1)
            for i in range (n):
                l.append(str(k // p))
                k %= p
                p //= (n+1)
            f.write(' '.join(l) + '\n')
