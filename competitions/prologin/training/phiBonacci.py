import sys

n = int(input())
x = list(map(int, sys.stdin.readline().strip().split()))
m = 1000000007

while len(x) > 2 :
    v = x.pop()
    x[-1] = (x[-1] + v)%m
    x[-2] = (x[-2] + v)%m

print(*x)