import random

class InvalidShapeException(Exception):
    pass

class InvalidOpException(Exception):
    pass

class Matrix:
    def __init__(self, rows, cols):
        if rows <= 0 or cols <= 0 or type(rows) != int or type(cols) != int:
            raise InvalidShapeException()
        
        self.rows = rows
        self.cols = cols

        self.data = [[0] * cols for _ in range(rows)]

    def Randomize(self):
        self.data = [[random.randint(0, 2) for _ in range(self.cols)] for _ in range(self.rows)]

    def Add(self, rhs):
        if not '+' in self.AvailableOp(rhs):
            raise InvalidOpException()
        
        ret = Matrix(self.rows, self.cols)

        for j in range(self.rows):
            for i in range(self.cols):
                ret.data[j][i] = self.data[j][i] + rhs.data[j][i]

        return ret

    def Sub(self, rhs):
        if not '-' in self.AvailableOp(rhs):
            raise InvalidOpException()

        ret = Matrix(self.rows, self.cols)

        for j in range(self.rows):
            for i in range(self.cols):
                ret.data[j][i] = self.data[j][i] - rhs.data[j][i]

        return ret

    def Mul(self, rhs):
        if not '*' in self.AvailableOp(rhs):
            raise InvalidOpException()

        ret = Matrix(self.rows, rhs.cols)

        for i in range(ret.cols):
            for j in range(ret.rows):
                for c in range(self.cols):
                    ret.data[j][i] += self.data[j][c] * rhs.data[c][i]

        return ret

    def AvailableOp(self, rhs):
        ret = []

        if self.rows == rhs.rows and self.cols == rhs.cols:
            ret.extend(['+', '-'])

        if self.cols == rhs.rows:
            ret.append('*')

        return ret

    def Show(self):
        for j in range(self.rows):
            print(' '.join(map(lambda x: '%3d' % x, self.data[j])))

while True:
    try:
        print 'Input Your First Matrix\'s Rows Size :',
        firstRows = input()
        print 'Input Your First Matrix\'s Cols Size :',
        firstCols = input()

        firstMat = Matrix(firstRows, firstCols)
        firstMat.Randomize()
        firstMat.Show()

        print 'Input Your Second Matrix\'s Rows Size :',
        secondRows = input()
        print 'Input Your Second Matrix\'s Cols Size :',
        secondCols = input()

        secondMat = Matrix(secondRows, secondCols)
        secondMat.Randomize()
        secondMat.Show()

        ops = firstMat.AvailableOp(secondMat)

        if len(ops) == 0:
            print '<ERROR> No operation is available'
        else:
            print 'Input ' + ' or '.join(map(lambda x: '\'%s\'' % x, ops)) + ' :',
            op = raw_input()

            if op == '+':
                firstMat.Add(secondMat).Show()
            elif op == '-':
                firstMat.Sub(secondMat).Show()
            elif op == '*':
                firstMat.Mul(secondMat).Show()
            else:
                raise InvalidOpException

    except NameError:
        print '<ERROR> You must input integer'
    except InvalidShapeException:
        print '<ERROR> Invalid matrix shape'
    except InvalidOpException:
        print '<ERROR> Invalid operation'

    print 'Continue? (o or x) :',
    ans = raw_input()

    if ans == 'x':
        break
    elif ans != 'o':
        print '<ERROR> Invalid answer. abort'
        break

    print
