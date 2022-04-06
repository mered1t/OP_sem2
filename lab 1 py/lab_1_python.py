from functions import *

inputFile = "inFile.txt"
outputFile = "outFile.txt"

inputText(inputFile)
print("Text:\n ")
outFile(inputFile)
textChange(inputFile, outputFile)
print("New file:\n ")
outFile(outputFile)
