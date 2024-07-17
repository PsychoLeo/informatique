import sys
print = sys.stdout.write
input = sys.stdin.readline

class UnionFind :

    def __init__ (self, n) :
        self.pred = [None]*n
        self.rank = [0]*n
    
    def find (self, A) :
        if self.pred[A] == None:
            return A
        else :
            self.pred[A] = self.find(self.pred[A])
            return self.pred[A]

    def union (self, A, B) :
        bossA, bossB = self.find(A), self.find(B)
        if self.find(A) == self.find(B) :
            return False
        if self.rank[bossA] == self.rank[bossB] :
            self.rank[bossA] += 1 # on ajoute au bossA le bossB de même profondeur que A
            self.pred[bossB] = bossA
        elif self.rank[bossA] > self.rank[bossB] :
            self.pred[bossB] = bossA # bossA devient le maitre de bossB (car il a une plus longue hiérarchie)
        else :
            self.pred[bossA] = bossB
        return True


if __name__ == "__main__" :
    n, r = map(int, input().split())
    uf = UnionFind(n)
    for i in range (r) :
        A, B = map(int, input().split())
        if uf.union(A, B) :
            print(str(A) + ' ' + str(B) + '\n')