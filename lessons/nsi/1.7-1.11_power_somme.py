def power (x, n) :
    if n > 1 :
        return x * x * power(x, n-2)
    elif n == 1:
        return x
    else :
        return 1


def somme (a, b) :
    if b > 0 :
        return somme (a+1, b-1)
    elif b < 0 :
        return somme (a-1, b+1)
    else :
        return a


# def powerB (x, n, r=1) :
#     if n > 1 :
#         return powerB (x, n-1, r*x)
#     elif n == 1 :
#         return x * r * r
#     else :
#         return r * r


def somme_liste (l, i=0, r=0):
    if i < len(l) :
        return somme_liste (l, i+1, r+l[i])
    else :
        return r