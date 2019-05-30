def printMenu():
    print '------------------------------'
    print '        Calculator'
    print '------------------------------'
    print '        What to do?'
    print '------------------------------'
    print '1. add'
    print '2. sub'
    print '3. mul'
    print '4. div'
    print '0. quit'
    print '------------------------------'
    print '>>> ',

def opAdd(args):
    ret = 0

    for n in args:
        ret += n

    return ret

def opSub(lhs, rhs):
    return lhs - rhs

def opMul(args):
    ret = 1
    
    for n in args:
        ret *= n

    return ret

def opDiv(lhs, rhs):
    return float(lhs) / float(rhs)

while True:
    printMenu()

    cmd = raw_input()
    
    if cmd == '1':
        print 'input as many as you want (input result to quit)'

        nums = []

        while True:
            line = raw_input()

            if line == 'result':
                break

            nums.append(float(line))

        print '%d numbers added, result is %0.2f' % (len(nums), opAdd(nums))

    elif cmd == '2':
        print 'first oprand : ',
        firstOp = input()
        print 'second oprand : ',
        secondOp = input()

        print (str(firstOp) + ' - ' + str(secondOp) + ' = %0.2f' % opSub(firstOp, secondOp))

    elif cmd == '3':
        print 'input as many as you want (input result to quit)'

        nums = []

        while True:
            line = raw_input()

            if line == 'result':
                break

            nums.append(float(line))

        print '%d numbers multiplied, result is %0.2f' % (len(nums), opMul(nums))

    elif cmd == '4':
        print 'first oprand : ',
        firstOp = input()
        print 'second oprand : ',
        secondOp = input()

        if secondOp == 0:
            print 'Can\'t divide by zero!!!'
        else:
            print(str(firstOp) + '/' + str(secondOp) + ' = %0.2f' % opDiv(firstOp, secondOp))
    elif cmd == '0':
        print 'bye'
        break
    else:
        print 'Wrong command!'
        continue
