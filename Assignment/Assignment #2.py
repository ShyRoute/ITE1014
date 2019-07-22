# -*- coding: euc-kr -*-

def add() : # 더하기 함수
    total = 0 # total값 초기화
    list1 = [] # 덧셈 리스트 생성
    print 'Input as many as you want(input result to quit)'
    while True : # 무한 반복
        num = raw_input()
        if num == 'result' :
            break # result일때 입력 종료
        else :
            temp = float(num)
            list1.append(temp) # 덧셈 리스트에 숫자 추가
    for i in list1 :
        total = total + i # 리스트에 있는 숫자를 total에 다 더함
    return total # total값을 리턴

def sub() : # 뺄셈 함수
    num1 = input('First number : ')
    num2 = input('Second number : ') # 두 수 입력
    result = num1 - num2
    return result # 뺄셈 값을 리턴

def mul() : # 곱셈 함수
    total = 1 # total 값 초기화
    list2 = [] # 곱셈 리스트 생성
    print 'Input as many as you want(input result to quit)'
    while True : # 무한 반복
        num = raw_input()
        if num == 'result' :
            break # result가 입력될 때 입력 종료
        else :
            temp = float(num)
            list2.append(temp) # 곱셈 리스트에 숫자 추가
    for i in list2 :
        total = total * i # 리스트에 있는 숫자를 total에 다 곱함
    return total # total 값을 리턴

def div() :
    num1 = input('First number : ')
    num2 = input('Second number : ') # 두 수 입력
    if num2 == 0 :
        print "Can't divide by zero" # 뒷 숫자가 0일 때 오류 방지로 출력
    else :
        result = num1 / num2
        return result # 나눗셈 값을 리턴
while True :
    print '=============================='
    print '          Calculator          '
    print '0.Quit 1.Add 2.Sub 3.Mul 4.Div'
    print '=============================='
    work = raw_input('What to do? ') # 연산 종류 입력
    if work == '1' :
        print 'Result : %.2f' % add() # 소수점 두자리 까지 덧셈
    elif work == '2' :
        print 'Result : %.2f' % sub() # 소수점 두자리 까지 뺄셈
    elif work == '3' :
        print 'Result : %.2f' % mul() # 소수점 두자리 까지 곱셈
    elif work == '4' :
        d = div()
        if d == None : # 뒷 숫자가 0일 때 결과값이 None으로 출력됨
            continue # Result가 출력되지 않기 위해 continue 사용으로 루프 통
        else :
            print 'Result :  %.2f' % d # 소수점 두자리 까지 나눗셈
    elif work == '0' :
        print 'Exit program'
        break # 0을 입력시 무한 루프 종료
    else :
        print 'Wrong command'
        continue # 잘못된 입력 시 루프 다시 실행을 위하여 continue 사용
