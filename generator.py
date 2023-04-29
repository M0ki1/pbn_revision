from random import random, randint,choice
import string
import sys

def randomword(length):
   letters = string.ascii_lowercase
   return ''.join(choice(letters) for i in range(length))

rango = int(sys.argv[1])

for i in range(rango):
    a = ""
    a+= randomword(10)
    a+= f",{round((randint(0,1000)+random()),2)}"
    a+= f",{round((randint(0,1000)+random()),2)}"
    print(a)
