def main():
    n = int(input())
    l = list(map(int, input().split()))
    vals = [0]*l[0]
    currVal = l[0]
    currNb = 1
    j = -1
    for i in range (1, n) :
        if l[i] == currVal :
            currNb += 1
        else :
            while l[i] < currVal :
                vals[j] = currNb
                currVal -= 1
                j -= 1
            currNb += 1
    vals += [0]*(n-l[0])
    print (' '.join(map(str, vals)))

main()