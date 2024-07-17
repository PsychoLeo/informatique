import sys

def read() :
   return sys.stdin.readline().strip()
   
def main() :
    stack = []
    for i in pattern :
        if i == '(':
            stack.append(i)
        else : # if i == ')'
            try :
                stack.pop()
            except :
                print (0); return
    if stack != [] :
        print (0); return
    print (1)
   
if __name__ == "__main__" :
   _ = int(read())
   pattern = read().replace(' ', '')
   main()