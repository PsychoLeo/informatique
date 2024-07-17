import random

def mergeSort (l):
    if len(l) <= 1 :
        return l
    else :
        n = len(l)
        return merge(mergeSort(l[:n//2]), mergeSort(l[n//2:]))

def merge(l1, l2):
    if not l1 :
        return l2
    if not l2 :
        return l1
    i, j = 0, 0
    totLen = len(l1) + len(l2)
    l1.append(float("+inf"))
    l2.append(float("+inf"))
    res = []
    for _ in range (totLen) :
        if l1[i] < l2[j] :
            res.append(l1[i])
            i += 1
        else :
            res.append(l2[j])
            j += 1
    return res

if __name__ == "__main__" :
    n = 10
    l = [random.randint(0, 20) for _ in range (n)]
    print (l)
    sortedList = mergeSort(l)
    print (sortedList)