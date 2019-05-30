print "what to do?",
cmd = raw_input()

print "first operand",
firstOp = input()

print "second operand",
secondOp = input()

if cmd == "+" or cmd == "add":
    print "result is %0.2f" % (firstOp + secondOp)
elif cmd == "*" or cmd == "mul":
    print "result is %0.2f" % (firstOp * secondOp)
else:
    isCmd = False
    isSub = False

    if cmd == "-" or cmd == "sub":
        isCmd = True
        isSub = True
		
    elif cmd == "/" or cmd == "div":
        isCmd = True
        isSub = False
    
    if isCmd:
        if isSub:
            opStr = "-"
        else:
            opStr = "/"
            
        print "first %s second or second %s first? (f%ss or s%sf)" % (opStr, opStr, opStr, opStr),

        opOrder = raw_input()

        if opOrder == ("f%ss" % opStr):
            if isSub:
                print "result is %0.2f" % (firstOp - secondOp)
            else:
                if secondOp == 0:
                    print "can't divide by zero!!!"
                else:
                    print "result is %0.2f" % (firstOp / secondOp)
        elif opOrder == ("s%sf" % opStr):
            if isSub:
                print "result is %0.2f" % (secondOp - firstOp)
            else:
                if firstOp == 0:
                    print "can't divide by zero!!!"
                else:
                    print "result is %0.2f" % (secondOp / firstOp)
        else:
            print "invalid order '%s'" % opOrder
    else:
        print "unknown command '%s'" % cmd
