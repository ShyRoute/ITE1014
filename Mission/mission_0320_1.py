while True :
    print 'Menu'
    work = input('Choose - 1. 99table 2. exit : ')
    if work == 1 :
        num = input('Input number : ')
        for i in range(1,10) :
            print (str(num) + '*' + str(i) + '=' + str(num*i))
    elif work == 2 :
        break
    
    
