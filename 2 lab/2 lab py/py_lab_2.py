from functions import *

def main():
    createFile("inToTheFile.txt")
    print("\nInfo:")
    showList("inToTheFile.txt")
    changeList("inToTheFile.txt", "outOfTheFile.txt")
    print("\nTexts written for last 4 years(2019-2022):")
    showList("outOfTheFile.txt")
    print("\nTexts released after 5 years from being written:")
    outOther("inToTheFile.txt")

if __name__ == '__main__':
    main()