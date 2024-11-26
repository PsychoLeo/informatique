from image_class import Img
from encryption_class import Encryption
import os, sys
import hashlib
    

lena_colors = Img(".input_img_dir/lena-colors.jpg", 'RGB')
# lena_colors.create_inverted()

encryptor = Encryption()

print(encryptor.encrypt_key())