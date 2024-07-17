def substract (r, i=0, state=1) :
    assert state in range(6), f'state has to be in {tuple(range(1, 6))}'
    if state == 1 :
        assert r[i] == None
        return substract(r, i+1, 2)
    elif state == 2 :
        if r[i] == None :
            return substract(r, i-1, 3)
        return substract(r, i+1, state)
    elif state == 3 :
        if r[i] == None:
            return substract(r, i+1, 3)
        elif r[i] == 0 :
            r[i] = 1
            return substract(r, i-1, 3)
        else :
            r[i] = 0
            return substract(r, i-1, 4)
    elif state == 4 :
        if r[i] == None :
            return substract(r, i+1, 5)
        return substract(r, i, 0)
    elif state == 5 :
        if r[i] == 0 :
            r[i] = None
        return substract(r, i, 0)
    else :
        return r

r1 = [None, 1, 0, 1, None]
r2 = [None, 1, 0, 1, 0, None]
r3 = [None, 1, 0, 0, None]
rubans = [r1, r2, r3]

for r in rubans :
    print (substract(r))