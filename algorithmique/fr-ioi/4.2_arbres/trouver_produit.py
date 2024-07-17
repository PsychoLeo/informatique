import sys

def read():
    return sys.stdin.readline().strip()

class Tree :
    """
    Implementing Tree data structure class
    """

    def __init__(self, tree=[]):
        self.tree = [0] + tree # je viens de perdre 15 minutes pour avoir mis self.tree = []

    def findPred (self, pos) :
        """
        Returns predecessors of object to root
        """
        preds = [pos]
        while pos : # while value is not 0 (not at the root of the tree)
            pos = self.tree[pos]
            preds.append(pos)
        return reversed(preds[:-1]) # reverse list to get it from root (excluding 0) to object


    def addElem (self, predecessor, index=0) :
        """
        Insert an element at the index given 
        => If no index specified, appends the element to list
        """
        if index == 0 :
            self.tree.append(predecessor)
            return
        self.tree[index] = predecessor

    def __repr__ (self) :
        return "Tree ({0})".format(self.tree)
            
if __name__ == "__main__" :
    numElem = int(input())
    vals = list(map(int, read().split()))
    t = Tree(vals)
    numRequest = int(input()) # aussi perdu 15 minutes ici
    requests = list(map(int, read().split()))
    for req in requests :
        reqPred = map(str, t.findPred(req))
        print (' '.join(reqPred))