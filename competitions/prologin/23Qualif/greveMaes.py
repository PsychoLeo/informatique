import sys
sys.setrecursionlimit(1000*1000)

def main():

    N = int(input())
    convertInt = lambda x: int(x)-1
    redirec = list(map(convertInt, input().split()))
    dist = [0]*N
    marquage = [0]*N

    def det_cycle(i):
        if marquage[i] == 1:
            marquage[i] = 2
            return [i], i

        elif marquage[i] == 0:
            marquage[i] = 1
            cycle, dep = det_cycle(redirec[i])
            marquage[i] = 2
            if dep == i:
                cycle.append(i)
                for j in cycle:
                    dist[j] = len(cycle)-1
                return [], -1
            elif dep == -1:
                dist[i] = dist[redirec[i]] + 1
                return [], -1
            else:
                return cycle + [i], dep
        else: #marquage = 2
            #dist[i] = dist[redirec[i]] + 1
            #marquage[i] = 2
            return [], -1
    for i in range(N):
        if marquage[i] == 0:
            det_cycle(i) 
    print(*dist) 

main()

