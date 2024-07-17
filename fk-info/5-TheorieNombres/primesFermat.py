import random 

def fermatIsPrime(n, nbBasesGen = 8) :
    if n < 4 :
        return n == 2 or n == 3
    for i in range (nbBasesGen) :
        a = 2 + random.randint(0, n-4)
        if binExp(a, n-1, n) != 1 :
            return False
    return True # n is probably prime

def binExp (a, b, mod) :
    # Renvoie a^b modulo mod
    res = 1
    a %= mod
    while (b > 0) :
        if (b&1) : # if b % 2 == 1
            res = res*a % mod
        b >>= 1 # b //= 2
        a = a*a%mod
    return res

def main() :
    MAX = 100
    for i in range (2, MAX+1) :
        if (fermatIsPrime(i)) :
            print(f"{i} is prime")

if __name__ == "__main__":
    main()