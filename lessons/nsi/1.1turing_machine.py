def machine (r, i=0, state=1) :
    assert state in (0, 1, 2, 3), 'state has to be 1, 2 or 3'
    if state == 1 : # case state in java
        assert r[i] == None
        return machine (r, i+1, 2)
    elif state == 2 :
        if r[i] == None :
            return machine (r, i-1, 3)
        else :
            return machine (r, i+1, 2)
    elif state == 3 : # state is 3
        if r[i] == 0 :
            r[i] = 1
            return machine (r, i-1, 0)
        elif r[i] == 1 :
            r[i] = 0
            return machine (r, i-1, 3)
        else :
            return machine (r, i-1, 0)
    else :
        return r


# r1 = [None, 1, 0, 0, 1, 1, None, None]
# r2 = [None, 1, 1, 1, 1, None, None]
#
# print (machine (r1))
# print (machine (r2))