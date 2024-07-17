import sys

def read() : # fonction pour rendre plus rapide la lecture de l'input
    return sys.stdin.readline().strip()

def main(s):
    maxLen = 1
    stringLen = len(s) # placer la longueur du string dans une variable pour la réutiliser plus tard
    for midLetter in range (1, stringLen): # lettre du milieu à chaque itération
        stopDist = min(midLetter, stringLen-midLetter-1) # distance to end of string or to beginning of it
        if 2*stopDist+2 <= maxLen : # if maximum value possible with current position is <= best
            continue
        currentScore = Palindrome(s, midLetter, maxLen, stopDist)
        if currentScore > maxLen : # si le score est meilleur que le meilleur actuel => devient le meilleur
            maxLen = currentScore
    print (maxLen)
    # return maxLen

def Palindrome(s, midLetter, maxLen, stopDist) :
    """Find longest palindrome with a certain letter in the middle"""
    scores = []
    if s[midLetter] == s[midLetter-1] : # search with pair values in the middle
        currentScore = 2
        for j in range (1, stopDist+1):
            if s[midLetter+j] == s[midLetter-j-1]:
                currentScore += 2
            else :
                break # pour cette lettre et sa voisine gauche, le palindrome est maximal
        scores.append(currentScore)
    currentScore = 1
    for j in range (1, stopDist+1) :
        if s[midLetter+j] == s[midLetter-j] :
            currentScore += 2 # adding to the left and to the right of the word
        else :
            break
    scores.append(currentScore)
    return max(scores)

if __name__ == "__main__" :
    s = read()
    main(s)