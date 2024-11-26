from PIL import Image
from math import sin, ceil, exp, cos

sn = 279132 # secret number 6 digits, sn += sn%2 : le rend pair, qui peut être le code de l'appli

def pn(a,b,c,x):
   return (a + b*x + c*x**2)%256

def digits(x):
   return (x//100)%10, (x//10)%10, x%10

#XOR est reversible

def f_abs(i,j):
   k = exp(4 + cos(i^73))
   l = exp(5 + cos(j^43))
   return ceil(1000*sin(k)) + ceil(1000*sin(l))



#Key is PWD SHA512 --> the hash provides 512 bits : 64o = 64 int. in [0; 255]
#key = [13, 17, 197, 240, 1, 155, 97, 201]
key = [146, 86, 198, 126, 251, 188, 157, 129, 124, 139, 179, 153, 239, 21, 238, 3, 110, 145, 107, 93, 104, 207, 60, 149, 233, 224, 58, 172, 242, 16, 192, 93, 53, 56, 70, 98, 214, 34, 214, 94, 51, 206, 155, 27, 158, 106, 172, 41, 194, 75, 67, 178, 88, 217, 153, 249, 41, 74, 185, 237, 120, 15, 20, 157]


def poly(r,g,b):
   r2 = pn(a_0,a_1,a_2,r)
   b_0, b_1, b_2 = digits(r)
   g2 = pn((a_0+1)*(b_0+1), (a_1+1)*(b_1 +1), (a_2+1)*(b_2+1), g)
   b2 = pn(a_0, a_1, a_2, b)
   return r2,g2,b2

def poly2(r,g,b,x,y,z):
   r2 = pn(a_0+x, a_1+y, a_2+z, r)
   g2 = pn(a_0+x, a_1+y, a_2+z, b)
   b2 = pn(a_0+x, a_1+y, a_2+z, b)
   return r2,g2,b2


def poly3(r,g,b,i,j):
   s = (i**3 + 1)*(j**3+1) 
   return (r+key[s%8]+s)%256,(g+key[s%8]+s)%256,(b+key[s%8]+s)%256


def poly4(r,g,b,i,j):
   s = (i**3 + 1)*(j**3+1) 
   return (r-key[s%8]-s)%256,(g-key[s%8]-s)%256,(b-key[s%8]-s)%256

#i**3 = 1 mod 4 donc rate les 4k+1


#Problème avec ça car on rate pleins de valeurs, comment recouvrir 255^2
#avec deux entiers, mais de façon aléatoire 

def poly5(r,b,g,i,j):
   s = ceil(1000*sin(i**2+j**2+1)) % 257
   return (r+key[s%8]+s)%256,(g+key[s%8]+s)%256,(b+key[s%8]+s)%256


def poly6(r,b,g,i,j):
   s = ceil(1000*sin(i**2+j**2+1)) %257
   return (r-key[s%8]-s)%256,(g-key[s%8]-s)%256,(b-key[s%8]-s)%256



def f_aux_encr(x, col, coeff_c):
   res = coeff_c*col
   a,b,c = digits(x)
   return (x+ (a+1+a%2)*x**3 + (b+1+b%2)*x**2 + (c+1+c%2)*x + res) %256 


def f_aux_decr(x, c, coeff_c):
   a,b,c = digits(x)
   return (coeff_c*(col - (x+ (a+1+a%2)*x**3 + (b+1+b%2)*x**2 + (c+1+c%2)*x))) %256


def new_f_encr(r,g,b,i,j):
   s = f_abs(i,j)
   coeff_r, coeff_g, coeff_b = 1,1,1 
   return (f_aux_encr(key[(sn+1)*s %8],r,coeff_r),f_aux_encr(key[(sn+3)*s %8],g,coeff_g), f_aux_encr(key[(sn+5)*s %8],b,coeff_b))

#le secret number vient shuffle mod32 : c'est bien uniforme

def new_f_decr(r,g,b,i,j):
   s = f_abs(i,j)
   coeff_r, coeff_g, coeff_b = 1,1,1  #inverses mod 256 de ceux ci-dessus
   return (f_aux_decr(key[(sn+1)*s %8],r,coeff_r), f_aux_decr(key[(sn+3)*s %8],g,coeff_g), f_aux_decr(key[(sn+5)*s %8],b,coeff_b))



def f_encr(r,g,b,i,j):
   s = f_abs(i,j)
   return (13*r+key[s%64]+s)%256,(17*g+key[(s+1)%64]+s)%256,(23*b+key[(s+2)%64]+s)%256

#multiplier par un entier premier avec 256 c'est pas mal

def old_f_encr(r,g,b,i,j):
   s = f_abs(i,j)
   return (r+key[s%8]+s)%256,(g+key[s%8]+s)%256,(b+key[s%8]+s)%256

def f_dec(r,g,b,i,j):
   s = f_abs(i,j)
   return (197*(r-key[s%64]-s))%256,(241*(g-key[(s+1)%64]-s))%256,(167*(b-key[(s+2)%64]-s))%256


def encryption():

   input_image = Image.open("test.png")
   pixel_map = input_image.load()
   width, height = input_image.size

   for i in range(width):
       for j in range(height):
            r,g,b,p = input_image.getpixel((i,j))
            r2,g2,b2 = f_encr(r,g,b,i,j)
            pixel_map[i, j] = (r2, g2, b2)
   input_image.save("testc.png", format="png")


def decryption():

   input_image = Image.open("test.png")
   pixel_map = input_image.load()
   width, height = input_image.size

   for i in range(width):
       for j in range(height):
           r,g,b= input_image.getpixel((i,j))
           r2,g2,b2 = f_dec(r,g,b,i,j)
           pixel_map[i, j] = (r2, g2, b2)

   input_image.save("testc.png", format="png")

#encryption()

def attack():
   input_image = Image.open("testc15.png")
   pixel_map = input_image.load()
   width, height = input_image.size

   for k in range(120):
       for i in range(width):
           for j in range(height):
               r,g,b,p = input_image.getpixel((i,j))
               r2,g2,b2 = f_encr(r,g,b,i,j)
               pixel_map[i, j] = (r2, g2, b2)
       print(k)        
       if k > 115 : 
           input_image.save(f"testc{k+15}.png", format="png")


#attack()

def attack2():
   input_image = Image.open("testc131.png")
   pixel_map = input_image.load()
   width, height = input_image.size

   for k in range(8):
       for i in range(width):
           for j in range(height):
               r,g,b,p = input_image.getpixel((i,j))
               r2,g2,b2 = f_dec(r,g,b,i,j)
               pixel_map[i, j] = (r2, g2, b2)

       input_image.save(f"testc{131-k-1}.png", format="png")

attack2()

def count_frequ():

   #input_image = Image.open("jen5.png")
   #pixel_map = input_image.load()
   #width, height = input_image.size

   width, height = 1000, 1000

   l = [0 for i in range(32)]

   for i in range(width):
       for j in range(height):
           k = f_abs(i,j)
           #print(k%32)
           l[k%32] += 1 
   print(l)
   print(width*height/32)
   print(min(l))
   print(max(l))


"""
#c'est parfaitement uniformisé, c'est même surpre
def f_attack(r,g,b,i,j):
   s = f_abs(i,j)
   return ((r-s)%256,(g-s)%256,(b-s)%256)

def attack():
   #récolte le max d'une image encryptée, marche bien sur old_f_encr
   input_image = Image.open("jenc.png")
   pixel_map = input_image.load()
   width, height = input_image.size

   for i in range(width):
       for j in range(height):
           r,g,b,p = input_image.getpixel((i,j))
           r2,g2,b2 = f_attack(r,g,b,i,j)
           pixel_map[i, j] = (r2, g2, b2)

   input_image.save("jenny", format="png")


def attack_base():

   input_image = Image.open("jenc.png")
   pixel_map = input_image.load()
   width, height = input_image.size
   lst = []
   for i in range(width):
       for j in range(height):
           s = f_abs(i,j)
           if s%32 == 0 :
               lst.append([(i,j), pixel_map[i,j]])
           else :
               pixel_map[i,j] = (255, 255, 255)

   for m in [13, 48]:
       for x in lst :
           s = f_abs(*x[0])
           r = 197*(x[1][0] - s - m) % 256
           g = (x[1][1] - s - m) % 256
           b = (x[1][2] - s - m) % 256
           pixel_map[i,j] = (r,g,b)
       input_image.save(f"jenced{m}.png", format="png")

#attack_base()
"""