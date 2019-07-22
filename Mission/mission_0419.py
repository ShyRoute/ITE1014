# -*- coding: euc-kr -*-
import time

def percent(A, B) :
    result = float(A / B * 100)
    print('%0.3f%% 입니다.' % result)

datalist = []
total = 0.0
count = 0.0
N = int(raw_input('학생 수를 입력하고, 성적을 입력하세요. : '))
for i in range(N) :
    datalist.append(int(raw_input()))
    total += datalist[i]
    
avg = total / N

for i in range(N) :
    if datalist[i] > avg :
        count += 1

print('평균을 넘는 학생의 비율은..')
time.sleep(1)
print 3
time.sleep(1)
print 2
time.sleep(1)
print 1
time.sleep(1)
percent(count, N)



    

            

