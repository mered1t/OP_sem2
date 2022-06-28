from abc import ABC, abstractmethod
import random


class TMatrix(ABC):

    def __init__(self, rows, cols, minRange, maxRange):
        self._rows = rows
        self._cols = cols
        self.M = self.generate_matrix(minRange, maxRange)

    @abstractmethod
    def generate_matrix(self, minRange, maxRange):
        pass

    def get_rows(self):
        return self._rows

    def get_cols(self):
        return self._cols

    def display(self):
        for i in range(self._rows):
            for j in range(self._cols):
                self.M[i][j] = round(self.M[i][j], 2)
        for i in self.M:
            print(*i)
        print()

    def increment(self, num):
        for i in range(self._rows):
            for j in range(self._cols):
                self.M[i][j] = self.M[i][j] + num

    def decrement(self, num):
        for i in range(self._rows):
            for j in range(self._cols):
                self.M[i][j] = self.M[i][j] - num

    def avg(self):
        sum = 0
        average = 0
        for i in range(self._rows):
            for j in range(self._cols):
                sum = sum + self.M[i][j]
        average = sum / (self._rows * self._cols)
        return average


class intMatrix(TMatrix):
    def __init__(self, rows, cols, minRange, maxRange):
        super().__init__(rows, cols, minRange, maxRange)

    def generate_matrix(self, minRange, maxRange):
        return [[random.randint(minRange, maxRange) for i in range(self._cols)] for j in range(self._rows)]


class floatMatrix(TMatrix):
    def __init__(self, rows, cols, minRange, maxRange):
        super().__init__(rows, cols, minRange, maxRange)

    def generate_matrix(self, minRange, maxRange):
        return [[random.uniform(minRange, maxRange) for i in range(self._cols)] for j in range(self._rows)]
