# -*- coding: euc-kr -*-

import random

while True : # ���� ���α׷� ���� �����Դϴ�.
    
    # ù��° ��� �Է� ����
    while True : # �� ũ�� �Է� �����Դϴ�. ���� �� �ٽ� �ۼ��ޱ� ���� ���� ������ �Ͽ����ϴ�.
        try :
            r1 = int(raw_input('Row of first matrix : '))   # int�� �̿��Ͽ� ������ �ް� �Ͽ����ϴ�.
            if r1 <= 0 :
                print '=== Negative number or 0 ==='    # 0�̰ų� ������ �� ���� �޽����� ���� �ٽ� �Է¹ް� �Ͽ����ϴ�.
            else :
                break    # �ڿ����� �� while���� ������ ���� �������� �Ѿ�� �Ͽ����ϴ�.
        except :
            print '=== Input natural number ==='    # ������ �ƴϰų�, ���ڰ� �ƴ� ��쿡 except������ ���� �޽����� ���� �ٽ� �Է¹ް� �Ͽ����ϴ�.
            
    while True :    # �� ũ�� �Է� �����Դϴ�. �� ũ�� �Է� ������ �۵� ����� �����մϴ�.
        try :
            c1 = int(raw_input('Col of first matrix : '))  
            if c1 <= 0 :
                print '=== Negative number or 0 ==='  
            else :
                break 
        except :
            print '=== Input natural number ==='  

    # ù��° ��� ���� ����
    m1 = [] # ���� ������
    for i in range(r1) :
        m1.append([])   # �� ���� ������ �ϴ� �� ����Ʈ�� for���� �۵��� ������ ����ϴ�.
        for j in range(c1) :
            m1[i].append(random.randint(0, 2))  # �� �࿡ random�� ���ڸ� append�� �߰��մϴ�.
    # ù��° ��� ��� ����
    for i in range(r1) :
        print '[',  # ��ȣ�� �߰��Ͽ� �ð������� �� ���̰� �Ͽ����ϴ�.
        for j in range(c1) :
            print m1[i][j], # �� ����� ��ҵ��� for������ ���ʴ�� ����մϴ�.
        print ']'

    # �ι�° ��� �Է� ����
    while True :    # �� ũ�� �Է� �����Դϴ�. ���� �� �ٽ� �ۼ��ޱ� ���� ���� ������ �Ͽ����ϴ�.
        try :
            r2 = int(raw_input('Row of second matrix : '))  # int�� �̿��Ͽ� ������ �ް� �Ͽ����ϴ�.
            if r2 <= 0 :
                print '=== Negative number or 0 ==='    # 0�̰ų� ������ �� ���� �޽����� ���� �ٽ� �Է¹ް� �Ͽ����ϴ�.
            else :
                break    # ������ �� while���� ������ ���� �������� �Ѿ�� �Ͽ����ϴ�.
        except :
            print '=== Input natural number ==='    # ������ �ƴϰų�, ���ڰ� �ƴ� ��쿡 except������ ���� �޽����� ���� �ٽ� �Է¹ް� �Ͽ����ϴ�.

    while True :    # �� ũ�� �Է� �����Դϴ�. �� ũ�� �Է� ������ �۵� ����� �����մϴ�.
        try :
            c2 = int(raw_input('Col of second matrix : '))  
            if c2 <= 0 :
                print '=== Negative number or 0 ==='   
            else :
                break   
        except :
            print '=== Input natural number ==='    

    # �ι�° ��� ���� ����
    m2 = [] # ���� ������
    for i in range(r2) :
        m2.append([])   # �� ���� ������ �ϴ� �� ����Ʈ�� for���� �۵��� ������ ����ϴ�.
        for j in range(c2) :
            m2[i].append(random.randint(0, 2))  # �� �࿡ random�� ���ڸ� append�� �߰��մϴ�.
    # �ι�° ��� ��� ����
    for i in range(r2) :
        print '[',  # ��ȣ�� �߰��Ͽ� �ð������� �� ���̰� �Ͽ����ϴ�.
        for j in range(c2) :
            print m2[i][j], # �� ����� ��ҵ��� for������ ���ʴ�� ����մϴ�.
        print ']'

    # ��Ģ���� - ����1 ( ���� ���� ����, ���� ���� )
    if r1 == r2 and c1 == c2 and c1 != r2 :
        w1 = raw_input('Choose + or - : ')
        if w1 == '+' :
            result1 = []    # ��� ���, ����� ���� �����ϰ� append�� ����մϴ�.
            for i in range(r1) :
                result1.append([])
                for j in range(c1) :
                    result1[i].append(m1[i][j] + m2[i][j])  # ������ ������� append�� �߰��մϴ�.
            for i in range(r1) :    # ��� ���, ����� ���� �����մϴ�.
                print '[',
                for j in range(c1) :
                    print result1[i][j],
                print ']'
            q1 = raw_input('Continue o or x : ')    # ����� �������� �Է¹޽��ϴ�. o �Է½� continue�� ���ν���, x �Է½� break�� �����ϴ�.
            if q1 == 'o' :
                print
                continue
            elif q1 == 'x' :
                break
        elif w1 == '-' :
            result1 = []    # ��� ���, ����� ���� �����ϰ� append�� ����մϴ�.
            for i in range(r1) :
                result1.append([])
                for j in range(c1) :
                    result1[i].append(m1[i][j] - m2[i][j])  # ������ ������� append�� �߰��մϴ�.
            for i in range(r1) :    # ��� ���, ����� ���� �����մϴ�.
                print '[',
                for j in range(c1) :
                    print result1[i][j],
                print ']'
            q1 = raw_input('Continue o or x : ')    # ����� �������� �Է¹޽��ϴ�. o �Է½� continue�� ���ν���, x �Է½� break�� �����ϴ�.
            if q1 == 'o' :
                print
                continue
            elif q1 == 'x' :
                break
            
    # ��Ģ���� - ����2 ( ���� ����, ���� ���� )
    elif c1 == r2 and r1 != r2 and c1 != c2 :
        w2 = raw_input('Choose * : ')
        if w2 == '*' :
            result2 = [[] for i in range(r1)]   # ���� ������ �ٸ��� ��ü ����� �̸� ����� �����ϴ�.
            for i in range(r1) :
                for j in range(c2) :
                    s = 0    # �� ĭ�� ���� ������ �հ踦 ���� �����Դϴ�.
                    for k in range(r2) :
                        s += (m1[i][k] * m2[k][j])  # �� ��� ���� ���ڵ��� ���� ���� ���� ���ʴ�� ���մϴ�.
                    result2[i].append(s)    # �� �� �̸� ������� ��Ŀ� �߰��մϴ�.
            for i in range(r1) :    # ��� ���, ����� ���� �����մϴ�.
                print '[',
                for j in range(c2) :
                    print result2[i][j],
                print ']'
            q2 = raw_input('Continue o or x : ')    # ����� �������� �Է¹޽��ϴ�. o �Է½� continue�� ���ν���, x �Է½� break�� �����ϴ�.
            if q2 == 'o' :
                print
                continue
            elif q2 == 'x' :
                break

    # ��Ģ���� - ����3 ( ���� ���� ���� ����, ���� ���� )
    
    # ���Ǹ� �ٸ� �� ���� ����� ���� �����ϹǷ� �����Ͽ����ϴ�.
    elif r1 == r2 and c1 == c2 and c1 == r2 :
        w3 = raw_input('Choose + or - or * : ')
        if w3 == '+' :
            result3 = []
            for i in range(r1) :
                result3.append([])
                for j in range(c1) :
                    result3[i].append(m1[i][j] + m2[i][j])
            for i in range(r1) :
                print '[',
                for j in range(c1) :
                    print result3[i][j],
                print ']'
            q3 = raw_input('Continue o or x : ')
            if q3 == 'o' :
                print
                continue
            elif q3 == 'x' :
                break
        elif w3 == '-' :
            result3 = []
            for i in range(r1) :
                result3.append([])
                for j in range(c1) :
                    result3[i].append(m1[i][j] - m2[i][j])
            for i in range(r1) :
                print '[',
                for j in range(c1) :
                    print result3[i][j],
                print ']'
            q3 = raw_input('Continue o or x : ')
            if q3 == 'o' :
                print
                continue
            elif q3 == 'x' :
                break
        elif w3 == '*' :
            result3 = [[] for i in range(r1)]
            for i in range(r1) :
                for j in range(c2) :
                    s = 0
                    for k in range(r2) :
                        s += (m1[i][k] * m2[k][j])
                    result3[i].append(s)
            for i in range(r1) :
                print '[',
                for j in range(c2) :
                    print result3[i][j],
                print ']'
            q3 = raw_input('Continue o or x : ')
            if q3 == 'o' :
                print
                continue
            elif q3 == 'x' :
                break
    # ��Ģ���� - ����4 ( ��� �Ұ����� ��, ���� ���� )
    else :
        print '=== Cannot calculate ==='
