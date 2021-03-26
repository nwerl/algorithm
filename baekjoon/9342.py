import re

T = input()
T = int(T)
while T:
    T-=1
    s = input()
    p = re.compile('[A-F]?A+F+C+[A-F]?')
    print("Infected!") if re.fullmatch(p, s) else print("Good")