def main():
    n = int(input())
    debuts = []
    fins = []
    for i in range (n) :
        deb = input()
        debuts.append(deb)
        fin = input()
        fins.append(fin)
    for fin in fins :
        if fin not in debuts :
            print(fin)
        
main()