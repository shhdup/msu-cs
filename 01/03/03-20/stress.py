R = 2**32

from random import randint
from os import system

while True:
    x = randint(1, R-1)
    if system("./check.sh " + str(x)):
        print(x)
        R = x
