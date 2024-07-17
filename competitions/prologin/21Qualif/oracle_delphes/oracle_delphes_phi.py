import time
"""
https://forthright48.com/spoj-lcmsum-lcm-sum/
==> formule pour calculer la somme des lcm(i, n) pour i allant de 1 à n
"""

def phi(n):
    '''retourne phi(n), l'indicatrice d'Euler en n'''
    pass

def primeNumbers(k):
    '''rettourne un set des nombres premiers de 1 à k'''
    nums = [i for i in range (2, k)]
    i = 0
    while i < len(nums)-1 :
        # print(nums[i])
        for num in range (nums[i]*2, len(nums), nums[i]) :
            if num in nums :
                nums.remove(num)
            continue
        i += 1
    # returns nums
    return None

def findSum (k) :
    '''retourne la somme recherchée'''
    r = k*(k+1)/4



if __name__ == '__main__' :
    start = time.time()
    n = 10000
    primeNumbers(n)
    print(f'Time : {time.time()-start} seconds')