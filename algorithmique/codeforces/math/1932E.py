import sys
input = sys.stdin.readline

def solve(n, s):
    ans = 0
    current_number = 0

    for i in range(n):
        current_number = current_number * 10 + int(s[i])
        ans += current_number

    return ans

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())
        s = input().strip()  # Read the string directly
        print(solve(n, s))
