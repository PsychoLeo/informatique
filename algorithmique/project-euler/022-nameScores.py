l = input().split()
l.sort()
n = len(l)
alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
scores = {alph[i]:i+1 for i in range (26)}

def main() :
    tot = 0
    for i in range (n) :
        tot += getScore(l[i], i+1)
    print(tot)


def getScore (word, position) :
    s = 0
    for i in word: 
        s += scores[i]
    return s*position

main()