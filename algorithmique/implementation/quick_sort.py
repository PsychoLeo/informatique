import random

def quickSort (l, first, last) :
    if first < last :
        pivot = random.randint(first, last)
        pivot = partitionner(l, first, last, pivot)
        quickSort(l, first, pivot-1)
        quickSort(l, pivot+1, last)
    return l

def partitionner (l, first, last, pivot) :
    l[pivot], l[last] = l[last], l[pivot]
    j = first
    for i in range (first, last) :
        if l[i] <= l[last] :
            l[i], l[j] = l[j], l[i]
            j += 1
    l[last], l[j] = l[j], l[last]
    return j


if __name__ == "__main__" :
    n = 10
    l = [random.randint(0, 20) for _ in range (n)]
    print (l)
    sortedList = quickSort(l, 0, n-1)
    print (sortedList)
