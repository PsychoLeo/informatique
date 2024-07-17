import sys
input = sys.stdin.readline

l = [int(input().strip()[:12]) for _ in range (100)]
print(str(sum(l))[:10])