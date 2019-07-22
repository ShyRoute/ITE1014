# -*- coding: euc-kr -*-

import random

while True : # 메인 프로그램 무한 루프입니다.
    
    # 첫번째 행렬 입력 과정
    while True : # 행 크기 입력 루프입니다. 오류 시 다시 작성받기 위해 무한 루프로 하였습니다.
        try :
            r1 = int(raw_input('Row of first matrix : '))   # int를 이용하여 정수로 받게 하였습니다.
            if r1 <= 0 :
                print '=== Negative number or 0 ==='    # 0이거나 음수일 시 에러 메시지를 띄우고 다시 입력받게 하였습니다.
            else :
                break    # 자연수일 시 while문을 끝내고 다음 과정으로 넘어가게 하였습니다.
        except :
            print '=== Input natural number ==='    # 정수가 아니거나, 숫자가 아닐 경우에 except문으로 에러 메시지를 띄우고 다시 입력받게 하였습니다.
            
    while True :    # 열 크기 입력 루프입니다. 행 크기 입력 루프와 작동 방식은 동일합니다.
        try :
            c1 = int(raw_input('Col of first matrix : '))  
            if c1 <= 0 :
                print '=== Negative number or 0 ==='  
            else :
                break 
        except :
            print '=== Input natural number ==='  

    # 첫번째 행렬 생성 과정
    m1 = [] # 메인 데이터
    for i in range(r1) :
        m1.append([])   # 각 행의 역할을 하는 빈 리스트를 for문이 작동할 때마다 만듭니다.
        for j in range(c1) :
            m1[i].append(random.randint(0, 2))  # 각 행에 random한 숫자를 append로 추가합니다.
    # 첫번째 행렬 출력 과정
    for i in range(r1) :
        print '[',  # 괄호를 추가하여 시각적으로 잘 보이게 하였습니다.
        for j in range(c1) :
            print m1[i][j], # 각 행렬의 요소들을 for문으로 차례대로 출력합니다.
        print ']'

    # 두번째 행렬 입력 과정
    while True :    # 행 크기 입력 루프입니다. 오류 시 다시 작성받기 위해 무한 루프로 하였습니다.
        try :
            r2 = int(raw_input('Row of second matrix : '))  # int를 이용하여 정수로 받게 하였습니다.
            if r2 <= 0 :
                print '=== Negative number or 0 ==='    # 0이거나 음수일 시 에러 메시지를 띄우고 다시 입력받게 하였습니다.
            else :
                break    # 정수일 시 while문을 끝내고 다음 과정으로 넘어가게 하였습니다.
        except :
            print '=== Input natural number ==='    # 정수가 아니거나, 숫자가 아닐 경우에 except문으로 에러 메시지를 띄우고 다시 입력받게 하였습니다.

    while True :    # 열 크기 입력 루프입니다. 행 크기 입력 루프와 작동 방식은 동일합니다.
        try :
            c2 = int(raw_input('Col of second matrix : '))  
            if c2 <= 0 :
                print '=== Negative number or 0 ==='   
            else :
                break   
        except :
            print '=== Input natural number ==='    

    # 두번째 행렬 생성 과정
    m2 = [] # 메인 데이터
    for i in range(r2) :
        m2.append([])   # 각 행의 역할을 하는 빈 리스트를 for문이 작동할 때마다 만듭니다.
        for j in range(c2) :
            m2[i].append(random.randint(0, 2))  # 각 행에 random한 숫자를 append로 추가합니다.
    # 두번째 행렬 출력 과정
    for i in range(r2) :
        print '[',  # 괄호를 추가하여 시각적으로 잘 보이게 하였습니다.
        for j in range(c2) :
            print m2[i][j], # 각 행렬의 요소들을 for문으로 차례대로 출력합니다.
        print ']'

    # 사칙연산 - 조건1 ( 덧셈 뺄셈 가능, 보고서 참조 )
    if r1 == r2 and c1 == c2 and c1 != r2 :
        w1 = raw_input('Choose + or - : ')
        if w1 == '+' :
            result1 = []    # 결과 행렬, 방식은 위와 동일하게 append를 사용합니다.
            for i in range(r1) :
                result1.append([])
                for j in range(c1) :
                    result1[i].append(m1[i][j] + m2[i][j])  # 덧셈한 결과값을 append로 추가합니다.
            for i in range(r1) :    # 결과 출력, 방식은 위와 동일합니다.
                print '[',
                for j in range(c1) :
                    print result1[i][j],
                print ']'
            q1 = raw_input('Continue o or x : ')    # 계속할 것인지를 입력받습니다. o 입력시 continue로 새로시작, x 입력시 break로 끝냅니다.
            if q1 == 'o' :
                print
                continue
            elif q1 == 'x' :
                break
        elif w1 == '-' :
            result1 = []    # 결과 행렬, 방식은 위와 동일하게 append를 사용합니다.
            for i in range(r1) :
                result1.append([])
                for j in range(c1) :
                    result1[i].append(m1[i][j] - m2[i][j])  # 뺄셈한 결과값을 append로 추가합니다.
            for i in range(r1) :    # 결과 출력, 방식은 위와 동일합니다.
                print '[',
                for j in range(c1) :
                    print result1[i][j],
                print ']'
            q1 = raw_input('Continue o or x : ')    # 계속할 것인지를 입력받습니다. o 입력시 continue로 새로시작, x 입력시 break로 끝냅니다.
            if q1 == 'o' :
                print
                continue
            elif q1 == 'x' :
                break
            
    # 사칙연산 - 조건2 ( 곱셈 가능, 보고서 참조 )
    elif c1 == r2 and r1 != r2 and c1 != c2 :
        w2 = raw_input('Choose * : ')
        if w2 == '*' :
            result2 = [[] for i in range(r1)]   # 덧셈 뺄셈과 다르게 전체 행렬을 미리 만들어 놓습니다.
            for i in range(r1) :
                for j in range(c2) :
                    s = 0    # 한 칸에 들어가는 곱셈의 합계를 위한 변수입니다.
                    for k in range(r2) :
                        s += (m1[i][k] * m2[k][j])  # 각 행과 열의 숫자들을 서로 곱한 값을 차례대로 더합니다.
                    result2[i].append(s)    # 그 후 미리 만들어진 행렬에 추가합니다.
            for i in range(r1) :    # 결과 출력, 방식은 위와 동일합니다.
                print '[',
                for j in range(c2) :
                    print result2[i][j],
                print ']'
            q2 = raw_input('Continue o or x : ')    # 계속할 것인지를 입력받습니다. o 입력시 continue로 새로시작, x 입력시 break로 끝냅니다.
            if q2 == 'o' :
                print
                continue
            elif q2 == 'x' :
                break

    # 사칙연산 - 조건3 ( 덧셈 뺄셈 곱셈 가능, 보고서 참조 )
    
    # 조건만 다를 뿐 연산 방식은 위와 동일하므로 생략하였습니다.
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
    # 사칙연산 - 조건4 ( 계산 불가능일 때, 보고서 참조 )
    else :
        print '=== Cannot calculate ==='
