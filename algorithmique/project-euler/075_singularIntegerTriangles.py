MAX = 1500001

vis = [0] * MAX

def gcd(a, b) :
    return a if b == 0 else gcd(b, a %b)

for q in range (1, 1000) :
    for p in range (q+1, 1000, 2) :
        n = 2 * p * (p + q)
        if 2 * p * (p + q) >= MAX :
            break
        if gcd(p, q) == 1 :
            m = n
            while m < MAX :
                vis[m] += 1
                m += n

ans = vis.count(1)
print(ans)