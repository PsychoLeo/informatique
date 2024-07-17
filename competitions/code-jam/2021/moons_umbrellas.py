import sys
input = sys.stdin.readline 

prices = {('C', 'J'):x, ('J', 'C'):y}

def main() :
    t = int(input())
    for i in range (1, t+1) :
        n, c = map(int, input().split())
        print(f"Case #{i}: {bruteForce(n, c)}")

def moon_umbrellas (x, y, s) :
    # CJ -> pay X
    # JC -> pay Y
    n = len(s)
    toMark = 0
    if s[toMark] == '?' :
        while toMark < n and s[toMark] == '?' :
            toMark += 1
    if toMark >= n : # On remplit tout avec la même lettre
        return 0
    for i in range (toMark) : # marquer l'avant
        s[i] = s[toMark]
    toMark = -1
    while s[toMark] == '?' :
        toMark -= 1
    for i in range (toMark, 0) : # marquer l'arrière
        s[i] = s[toMark]
    # Jusqu'ici, rien ne coûte quelque chose
    prix = 0
    for i in range (1, n) : # on compte seulement le prix des prédecesseurs
        pred = i-1
        nexT = i+1
        while s[pred] == '?' :
            pred -= 1
        while nexT <n and s[nexT] == '?' :
            nexT += 1
        if s[i] == '?' :
            if s[pred] == s[nexT] :
                s[i] = s[pred] # on remplit avec la lettre actuelle : pas de prix en plus
            elif s[pred] == 'C' :
                s[i] = 'C'
            else :
                s[i] = 'J'
        if s[i-1] != s[i] :
            prix += prices[(s[i-1], s[i])]
    return prix

def bruteForce () :
    sizes = [list() for i in range (1001)]

main()