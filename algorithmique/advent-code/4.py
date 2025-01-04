s0 = input()
n = len(s0)
s = [s0] + [input() for _ in range (n-1)]
possib = ["XMAS", "SAMX"]
ans = 0

def diag(i, j) :
    return ''.join([s[i+k][j+k] for k in range(4)])

def diagleft(i, j) :
    return ''.join([s[i+k][j-k] for k in range(4)])

def col(i, j) :
    return ''.join([s[i+k][j] for k in range(4)])

def lin(i, j) :
    return s[i][j:j+4]


# for i in range (n) :
#     for j in range (n) :
#         if i+3 < n and j+3 <n :
#             if col(i, j) in possib :
#                 ans += 1
#             if lin(i, j) in possib :
#                 ans += 1
#             if diag(i, j) in possib :
#                 ans += 1
#         elif i+3 <n :
#             if col(i,j) in possib :
#                 ans += 1
#         elif j+3 < n :
#             if lin(i, j) in possib :
#                 ans += 1
#         if j > 2 and i+3<n: 
#             if diagleft(i, j) in possib :
#                 ans += 1

def around(i, j) :
    d = [1, -1]
    return [s[i+di][j+dj] for di in d for dj in d]

possible = ["SSMM", "MSMS", "SMSM", "MMSS"]

for i in range (1, n-1) :
    for j in range (1, n-1) :
        if s[i][j] == 'A' and ''.join(around(i, j)) in possible :
            ans += 1


print(ans)