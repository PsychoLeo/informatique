def main() :
    txt = input()
    indentIter(txt)

# def indentBrackets (txt, spacing=0, i=0) :
#     if i == len(txt)-1 :
#         print (spacing*'\t' + txt[i])
#     else :
#         if txt[i] == '{' :
#             indentBrackets(txt, spacing+1, i+1)
#         else :
#             indentBrackets(txt, spacing-1, i+1)

def indentIter (txt) :
    nbIndent = -1
    for i in txt :
        if i == '}' :
            print (nbIndent*'\t' + i)
            nbIndent -= 1
        else :
            nbIndent += 1
            print (nbIndent*'\t' + i)

main()