import sys
from string import ascii_uppercase

def read():
    return sys.stdin.readline().strip()

# def write(txt):
#     sys.stdout.write(txt)

def main():
    """O(n^2) complexity"""
    alph = list(ascii_uppercase)
    word = []
    nbLines = int(input())
    for i in range (nbLines) :
        col = read()
        for j in range (26) : # len of alphabet
            if col[j] == 'O' :
                word.append(alph[j])
    print(''.join(word))

main()