import sys

def isRugissant(year):
    year = str(year)
    for k in range(1,len(year)//2+1):
        number = int(year[:k])
        
        reste = year[k:]
        number+=1

        while True:
            if reste == "":
                return True

            sizeNumber = len(str(number))
            if sizeNumber > len(reste):
                break
            if str(number) == reste[:sizeNumber]:
                reste = reste[sizeNumber:]
                number+=1
            else:
                break
    return False

def solve():
    year = int(input().strip())
    year+=1
    while not isRugissant(year):
        year+=1
    return year

def input() :
	return sys.stdin.readline().strip()

if __name__ == '__main__':

    nbTests = int(input())
    for t in range(1, nbTests+1):
        print(f"Case #{t}: {solve()}")
