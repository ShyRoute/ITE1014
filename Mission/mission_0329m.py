def sr1(a, b) :
    lower = 'abcdefghijklmnopqrstuvwxyz'
    upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    l1 = []

    if a in lower and b in lower :
        a1 = lower.index(a)
        b1 = lower.index(b)
        for i in range(a1,b1) :
            t = lower[i]
            l1.append(t)
    elif a in upper and b in upper :
        a1 = upper.index(a)
        b1 = upper.index(b)
        for i in range(a1,b1) :
            t = upper[i]
            l1.append(t)
    return l1

def sr2(a, b) :
    a2 = ord(a)
    b2 = ord(b)
    l2 = []
    for i in range(a2, b2) :
        i = chr(i)
        l2.append(i)
    return l2
