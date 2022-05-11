a = [i for i in range(1,1001)]
for i in a:
    print(id(i))
    if i < 500:
        i = i*i
    elif i < 800:
        i = -i
    else:
        i = i + 1000
    print(id(i))
print(*a)
