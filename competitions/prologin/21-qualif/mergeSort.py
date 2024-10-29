from random import randint 
import time

def sort (l) :
	if len(l) < 50 :
		return bubbleSort(l)
	else :
		return mergeSort(l) 

def mergeSort (l) :
	'''
	input : list
	output : list of sorted values using merge sort : O(n*log(n))
	'''
	pass
	

def bubbleSort (l) :
	'''
	input : list
	output : lsit of sorted value using bubble sort : O(n^2)
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
	
def randomList (size, max_val) :
	return [randint(0, max_val) for _ in range (size)]
	
if __name__ == '__main__' :
	size = 49
	max_val = 1000
	l = randomList (size, max_val)
	start = time.time()
	print (sort(l))
	print (f'Time : {time.time()-start} seconds')