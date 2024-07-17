import sys

def malindromes() :
    c = 0
    for pal in palindromes:
        mini, maju, chif = '', '', ''
        for char in pal :
            if char.islower() :
                mini += char
            elif char.isupper() :
                maju += char
            elif char.isnumeric() :
                chif += char
        if ispal(mini) and ispal(maju) and ispal(chif) :
            c += 1
    return c

def ispal(c) :
    for i in range (len(c)//2) :
        if c[i] != c[-1-i] :
            return False
    return True

if __name__ == "__main__" :
    n = int(input())
    palindromes = []
    for i in range (n) :
        palindromes.append(sys.stdin.readline().strip())
    print(malindromes())