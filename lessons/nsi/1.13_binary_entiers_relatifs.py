def binaire_relatif (r, n=8, res=''):
    assert r <= 2**n, f'Number does not fit in {n-1} bits (one bit allowed for its sign)'
    print (f'Entering function with r={r} and res={res}')
    if r < -2 or r > 1 :
        return binaire_relatif(r//2, n, res+str(r%2))
    else :
        print (f'Entering base case with {r}')
        print (f'Binary : {res}')
        if r < 0 :
            if r == -2 :
                return '1'+(''.join(['1' if i=='0' else '0' for i in ('10'+res).zfill(n-1)]))
            else : # r==-1
                return '1'+(''.join(['1' if i=='0' else '0' for i in ('1'+res).zfill(n-1)]))
        else :
            return '0'+res.zfill(n-1)