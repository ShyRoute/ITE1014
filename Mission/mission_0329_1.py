while True :
    try :
        print '======= Calculator ======='
        n1 = input('First number : ')
        n2 = float(input('Second number : '))
        print 'Add : %.2f' % (n1+n2)
        print 'Sub : %.2f' % (n1-n2)
        print 'Mul : %.2f' % (n1*n2)
        print 'Div : %.2f \n' % (n1/n2)
    except ZeroDivisionError :
        print '== Cannot divide by zero == \n'
    except NameError :
        print '==== Input number plz ==== \n'
