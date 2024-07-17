import sys
from collections import deque

def read() :
    return sys.stdin.readline().strip()


def matching (txt):
    unmatched = deque()
    for i in txt :
        if not unmatched : # if list empty
            unmatched.append(i)
        elif i in closing :
            if i != complementary[unmatched.pop()] :
                print ("no"); return
        else :
            unmatched.append(i)
    if not unmatched : # if list is empty
        print ("yes")
    else :
        print ("no")


complementary = {'{':'}', '(':')', '[':']', '<':'>', ']':None, '>':None, '}':None, ')':None}
txt = ''.join([i for i in read() if i in {'{', '}', '[', ']', '(', ')', '<', '>'}])
closing = {'}', ']', '>', ')'}
matching(txt)
# print (txt)