from PIL import Image

class Img :

    def __init__(self, path, type) :
        self.path = path
        self.type = type
        self.im = Image.open(self.path)
        self.im.convert(self.type)
        self.w, self.h = self.im.size

    def create_inverted(self) :
        inv_img = Image.new(self.type, (self.w, self.h))
        for x in range (self.w) :
            for y in range (self.h) :
                r, g, b = self.im.getpixel((x, y))
                inv_img.putpixel((x, y), (255-r, 255-g, 255-b))
        inv_img.save("inv-filter.jpg")
        inv_img.show()

    def encrypt(self, pix_bij, f) :
        pass

    def decrypt(self, pix_bij, f) :
        pass