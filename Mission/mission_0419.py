# -*- coding: euc-kr -*-
import time

def percent(A, B) :
    result = float(A / B * 100)
    print('%0.3f%% �Դϴ�.' % result)

datalist = []
total = 0.0
count = 0.0
N = int(raw_input('�л� ���� �Է��ϰ�, ������ �Է��ϼ���. : '))
for i in range(N) :
    datalist.append(int(raw_input()))
    total += datalist[i]
    
avg = total / N

for i in range(N) :
    if datalist[i] > avg :
        count += 1

print('����� �Ѵ� �л��� ������..')
time.sleep(1)
print 3
time.sleep(1)
print 2
time.sleep(1)
print 1
time.sleep(1)
percent(count, N)



    

            

