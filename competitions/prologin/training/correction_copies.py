import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n = int(read())
    values = list(map(int, read().split()))
    sumVals = sum(values)
    if sumVals % 2 :
        print(0); return
    else :
        print(knapsack (values, sumVals//2))

def knapsack(values, cmax) :
    n = len(values)
    Opt = [[0]*(cmax+1) for _ in range (n)]
    for cap in range (values[0], cmax+1) :
        Opt[0][cap] = values[0]
    for i in range (1, n):
        for cap in range (cmax+1) :
            if cap >= values[i] and Opt[i-1][cap-values[i]] + values[i] > Opt[i-1][cap] :
                Opt[i][cap] = Opt[i-1][cap-values[i]] + values[i]
            else :
                Opt[i][cap] = Opt[i-1][cap]
    return int(Opt[n-1][cmax] == cmax)

main()