import sys
input = sys.stdin.readline 

def main() :
    t = int(input())
    for i in range (t) :
        n, c = map(int, input().split())
        found = False
        for l in costs[c] :
            if len(l) == n :
                found = True
                res = ' '.join(map(str, l))
                print(f"Case #{i+1}: {res}")
                break
        if not found :
            print(f"Case #{i+1}: IMPOSSIBLE")

def reversort(n, l):
    r = 0
    for i in range (n-1) :
        mini = float("+inf")
        bestIndex = None
        for j in range (i, n) :
            if l[j] < mini :
                bestIndex = j
                mini = l[j]
        r += bestIndex-i+1
        l = l[:i] + l[i:bestIndex+1][::-1] + l[bestIndex+1:]
        assert len(l) == n
    return r

def bruteForce() :
    def findLists (size, liste = []) :
        if len(liste) == size :
            costs[reversort(size, liste)].append(liste)
            return
        else :
            for j in range (1, size+1) :
                if j not in liste:
                    # liste.append(j)
                    findLists(size, liste+[j])
                    # liste.pop()

    for i in range (2, 8) :
        findLists(i)

costs = [list() for _ in range (1001)] # une liste pour chaque taille
bruteForce()
main()