from image_class import Img
from encryption_class import Encryption
import os, sys
import hashlib
    

lena_colors = Img("lena-colors.jpg", 'RGB')
# lena_colors.create_inverted()

encryptor = Encryption()

print(encryptor.encrypt_key())