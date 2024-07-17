import sys

def read() :
    return sys.stdin.readline().strip()
def write(txt) :
    return sys.stdout.write(txt)

def bestDensity (request) :
    mini, maxi = 0, numDensities-1
    mid = maxi//2 # dichotomie
    while maxi-mini > 1:
        if request == densities[mid] :
            return densities[mid]
        elif request < densities[mid] :
            maxi = mid
        else : # if superior
            mini = mid
        mid = (mini+maxi)//2
    if abs(request-densities[mini]) <= abs(request-densities[maxi]) :
        return densities[mini]
    else :
        return densities[maxi]

def density (request, mini, maxi) :
    if mini <= maxi-1:
        return min([densities[mini], densities[maxi]], key=lambda elem : abs(request-elem))
    mid = (mini+maxi)//2
    if request == densities[mid] :
        return densities[mid]
    elif request < densities[mid] :
        return density(request, mini, mid-1)
    else :
        return density(request, mid+1, maxi)



def main() :
    for i in range (numRequests) :
        request = int(read())
        # result = density(request, 0, numRequests-1)
        result = bestDensity(request)
        print (result)

if __name__ == '__main__' :
    numDensities = int(read())
    densities = list(map(int, read().split()))
    densities.sort()
    # print (densities)
    numRequests = int(read())
    main()