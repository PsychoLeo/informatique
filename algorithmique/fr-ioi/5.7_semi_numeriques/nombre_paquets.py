n = int(input())
p = int(input())

def fact(n):
    if n <= 1 :
        return 1
    else :
        return n*fact(n-1)

print(fact(n+p-1)//(fact(p)*fact(n-1)))