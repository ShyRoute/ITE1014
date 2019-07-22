num = input("Input number : ")

if type(num) is float :
    print "This is float type"
else :
    if num < 0 :
        print "This is negative"
    elif num == 0 :
        print "This is 0"
    else :
        if num % 2 == 1 :
            print "This is odd number"
        else :
            print "This is even number"
