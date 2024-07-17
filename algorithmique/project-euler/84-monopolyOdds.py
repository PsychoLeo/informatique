from random import randint, shuffle

def nextR(x) :
    if x >= 35 :
        return 5
    return ((x+5)//10)*10 + 5

def nextU(x) :
    if x >= 12 and x <= 18 :
        return 18
    return 12

def back3(x) :
    return (x-3)%40

def rolled3Double() :
    global lastRolls
    if lastRolls[0] == True == lastRolls[1] == lastRolls[2] :
        lastRolls = [False]*3
        return True
    return False

def modalString() :
    found = set()
    l = [None]*3
    for j in range (3) :
        maxi = 0
        for i in range (sz) :
            if board[i] > maxi and i not in found:
                maxi = board[i]
                l[j] = i
        found.add(l[j])
    return l

def makeMove(i, d) :
    global cci, chi
    # Returns final position after moving
    i = (i+d)%40
    if i == g2j : # if we have to go to jail
        i = 10
    elif i in ccp :
        cci = (cci + 1)%cn
        action = cc[cci]
        if action != None :
            i = action
    elif i in chp :
        chi = (chi+1)%cn
        action = cc[cci]
        if callable(action) :
            i = action(i)
        elif action != None :
            i = action
    return i

def game() :
    global lastRolls
    i = 0
    board[0] = 1
    moves = totalMoves # number of moves to make
    while moves > 0 :
        d1, d2 = randint(1, diceSides), randint(1, diceSides)
        lastRolls.pop()
        lastRolls = [d1==d2] + lastRolls
        if rolled3Double() : # if 3 consecutive doubles
            i = 10
        else :
            d = d1+d2
            i = makeMove(i, d)
        board[i] += 1
        moves -= 1
    return modalString() 

if __name__ == "__main__" :
    sz = 40
    totalMoves = 10*1000*1000
    board = [0]*sz # number of visited squares
    ccp = {2, 17, 33} # community chest positions
    chp = {7, 22, 36} # chance card positions
    g2j = 30 # go to jail position
    lastRolls = [False]*3 # bool set containing true if roll was double
    cc = [0, 10] + [None]*14
    ch = [0, 10, 11, 24, 39, 5, nextR, nextR, nextU, back3] + [None]*6
    cci = 0 # cc index
    chi = 0 # ch index
    cn = 16 # number of cc or ch cards
    shuffle(cc)
    shuffle(ch)
    diceSides = 4
    s = ''.join(map(str, game()))
    print(s)