s1 = input()
s2 = input()

p1 = set()
p2 = set()
for i in range(len(s1)):
    for j in range(len(s1[i:])+1):
        p1.add(s1[i:][:j])
for i in range(len(s2)):
    for j in range(len(s2[i:])+1):
        p2.add(s2[i:][:j])
print(p1.intersection(p2).__len__())
