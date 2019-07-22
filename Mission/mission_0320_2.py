for i in range(0,9) :
    if i<5 :
        print (' ' * (4-i)),
        print ('*' * (i*2+1))
    else :
        print (' ' * (i-4)),
        print ('*' * (17-i*2))
