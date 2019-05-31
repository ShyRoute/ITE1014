while True:
    print 'Menu'
    print '1. 99dan   2. exit'
    menu = input()

    if menu == 1:
        print 'Input dan : ',
        dan = input()

        for i in range(1, 10):
            print '{} * {} = {}'.format(dan, i, dan*i)
    else:
        break
