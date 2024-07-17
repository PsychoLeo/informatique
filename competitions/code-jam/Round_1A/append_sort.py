import sys
input = sys.stdin.readline

def compare (a, b, i=0, diff=0) :
    isIndexOk = (i < min(len(a), len(b)))
    if int(b) > int(a) :
       return b, diff
    if isIndexOk and int(a[i]) < int(b[i]) : # fill with 0's
        while len(b) < len(a) :
            b += '0'
            diff += 1
        return b, diff 
    elif isIndexOk and int(a[i]) > int(b[i]) :
        while len(b) <= len(a) :
            b += '0'
            diff += 1
        return b, diff
    else : # si a[i] == b[i] ou i >= len(b) ou i >= len(a)
        if i >= len(a) :
            return compare(a, b+'0', i+1, diff+1)
        if i >= len(b) :
            d = len(a)-i
            if a[i:] == '9'*d :
                return b+'0'*(len(a)-i+1), diff+d+1
            else :
                lenA = len(a[i:])
                return b+str(int(a[i:])+1).zfill(lenA), diff+d
        elif a[i] == b[i] :
            return compare(a, b, i+1, diff)


def appendSort(n, l):
    i = 0
    res = 0
    stringNb = [str(i) for i in l]
    while i < n-1 : # pour chaque paire de deux digits
        stringNb[i+1], d = compare(stringNb[i], stringNb[i+1])
        res += d
        i += 1
    # print(' '.join(stringNb))
    return res


def main() :
    t = int(input())
    for i in range(t) :
        n = int(input())
        l = list(map(int, input().strip().split()))
        print(f"Case #{i+1}: {appendSort(n, l)}")

main()