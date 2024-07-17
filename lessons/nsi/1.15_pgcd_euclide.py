def pgcd (a, b):
    return a if b==0 else pgcd (b, a%b)

def inverse (string) :
    return string[::-1]

def inverse_ex (string) :
    if len(string) == 1 :
        return string
    else :
        return string[-1] + inverse_ex(string[:-1])