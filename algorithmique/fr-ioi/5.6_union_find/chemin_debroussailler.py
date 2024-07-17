import sys
input = sys.stdin.readline

class UnionFind :

    def __init__ (self, n) :
        self.up = [None]*n
        self.rank = [0]*n
        self.depth = [1]*n # profondeur de tous les noeuds
    
    def find (self, A) :
        if self.up[A] == None:
            return A
        else :
            self.up[A] = self.find(self.up[A])
            return self.up[A]

    def union (self, A, B) :
        bossA, bossB = self.find(A), self.find(B)
        if bossA == bossB :
            # self.depth[bossA] += 1 # on rajoute un membre au bossA
            return self.depth[bossA]
        if self.rank[bossA] == self.rank[bossB] :
            self.rank[bossA] += 1 # on ajoute au bossA le bossB de même profondeur que A
            self.up[bossB] = bossA
            self.depth[bossA] += self.depth[bossB]
            best = self.depth[bossA]
        elif self.rank[bossA] > self.rank[bossB] :
            self.up[bossB] = bossA # bossA devient le maitre de bossB (car il a une plus longue hiérarchie)
            self.depth[bossA] += self.depth[bossB]
            best = self.depth[bossA]
        else :
            self.up[bossA] = bossB
            self.depth[bossB] += self.depth[bossA]
            best = self.depth[bossB]
        return best

if __name__ == "__main__":
    nbNodes, nbEdges = map(int, input().split())
    uf = UnionFind(nbNodes)
    maxi = 0
    for i in range (nbEdges) :
        A, B, _ = map(int, input().split())
        maxDepth = uf.union(A-1, B-1)
        maxi = max(maxDepth, maxi)
        print(maxi)
    # print(uf.depth)
    # print(uf.rank)
