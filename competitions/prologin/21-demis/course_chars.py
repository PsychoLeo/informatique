def main():
    p = int(input())
    best = float("+inf")
    bestPilote = None
    for i in range (p) :
        pilote, temps, depass = map(int, input().split())
        if depass < 10 :
            if temps*(1+depass/10) < best :
                best = temps*(1+depass/10)
                bestPilote = pilote
    if bestPilote is None :
        return 0
    else :
        return bestPilote

print(main())