from collections import deque

def main():
    a, b, c, d = map(int, input().split())
    init, end = map(int, input().split())
    visited = [False] * 100001 # brute force
    # pred = [None] * 100001
    toTry = deque([init])
    while toTry :
        val = toTry.pop()
        for op in [val+a, val-b, val*c] :
            if 0 <= op <= 100000 and not visited[op] : # and op != init
                toTry.appendleft(op)
                visited[op] = True
                # pred[op] = val
                if op == end :
                    print(1); return
            if d != 0 and val%d == 0 :
                op = val//d
                if not visited[op] :
                    toTry.appendleft(op)
                    visited[op] = True
                if op == end :
                    print (1); return
    # if visited[end] :
    #     curr = end
    #     sol = []
    #     while curr is not None :
    #         sol.append(curr)
    #         curr = pred[curr]
    #     print (sol[::-1])
    # else :
    print (0)

main()