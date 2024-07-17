import sys

def read() :
    return sys.stdin.readline().strip()
def write(txt) :
    return sys.stdout.write(txt)

def main() :
    swaps = [] # list of swaps 
    while any([positions[i] > positions[i+1] for i in range (numCars-1)]) :
        for i in range (numCars-1) :
            first, second = positions[i], positions[i+1]
            if first > second :
                swaps.append (map(str, (first, second)))
                positions[i], positions[i+1] = second, first
    print(len(swaps))
    for i in swaps :
        print (' '.join(i))


if __name__ == '__main__' :
    numCars = int(read())
    positions = list(map(int, read().split()))
    main()