# -*- coding: euc-kr -*-

def add() : # ���ϱ� �Լ�
    total = 0 # total�� �ʱ�ȭ
    list1 = [] # ���� ����Ʈ ����
    print 'Input as many as you want(input result to quit)'
    while True : # ���� �ݺ�
        num = raw_input()
        if num == 'result' :
            break # result�϶� �Է� ����
        else :
            temp = float(num)
            list1.append(temp) # ���� ����Ʈ�� ���� �߰�
    for i in list1 :
        total = total + i # ����Ʈ�� �ִ� ���ڸ� total�� �� ����
    return total # total���� ����

def sub() : # ���� �Լ�
    num1 = input('First number : ')
    num2 = input('Second number : ') # �� �� �Է�
    result = num1 - num2
    return result # ���� ���� ����

def mul() : # ���� �Լ�
    total = 1 # total �� �ʱ�ȭ
    list2 = [] # ���� ����Ʈ ����
    print 'Input as many as you want(input result to quit)'
    while True : # ���� �ݺ�
        num = raw_input()
        if num == 'result' :
            break # result�� �Էµ� �� �Է� ����
        else :
            temp = float(num)
            list2.append(temp) # ���� ����Ʈ�� ���� �߰�
    for i in list2 :
        total = total * i # ����Ʈ�� �ִ� ���ڸ� total�� �� ����
    return total # total ���� ����

def div() :
    num1 = input('First number : ')
    num2 = input('Second number : ') # �� �� �Է�
    if num2 == 0 :
        print "Can't divide by zero" # �� ���ڰ� 0�� �� ���� ������ ���
    else :
        result = num1 / num2
        return result # ������ ���� ����
while True :
    print '=============================='
    print '          Calculator          '
    print '0.Quit 1.Add 2.Sub 3.Mul 4.Div'
    print '=============================='
    work = raw_input('What to do? ') # ���� ���� �Է�
    if work == '1' :
        print 'Result : %.2f' % add() # �Ҽ��� ���ڸ� ���� ����
    elif work == '2' :
        print 'Result : %.2f' % sub() # �Ҽ��� ���ڸ� ���� ����
    elif work == '3' :
        print 'Result : %.2f' % mul() # �Ҽ��� ���ڸ� ���� ����
    elif work == '4' :
        d = div()
        if d == None : # �� ���ڰ� 0�� �� ������� None���� ��µ�
            continue # Result�� ��µ��� �ʱ� ���� continue ������� ���� ��
        else :
            print 'Result :  %.2f' % d # �Ҽ��� ���ڸ� ���� ������
    elif work == '0' :
        print 'Exit program'
        break # 0�� �Է½� ���� ���� ����
    else :
        print 'Wrong command'
        continue # �߸��� �Է� �� ���� �ٽ� ������ ���Ͽ� continue ���
