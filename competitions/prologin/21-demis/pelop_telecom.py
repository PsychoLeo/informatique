import sys

def read():
    return sys.stdin.readline().strip()

def write(txt) :
    return sys.stdout.write(txt)

def main():
    n = int(input())
    mot = list(read())
    # print(mot)
    for i in range (0, n, 2) :
        write(int(mot[i])*mot[i+1])
    
main()