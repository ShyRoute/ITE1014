# -*- coding: euc-kr -*-

work = raw_input("Calculate : ")            # ���� ����
num1 = input("First Operand : ")            # ù��° ��
num2 = input("Second Operand : ")           # �ι�° ��

if work == '+' or work == 'add' :           # ���ϱ� ���ý�
    print 'Result : %.2f' % float(num1 + num2)  #�Ҽ��� ���ڸ� �Ǽ� ǥ��
elif work == '-' or work == 'sub' :         # ���� ���ý�
    order = raw_input('Choose - f-s or s-f : ')     #���� ���� ����
    if order == 'f-s' :
        print 'Result : %.2f' % float(num1 - num2)  #�Ҽ��� ���ڸ� �Ǽ� ǥ��
    elif order == 's-f' :
        print 'Result : &.2f' % float(num2 - num1)  #�Ҽ��� ���ڸ� �Ǽ� ǥ��
elif work == '*' or work == 'mul' :         #���ϱ� ���ý�
    print 'Result : %.2f' % float(num1 * num2)
elif work == '/' or work == 'div' :         #������ ����
    order = raw_input('Choose - f/s or s/f : ')     #���� ���� ����
    if order == 'f/s' :
        if num2 == 0 :  #0���� ���� ��
            print '=== Cannot divide by zero ==='
        else :
            print 'Result : %.2f' % float(num1 / num2)  #�Ҽ��� ���ڸ� �Ǽ� ǥ��
    elif order == 's/f' :
        if num1 == 0 :  #0���� ���� ��
            print '=== Cannot divide by zero ==='
        else :
            print 'Result : %.2f' % float(num2 / num1)  #�Ҽ��� ���ڸ� �Ǽ� ǥ��
