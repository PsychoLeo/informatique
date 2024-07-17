import math

def main() :
    n = int(input())
    print(findDivisors((n)))

def findDivisors (n) :
    divisors = []
    for i in range(1, int(math.sqrt(n))+1):
        if n%i == 0:
            divisors.append(i)
            divisors.append(n//i)
    return list(set(divisors))


if __name__ == '__main__':
    main()