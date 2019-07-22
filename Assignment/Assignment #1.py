# -*- coding: euc-kr -*-

work = raw_input("Calculate : ")            # 연산 선택
num1 = input("First Operand : ")            # 첫번째 수
num2 = input("Second Operand : ")           # 두번째 수

if work == '+' or work == 'add' :           # 더하기 선택시
    print 'Result : %.2f' % float(num1 + num2)  #소수점 두자리 실수 표현
elif work == '-' or work == 'sub' :         # 빼기 선택시
    order = raw_input('Choose - f-s or s-f : ')     #연산 순서 지정
    if order == 'f-s' :
        print 'Result : %.2f' % float(num1 - num2)  #소수점 두자리 실수 표현
    elif order == 's-f' :
        print 'Result : &.2f' % float(num2 - num1)  #소수점 두자리 실수 표현
elif work == '*' or work == 'mul' :         #곱하기 선택시
    print 'Result : %.2f' % float(num1 * num2)
elif work == '/' or work == 'div' :         #나누기 선택
    order = raw_input('Choose - f/s or s/f : ')     #연산 순서 지정
    if order == 'f/s' :
        if num2 == 0 :  #0으로 나눌 시
            print '=== Cannot divide by zero ==='
        else :
            print 'Result : %.2f' % float(num1 / num2)  #소수점 두자리 실수 표현
    elif order == 's/f' :
        if num1 == 0 :  #0으로 나눌 시
            print '=== Cannot divide by zero ==='
        else :
            print 'Result : %.2f' % float(num2 / num1)  #소수점 두자리 실수 표현
