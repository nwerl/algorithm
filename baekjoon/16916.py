def makePi():
    n = len(t)
    pi = [0]*n
    j = 0
    for i in range(1, n):
        while j>0 and t[i] != t[j]:
            j = pi[j-1]
        if t[i] == t[j]:
            j += 1
            pi[i] = j

    return pi

def kmp():
    pi = makePi()
    n = len(s)
    m = len(t)
    j = 0

    for i in range(n):
        while j>0 and s[i] != t[j]:
            j = pi[j-1]
        if s[i] == t[j]:
            if j == m-1:
                return True
            else:
                j = j+1

    return False



s = input()
t = input()
print(1 if kmp() else 0)