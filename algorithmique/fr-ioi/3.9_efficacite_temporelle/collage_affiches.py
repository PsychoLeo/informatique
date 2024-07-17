import sys

def read() :
    return sys.stdin.readline().strip()

def main() :
    affiches = []
    for i in range (n) :
        request = read().split()
        if request == ['Q'] :
            print (len(affiches))
        else :
            longueurAffiche = int(request[1])
            if affiches == [] :
                affiches.append(longueurAffiche)
            else :
                while affiches != [] and affiches[-1] <= longueurAffiche :
                    affiches.pop()
                affiches.append(longueurAffiche)
                # i = findPos (longueurAffiche, affiches)
                # affiches = affiches[:i] + [longueurAffiche]
            # print (affiches)

def findPos (n, affiches) :
    if n < affiches[-1] :
        return len(affiches)
    for i in range (1, len(affiches)) :
        if affiches[i-1] > n >= affiches[i]:
            return i+1

if __name__ == "__main__": 
    n = int(read())
    main()