a = []

def ave(a) :
    for i in a :
        i += i
    return i / len(a)

    
while True :
    n = raw_input()
    if n == 'result' :
        break
    else :
        a.append(float(n))

b = ave(a)

print('%0.4f' % (b))
