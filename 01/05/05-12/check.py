with open("input.txt") as fh:
    N = int(fh.readline().strip())
    M = [list(map(int, fh.readline().split())) for i in range(N)]
with open("output.txt") as fh:
    X = list(map(lambda x: int(x.strip()), fh.readlines()))

for row in M:
    if sum(map((lambda t: int.__mul__(*t)), zip(row[:-1], X))) != row[-1]:
        print("FAIL")
        print('\n'.join(' '.join(map(str, row) for row in M)))
        exit(1)
