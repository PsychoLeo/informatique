def main() :
    maxLen, jours = map(int, input().split())
    stages (jours, maxLen)

def stages(jours, maxi, currDist=1, path='') :
    if jours == 0 :
        print (path)
    else :
        for i in range (currDist, maxi+1) :
            stages(jours-1, maxi, i, path+str(i)+' ')

main()