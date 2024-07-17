import time
import random

def bubbleSort (l) :
    '''
    input : list to sort
    output : sorted list using bubble sort
    '''
    i, swaps = 0, 0
    while True :
        if i == len(l)-1 :
            if swaps == 0 :
                break
            else :
                swaps, i = 0, 0
        else :
            if l[i] > l[i+1] :
                l[i], l[i+1] = l[i+1], l[i]
                swaps += 1
            i += 1
    return l


def getRandomList (size, max_val) :
    return [random.randint(0, max_val) for _ in range (int(size))]

if __name__ == '__main__' :
    liste = getRandomList(1000, 100)
    start = time.time()
    sorted_list = bubbleSort (liste)
    print(f'Time using bubble sort : {time.time()-start} seconds')