def pair (n) :
    assert n > 0, 'n doit être un entier naturel'
    if n == 0 :
        return True
    elif n == 1 :
        return False
    else :
        return pair (n-2)

def pair_simple (n) :
    return not n%2