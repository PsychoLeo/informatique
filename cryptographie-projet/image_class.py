from PIL import Image
import os

class Img :

    def __init__(self, path, type) :
        self.path = path
        self.type = type
        self.im_name = os.path.basename(self.path).split('.')[0] # get the filename without the extension at the end
        try:
            self.im = Image.open(self.path)
            self.im.convert(self.type)
            self.w, self.h = self.im.size
        except FileNotFoundError:
            print(f"Erreur : File {self.path} does not exist.")
        except Exception as e:
            print(f"Following error occured : {e}")

    def create_inverted(self) :
        inv_img = Image.new(self.type, (self.w, self.h))
        for x in range (self.w) :
            for y in range (self.h) :
                r, g, b = self.im.getpixel((x, y))
                inv_img.putpixel((x, y), (255-r, 255-g, 255-b))
        inv_img.save("inv-filter.jpg")
        inv_img.show()

    def encrypt(self, f_encr) :
        pixel_map = self.im.load()
        for i in range(self.w):
            for j in range(self.h):
                    r,g,b,p = self.im.getpixel((i,j))
                    r2,g2,b2 = self.f_encr(r,g,b,i,j)
                    pixel_map[i, j] = (r2, g2, b2)
        self.im.save(f"./output_img_dir/encr_{self.im_name}.png", format="png")

    def decrypt(self, f_decr) :
        pass