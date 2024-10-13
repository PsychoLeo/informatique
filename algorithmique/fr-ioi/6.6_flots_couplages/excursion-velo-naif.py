def find(i, score, used=[]) :
    if i == p :
        global mx
        mx = max(mx, score)
    else :
        for x in adj1[i] :
            if x not in used :
                find(i+1, score+1, used+[x])
        find(i+1, score, used)


if __name__ == "__main__" :
    # t = int(input())
    t = 1
    for _ in range (t) :
        p, v, m = list(map(int, input().split()))
        adj1 = [[] for _ in range(p)]
        c = 0
        for i in range(m):
            a, b = list(map(int, input().split()))
            adj1[a].append(b)
        mx = 0
        find(0, 0)
        print(mx)
    