n, m = list(map(int, input().split()))
k = [0] + list(map(int, input().split()))

s_j2kj = [0]
s_jkj = [0]
s_kj = [0]

for j in range (1, n+1) :
    s_j2kj.append(s_j2kj[-1] + j*j*k[j])
    s_jkj.append(s_jkj[-1] + j*k[j])
    s_kj.append(s_kj[-1] + k[j])


dp = [[float("inf")]*(m+1) for _ in range (n+1)]

def cost(a, b) :
    E = (s_jkj[b]-s_jkj[a-1])/(s_kj[b]-s_kj[a-1])
    ans = s_j2kj[b]-s_j2kj[a-1] 
    ans -= 2*E*(s_jkj[b]-s_jkj[a-1])
    ans += E*E*(s_kj[b]-s_kj[a-1])
    return ans

def get(i, m) :
    if i == 0 :
        return 0
    if dp[i][m] < float("inf") :
        return dp[i][m]
    ans = float("inf")
    for k in range (1, i) :
        ans = min(ans, get(k, m-1) + cost(k+1, i))
    dp[i][m] = ans
    return ans

print(get(n, m))
print(dp)