def inputText(fileName):
    with open(fileName, 'w') as inFile:
        line = input("Enter text\nPress Enter to go on new line\nPress Ctrl + N to stop writing\n\n")
        while line != chr(14):
            inFile.write(line + "\n")
            line = input()
    inFile.close()

def outFile(fileName):
    with open(fileName, 'r') as file:
        lines = file.read().split("\n")
        for i in lines:
            print(i)
    file.close()

def textChange(firstFile, secondFile):
    with open(firstFile, 'r') as inFile:
        with open(secondFile, 'w') as outFile:
            lines = inFile.read().split("\n")
            newLine = lines
            for i in range(len(lines) - 1):
                newLine[i] = lines[i].strip()
                newLine[i] = newLine[i].replace(' ', '  ')
                outFile.write(newLine[i] + " - " + str(newLine[i].count(" ")//2) + "\n")
    inFile.close()
    outFile.close()


