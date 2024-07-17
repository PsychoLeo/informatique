import sys

def read():
    return sys.stdin.readline().strip()

class Tree :
    """
    Implementing Tree data structure class
    """

    def __init__(self, tree=[]):
        self.tree = [0] + tree
        self.length = len(self.tree)
    
    def findPred (self, pos) :
        """
        Returns list of predecessors from object to root (including root)
        => O(h) where h: depth of the current node
        """
        preds = [pos]
        while pos : # while value is not 0 (not at the root of the tree)
            pos = self.tree[pos]
            preds.append(pos)
        return preds

    def findLenPred (self, pos) :
        """
        Returns number of predecessors from object to root
        => O(h) complexity (h: depth of node)
        """
        r = 0
        while pos :
            pos = self.tree[pos]
            r += 1
        return r

    def addElem (self, predecessor, index=0) :
        """
        Insert an element at the index given 
        If no index specified, appends the element to list
        => O(1) complexity
        """
        if index == 0 :
            self.tree.append(predecessor)
            return
        self.tree[index] = predecessor
        self.length += 1

    def findLongest (self) :
        """
        Finds longest path to go from any element to source
        => O(n) complexity (dynamic programming)
        """
        distRoot = [0] + [-1]*(numElem)
        
        def lenToRoot (i) :
            """Length to get from one node to root"""
            if distRoot[i] == -1 : # if not visited
                distRoot[i] = 1 + lenToRoot(self.tree[i])
                return distRoot[i]
            else : # if visited (we have a score for it)
                return distRoot[i]
        
        for i in range (1, numElem+1) : # for every element
            lenToRoot(i) # updating distRoot list
        return max(distRoot)

    def commonAncestor (self, a, b) :
        """
        Finds nearest common ancestor to nodes a & b
        => O(h) [max complexity] : h = min(depthA, depthB)
        """
        predA = self.findPred(a)
        predB = self.findPred(b)
        lenA, lenB = len(predA), len(predB)
        # print (predA, predB)
        diffDepth = abs(len(predA) - len(predB)) # difference of depth between a & b
        i = 0 # starting index for nearest from root node
        if lenA < lenB : # if A is nearer from root than B
            while predB[diffDepth] != predA[i] :
                diffDepth += 1
                i += 1
            return predB[diffDepth]
        else :
            while predA[diffDepth] != predB[i] :
                diffDepth += 1
                i += 1
            return predA[diffDepth]

    def findMissing (self, code) :
        """
        Returns missing edges in trees that could correspond to the code given
        => Particular method to solve IOI problem
        """
        numCorrupted = code.count('?') # number of corrupted letters
        self.potentialCodes = []
        self.getPossibleCodes(code)
        print (' '.join(map(str, sorted(self.potentialCodes, key = self.findLenPred))))

    def getPossibleCodes (self, code, i=0, currCode = '') :
        """
        Find all possible codes to fill the questions marks 
        (corrupted file from the Anti-virus IOI problem)
        """
        if i == len(code) :
            if int(currCode) < self.length :
                self.potentialCodes.append(int(currCode))
        else :
            if code[i] == '?' :
                if i == 0 :
                    for j in range (1, 10) :
                        self.getPossibleCodes(code, i+1, currCode + str(j))
                else :
                    for j in range (10) :
                        self.getPossibleCodes(code, i+1, currCode + str(j))
            else :
                self.getPossibleCodes(code, i+1, currCode + code[i])

    def __repr__ (self) :
        return "Tree ({0})".format(self.tree)
            
if __name__ == "__main__" :
    numElem = int(input())
    reserve = list(map(int, read().split()))
    t = Tree(reserve)
    code = input()
    t.findMissing(code)