from classes import *
from functions import *

def main():

    amount = random.randint(1, 4)
    r, c = enterRowCol()
    minR, maxR = enterMinMax()
    print()

    matrixes = [None for i in range(2 * amount)]

    createIntMat(matrixes, r, c, minR, maxR, amount)
    createFloatMat(matrixes, r, c ,minR, maxR, amount)

    print("Changed matrices:\n")

    intUpValue(matrixes, amount)
    intDownValue(matrixes, amount)

    min, index = findAverage(matrixes, amount)
    print("The smallest average:", round(min, 2), "has matrix", index, "\n")

if __name__ == '__main__':
    main()
