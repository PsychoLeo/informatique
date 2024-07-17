nbs = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
currPermNb = 0

def permutations (l=[]):
    global currPermNb
    if len(l) < 10 :
        for i in range (10) :
            if i not in l :
                permutations(l+[i])
    else :
        currPermNb += 1
        if currPermNb == 1000*1000 :
            print(' '.join(map(str, l)))

permutations()