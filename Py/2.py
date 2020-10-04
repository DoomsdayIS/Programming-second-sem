n = input()
n = n[::-1]
flag = 228322
cnt = 0
for i in range(len(n)):
    if n[i] != '1':
        flag = i
        break
for i in range(flag + 1,len(n)):
    if n[i] == '1':
        cnt += 1
print(cnt)
