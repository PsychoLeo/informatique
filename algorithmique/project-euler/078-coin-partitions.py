MAX = 1001
MOD = 1000000

p = [[1] * MAX for _ in range (MAX)]

# p[n][k] = number of ways to form 
# p(n) = p[n][n]

for n in range (1, MAX) :
    p[n][0] = 0
    for k in range (1, n+1) :
        p[n][k] = (p[n-k][min(k, n-k)] + p[n][k-1]) % MOD
    if p[n][n] == 0 :
        print(n)

print(p[5][5])
print(p[6][6])
print(p[7][7])