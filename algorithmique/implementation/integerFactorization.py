import time, random

def timeFunction(f, n) :
    dep = time.time()
    res = f(n)
    totalTime = round(time.time()-dep, 4)
    print(f"{f.__name__} : {res}\nTime : {totalTime}\n")

def erath(n) :
    # Sieving untill square root
    P = [True]*(n+1)
    primes = [2]
    for i in range (4, n+1, 2) :
        P[i] = False
    i = 3
    while i*i <= n :
        if P[i] :
            primes.append(i) # i is a prime number
            for j in range (i*i, n+1, i) :
                P[j] = False
        i += 2
    return primes


def trialDiv(n) :
    l = []
    i = 2
    while i*i <= n:
        while n % i == 0:
            l.append(i)
            n //= i
        i += 1
    if n > 1 :
        l.append(n)
    return l

def trialDiv2(n) :
    l = []
    while n % 2 == 0 :
        l.append(2)
        n //= 2
    i = 3
    while i*i <= n:
        while n % i == 0 :
            l.append(i)
            n //= i
        i += 2
    if n > 1:
        l.append(n)
    return l

def trialDiv3(n) :
    l = []
    for d in [2, 3, 5] :
        while n % d == 0 :
            l.append(d)
            n //= d
    incr = [4, 2, 4, 2, 4, 6, 2, 6]
    i = 7
    c = 0
    while i*i <= n :
        while n % i == 0 :
            l.append(i)
            n //= i
        i += incr[c]
        c = (c + 1) % len(incr)
    if n > 1 : # if n is prime 
        l.append(n)
    return l
    

def gcd(a, b) :
    while b :
        a, b = b, a%b
    return a

def binExp(a, n, mod) :
    # Calcul de (a^n) % mod
    d = 1
    while n :
        if n % 2 :
            d = (d*a) % mod
        n >>= 1
        a = (a*a) % mod
    return d

def isPrime(n) :
    # Fast Fermat primality -> fasten factorization
    for i in range (20) :
        a = random.randint(2, n-1) # random base
        # p prime => a^(p-1) = 1 (mod n) 
        # Donc a^(p-1) != 1 (mod n) => p not prime
        if gcd(a, n) == 1 :
            if binExp(a, n-1, n) != 1 :
                return False
    return True # test probabiliste

def precomputePrimes(n) :
    # Only works for "small" numbers (maximum 10^6 / 10^7)
    l = []
    primesUntillSqrt = erath(n)
    for p in primesUntillSqrt :
        while n%d == 0 :
            l.append(d)
            n //= d
    if n > 1 :
        l.append(n)
    return l

def fermatMethod(n) :
    pass

def main() :
    n = random.randint(int(1e14), int(1e15))
    print(f"n = {n}\n")
    factors = [trialDiv, trialDiv2, trialDiv3] # fermatMethod]
    for f in factors :
        timeFunction(f, n)

main()