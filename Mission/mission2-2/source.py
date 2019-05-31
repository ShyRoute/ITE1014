print 'input number'
number = input()

if type(number) is float:
    print 'this number is float'
else:
    if number < 0:
        print 'this number is negative'
    elif number == 0:
        print 'this number is 0'
    else:
        if number%2 == 1:
            print 'this number is odd'
        else:
            print 'this number is even'
