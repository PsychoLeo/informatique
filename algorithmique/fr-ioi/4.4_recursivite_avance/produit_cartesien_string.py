def findWords (lenPoss, lenWd, currWd= ""):
    if lenPoss == 0 :
        print(currWd); return
    else :
        for j in range (lenWd) :
            findWords(lenPoss-1, lenWd, currWd+word[j])

lenWd = int(input())
word = sorted(input()) # sort word in alph order
lenPoss = int(input())
print (lenWd**lenPoss) # number of different possible words
findWords(lenPoss, lenWd)