import time

data1 = [
    [101, 102, 103, 104, 105, 106, 107, 108, 109, 110],
    [102, 104, 106, 108, 110, 112, 114, 116, 118, 120],
    [103, 106, 109, 112, 115, 118, 121, 124, 127, 130],
    [104, 108, 112, 116, 120, 124, 128, 132, 136, 140],
    [105, 110, 115, 120, 125, 130, 135, 140, 145, 150],
    [106, 112, 118, 124, 130, 136, 142, 148, 154, 160],
    [107, 114, 121, 128, 135, 142, 149, 156, 163, 170],
    [108, 116, 124, 132, 140, 148, 156, 164, 172, 180],
    [109, 118, 127, 136, 145, 154, 163, 172, 181, 190],
    [110, 120, 130, 140, 150, 160, 170, 180, 190, 200]
]
data2 = [
    [101, 102, 103, 104, 105, 106, 107, 108, 109, 110],
    [102, 104, 106, 108, 110, 112, 114, 116, 118, 120],
    [103, 106, 109, 112, 115, 118, 121, 124, 127, 130],
    [104, 108, 112, 116, 120, 124, 128, 132, 136, 140],
    [105, 110, 115, 120, 125, 130, 135, 140, 145, 150],
    [106, 112, 118, 124, 130, 136, 142, 148, 154, 160],
    [107, 114, 121, 128, 135, 142, 149, 156, 163, 170],
    [108, 116, 124, 132, 140, 148, 156, 164, 172, 180],
    [109, 118, 127, 136, 145, 154, 163, 172, 181, 190],
    [110, 120, 130, 140, 150, 160, 170, 180, 190, 200]
]

def add(a, b) :
    result = []
    for i in range(0,10) :
        result.append([])
        for j in range(0,10) :
            result[i].append(a[i][j] + b[i][j])
    return result

def sub(a, b) :
    result = []
    for i in range(0,10) :
        result.append([])
        for j in range(0,10) :
            result[i].append(a[i][j] - b[i][j])
    return result

def show(a) :
    for i in range(0, 10) :
        print(a[i])
        time.sleep(0.1)
