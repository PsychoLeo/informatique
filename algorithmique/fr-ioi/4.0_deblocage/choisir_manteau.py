# def main() :
#     """O(n^2) complexity"""
#     manteaux = [] # (t_inf, t_sup, score)
#     nbManteaux = int(input())
#     for i in range (nbManteaux) :
#         mini, maxi = map(int, input().split())
#         included = False # if this interval is included in other(s)
#         numIncluded = 0 # number of coats included in this current coat
#         toRemove = []
#         for j in range(len(manteaux)) :
#             if manteaux[j][0] <= mini and maxi <= manteaux[j][1] : # if current is included in one of the biggest coats
#                 manteaux[j][2] += 1
#                 included = True
#             elif mini <= manteaux[j][0] and maxi >= manteaux[j][1]:
#                 numIncluded += manteaux[j][2] + 1
#                 toRemove.append(j)
#         # Remarque : un manteau inclus dans un intervalle ne peut en englober un autre (propriété importante)
#         if not included : # if current coat is not included included in any of the current biggest intervals => add it
#             remove = [toRemove[i] - i for i in range (len(toRemove))]
#             for coat in remove :
#                 del manteaux[coat]
#             manteaux.append([mini, maxi, numIncluded])
#     print (max([i[2] for i in manteaux]))

import sys

def read() :
    return sys.stdin.readline().strip()

def main() :
    nbManteaux = int(input())
    manteaux = [tuple(map(int, read().split())) for _ in range (nbManteaux)]
    l1 = list(sorted(manteaux, key = lambda e : (e[0], -e[1])))
    l2 = list(sorted(manteaux, key = lambda e : (-e[1], e[0])))
    scores = {manteau:[float("+inf"), float("+inf")] for manteau in manteaux}
    for i in range (nbManteaux) :
        p1, p2 = l1[i], l2[i]
        if scores[p1][0] == float("+inf") :
            scores[p1][0] = i
        if scores[p2][1] == float("+inf") :
            scores[p2][1] = i
    print (nbManteaux - min([sum(i) for i in scores.values()]) -1)

    # print(manteaux)
    # vmax, vcourant = 0, 0
    # i = 0
    # while i < nbManteaux-1:
    #     if manteaux[i][0] <= manteaux[i+1][0] and manteaux[i][1] >= manteaux[i+1][1] :
    #         vcourant += 1
    #         del manteaux[i+1]
    #         nbManteaux -= 1
    #     else :
    #         vcourant = 0
    #         i += 1
    #     vmax = max(vmax, vcourant)
    # print (vmax)

if __name__ == "__main__" :
    main()