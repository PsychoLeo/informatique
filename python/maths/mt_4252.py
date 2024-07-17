# K = -1
# 
# a, b = 0, K
# 
# for i in range (30) :
#     u, v = b, K*K*b - a # relation de récurrence
#     print((u*u + v*v)/(1+u*v))
#     a, b = u, v
    
# y = [0, 1]
# maxi = 100
# 
# for i in range (2, maxi+1) :
#     k = i//2
#     if i % 2 == 0 :
#         if k % 2 == 0 :
#             y.append(2*y[k])
#         else :
#             y.append(2*y[k]+1)
#     else :
#         if k % 2 == 0 :
#             y.append(2*y[k] +1)
#         else :
#             y.append(2*y[k])
#             
# print(y)

def biggestOddDiv(x) :
    for i in range (x-1, -1, -1) :
        if x % i == 0 and i % 2 == 1:
            return i

x = 1
maxi = 1000
for i in range (2, maxi) :
    # print(x)
    if x % 2 == 0 :
        x = x//2 + x // biggestOddDiv(x)
    else :
        x = 2**((x+1)//2)
    if x == 800 :
        print("Found index", i)
        break
