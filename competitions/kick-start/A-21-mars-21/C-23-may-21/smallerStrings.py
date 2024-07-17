import sys
input = lambda : sys.stdin.readline().strip()
mod = 1_000_000_007
alph = list("abcdefghijklmnopqrstuvwxyz")
alphInd = {alph[i]:i+1 for i in range (26)}

def solve() :
    n, k = map(int, input().split())
    s = input()
    res = 1
    lim = n//2 if n%2==0 else n//2+1
    for i in range (1, lim) :
        res *= min(alphInd[s[i]], alphInd[s[n-i]])
    res2 = (alphInd[s[0]]-1)*pow(k, lim-1, mod)
    return (res+res2) % mod

def main() :
    t = int(input())
    for i in range (1, t+1) :
        print(f"Case #{i}: {solve()}")

main()