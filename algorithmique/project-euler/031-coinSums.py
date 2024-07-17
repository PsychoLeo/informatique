coins = [1, 2, 5, 10, 20, 50, 100, 200]
n = len(coins)
res = 0

def coinSum (i=n-1, amt = 0) :
    global res
    if i == 0 :
        res += 1
    else :
        j = 0
        while amt + j*coins[i] <= 200 :
            coinSum(i-1, amt + j*coins[i])
            j += 1

coinSum()
print(res)