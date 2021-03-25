T = int(input())
for i in range(0, T):
    ans = "YES"
    s = input()
    stk = 0
    for j in range(0, len(s)):
        if s[j] == '(':
            stk+=1
        else:
            stk-=1
        if stk < 0:
            ans = "NO"
            break
    if stk != 0:
        ans = "NO"
    print(ans)
