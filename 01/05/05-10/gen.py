#!/usr/bin/python3
from random import choice, randint
A = randint(0, 10**10000-1)
B = randint(0, 10**10000-1)
op = choice(('+', '-', '*',))

print(A, op, B, sep='')
