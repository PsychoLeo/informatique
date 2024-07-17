import sys
input = sys.stdin.readline

def matchingParenth(s, depth=0, r = "", i=0) :
    if i == len(s) :
        r += ")"*depth
        return r
    else :
        while depth > int(s[i]) :
            r += ")"
            depth -= 1
        while depth < int(s[i]) :
            r += "("
            depth += 1
        r += s[i]
        return matchingParenth(s, depth, r, i+1)

def main():
    t = int(input())
    for i in range (t) :
        s = input().strip()
        print(f"Case #{i+1}: {matchingParenth(s)}")

main()