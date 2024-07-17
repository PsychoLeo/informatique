from math import sqrt

def main():
    n = int(input())
    found = False
    result = set()
    for i in range (2, int(sqrt(n))+1) :
        if n%i == 0 :
            result.add(i)
            result.add(n//i)
            found = True
    if not found:
        print (0)
    else :
        print("\n".join(map(str, sorted(result))))

main()