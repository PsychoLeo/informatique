def erath() :
    """
    Eratosthene algorithm
    Finds prime numbers between 1 and n
    Complexity : O(n ln ln n)
    """
    P = [True]*MAX
    primes = []
    P[0] = P[1] = False
    for i in range (2, MAX) :
        if P[i] :
            primes.append(i)
            for i in range (i*i, MAX, i) :
                P[i] = False
    return P, primes

def possibleSums(n, i=0) :
    """
    We would like to find all the possible coefficients (a1, a2, ..., an) natural numbers
    such that : n = SUM(i=1 to n) of ai*p_i
    with p_i the i-th prime number
    
    n : number we want to determine the number of possible ways to write it as a sum
    of prime numbers
    i : index in the prime numbers list
    """
    if n == 0 : # we have reached a solution
        return 1
    elif primes[i] > n: # if we are over our number
        return 0
    r = 0
    for j in range (0, n+1, primes[i]) :
        r += possibleSums(n-j, i+1)
    return r
    

if __name__ == "__main__" :
    n = 1
    MAX = 1000 # we don't need much prime numbers
    P, primes = erath()
    sums = [-1]*MAX
    count = 0
    while count < 5000 :
        n += 1
        count = possibleSums(n)
    print(n)