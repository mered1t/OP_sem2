def input_file(nameOfFile):
    with open(nameOfFile, 'w') as inFile:
        line = input("Enter the text\nTo go on a new line press Enter\nPress Ctrl + N to stop writing\n\n")
        while line != chr(14):
            inFile.write(line + "\n")
            line = input()


def output_file(nameOfFile):
    with open(nameOfFile, 'r') as file:
        lines = file.read().split("\n")
        for i in lines:
            print(i)


def rewrite_file(firstFile, secondFile):
    with open(firstFile, 'r') as inFile:
        with open(secondFile, 'w') as outFile:
            line = inFile.read().split("\n")
            newLine = line
            for i in range(len(line) - 1):
                newLine[i] = line[i].strip()
                newLine[i] = newLine[i].replace('  ', '')
                outFile.write(newLine[i] + " - " + str(newLine[i].count(' ')) + "\n")