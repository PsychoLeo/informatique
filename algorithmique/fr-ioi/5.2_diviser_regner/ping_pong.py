import sys
# from collections import deque

input = sys.stdin.readline

# def read():
#     return sys.stdin.readline().strip()

# def championnat():
#     global n, k, l
#     while len(l) > 1 : # tant que nous ne sommes pas en finale
#         # print(l)
#         A, B = l.popleft(), l.popleft()
#         minA, minB = min(A), min(B)
#         if abs(minA-minB) < k:
#             qualified = A.union(B)
#             l.append(qualified)
#         elif minA < minB: # Certains éléments de la partie A n'ont pas de chance
#             for element in A:
#                 if abs(minB-element) < k:
#                     B.add(element)
#             l.append(B)
#         elif minB < minA: # Certains éléments de la partie B n'ont pas de chance
#             for element in B:
#                 if abs(minA-element) <k:
#                     A.add(element)
#             l.append(A)
#     print(min(l[0]))

# if __name__ == '__main__':
#     n, k = map(int, read().split())
#     l = deque()
#     for i in map(int, read().split()) :
#         l.append({i})
#     championnat()


def main():
    n, K = map(int, input().split())
    participants = list(map(int, input().split()))
    def fusion(partA, partB):
        if partA == None and partB == None:
            return None
        elif partA == None:
            return partB
        elif partB == None:
            return partA
        minA = min(partA)
        minB = min(partB)
        
        if abs(minA-minB) < K: # TOus les éléments ont une chance
            return partA.union(partB)
        elif minA < minB: # Certains éléments de la partie A n'ont pas de chance
            for element in partA:
                if abs(minB-element) < K:
                    partB.add(element)
            return partB
            
        elif minB < minA: # Certains éléments de la partie B n'ont pas de chance
            for element in partB:
                if abs(minA-element) < K:
                    partA.add(element)
            return partA

    def niveauxPossibles(niv,iDeb):
        if niv==0: # Tout seul
            # print(participants[iDeb])
            return set([participants[iDeb]])
        partieA = niveauxPossibles(niv-1, iDeb) # set des niveaux possibles à gauche
        partieB = niveauxPossibles(niv-1, iDeb+2**(niv-1)) # sets des niveaux possibles à droite
        # print(f"NIV: {niv}\tiDEB: {iDeb}\tPartA: {partieA}\tPartB: {partieB}\tRESULT:")
        return fusion(partieA, partieB)
    return min(niveauxPossibles(n, 0))

if __name__ == "__main__" :
    print(main())