MOD = '3 abc'

from os import system

for i in range(100):
    print(i, ": ", end="")
    system("python gen.py " + MOD + " " + str(i) + " > input.txt")
    system("./a.out < input.txt > answer.txt")
    system("./petr < input.txt > output.txt")
    if system("diff output.txt answer.txt"):
        print("FAIL")
        exit()
    print()
