lenWd = int(input())
word = input()
lenSub = int(input())

def possWord(n=0, wd = '', possible = list(word)):
    if n == lenSub :
        print (wd)
    else :
        for i in range (lenWd-n) :
            possWord(n+1, wd+possible[i], possible[:i] + possible[i+1:])
            

def fact (n) :
    if n < 2 :
        return 1
    else :
        return n*fact(n-1)

def main() :
    if lenSub > lenWd :
        print (0)
    else :
        print (int(fact(lenWd)/fact(lenWd-lenSub)))
        possWord()

main()