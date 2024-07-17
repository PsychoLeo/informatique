import sys
input = sys.stdin.readline

def numberChanges (s, wordSize, goodnessToReach):
    r = 0
    for i in range (wordSize//2) :
        if s[i] != s[-i-1] :
            r += 1
    if r == goodnessToReach :
        return 0
    else :
        return abs(goodnessToReach-r)

if __name__ == '__main__':
    t = int(input())
    for i in range (t) :
        wordSize, goodnessToReach = map(int, input().split())
        s = input().strip()
        print(f"Case #{i+1}: {numberChanges(s, wordSize, goodnessToReach)}")