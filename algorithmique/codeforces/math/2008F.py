MOD = int(1e9+7)

def binexp(a, n) :
    r = 1
    while n > 0 :
        if n % 2 :
            r = (r * a) % MOD
        a = (a * a) % MOD
        n //= 2
    return r

def gcd(a, b) :
    return a if b == 0 else gcd(b, a%b)

def solve(n, a) :
    S = sum(a)
    ans = 0
    for x in a :
        ans += x * (S - x)
    denom = n * (n-1)
    d = gcd(ans, denom)
    ans //= d
    denom //= d
    ans = (ans * binexp(denom, MOD-2)) % MOD
    return ans

t = int(input())
for _ in range (t) :
    n = int(input())
    a = list(map(int, input().split()))
    print(solve(n, a))