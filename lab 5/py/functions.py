from classes import *

def createIntMat(matrixes, r, c ,minR, maxR, am):
    print("Int matrixes:\n")
    for i in range(am):
        matrixes[i] = intMatrix(r, c, minR, maxR)
        print(i + 1, ")")
        matrixes[i].display()

def createFloatMat(matrixes, r, c ,minR, maxR, am):
    print("Float matrixes:\n")
    for i in range(am, 2 * am):
        matrixes[i] = floatMatrix(r, c, minR, maxR)
        print(i + 1, ")")
        matrixes[i].display()

def intUpValue(matrixes, am):
    print("Int matrices:\n")
    for i in range(am):
        matrixes[i].increment(9)
        print(i + 1, ")")
        matrixes[i].display()

def intDownValue(matrixes, am):
    print("Float matrices:\n")
    for i in range(am, 2 * am):
        matrixes[i].decrement(5)
        print(i + 1, ")")
        matrixes[i].display()

def findAverage(matrixes, am):
   minAv = matrixes[0].avg()
   index = 1

   for i in range(2 * am):
       if matrixes[i].avg() < minAv:
           minAv = matrixes[i].avg()
           index = i
   print("Matrix with the min av #", index + 1)
   matrixes[index].display()
   return (minAv, index + 1);

def enterMinMax():
    minR = int(input("\nEnter the min number for rand: "))
    maxR = int(input("Enter the max number for rand: "))
    while(maxR < minR or maxR == minR):
        maxR = int(input("Enter correct number: "))
    return (minR, maxR);

def enterRowCol():
    row = int(input("Enter number of rows: "))
    while(row < 0):
        row = int(input("Enter correct number: "))

    col = int(input("Enter number of cols: "))
    while(col < 0):
        row = int(input("Enter correct number: "))

    return (row, col);