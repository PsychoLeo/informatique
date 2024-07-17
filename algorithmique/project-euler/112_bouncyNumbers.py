n = 1 # total number count
b = 0 # bouncy count
p = 0.99 # proportion of bouncy number to reach

def isBouncy(n) :
    if n < 100 :
        return False
    n = str(n)
    return (not incr(n)) and (not decr(n))

def incr(n) :
    for i in range(1, len(n)) :
        if n[i-1] < n[i] :
            return False
    return True

def decr(n) :
    for i in range(1, len(n)) :
        if n[i-1] > n[i] :
            return False
    return True

while b/n < p :
    n += 1
    b += isBouncy(n)
print(n)