import random

def f1(n) :
    list1 = random.sample(range(1,100), n)
    return list1

def f2(list1) :
    for i in range(len(list1)-1) :
        for j in range(len(list1)-1-i) :
            if list1[j] > list1[j + 1] :
                a = list1[j]
                list1[j] = list1[j + 1]
                list1[j + 1] = a
    return list1
