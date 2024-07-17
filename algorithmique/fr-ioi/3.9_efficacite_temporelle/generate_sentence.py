import random
from long_palindrome import *
from string import ascii_lowercase
from long_palindrome_test import *
import time

def genSentence (length) :
    alph = list(ascii_lowercase)
    palindromes = ['yeeeeey', 'plagalp', 'heh', 'pennep']
    proba = [random.random() for i in range (length)]
    return ''.join([random.choice(alph) if i>0.05 else random.choice(palindromes) for i in proba])

if __name__ == "__main__" :
    size = 4000
    l = []
    for size in range (100, 1000, 100) :
        s = genSentence(size)
        # print (s)
        # t = time.time()
        # print (f"Program : {main(s)}")
        # print (f"Time : {time.time()-t} seconds")
        # print ()
        # t = time.time()
        # print(f"GFG program : {longestPalSubstr(s)}")
        # print (f"Time : {time.time()-t} seconds")
        own = main(s)
        other = longestPalSubstr(s)
        if own != other :
            print (s)