import sys
input = sys.stdin.readline 

n, q = 100, 10000

def findCheater() :
    questionsMean = [0]*q
    deltaQuestions = [0]*n
    players = [0]*n
    for i in range (n) :
        l = list(map(int, list(input().strip())))
        # print(l)
        players[i] = l
        for j in range (q):
            # print(j)
            questionsMean[j] += l[j]
    for i in range (q) :
        questionsMean[i] /= q
    bestDiff = -1
    bestIndex = None
    for i in range (n) :
        deltaMoyenne = 0
        for j in range (q) :
            deltaMoyenne += abs(questionsMean[j]-players[i][j])
        if deltaMoyenne > bestDiff :
            bestDiff = deltaMoyenne
            bestIndex = i
    return bestIndex+1

def main() :
    t = int(input())
    p = int(input())
    for i in range (t) :
        print(f"Case #{i+1}: {findCheater()}")

main()
