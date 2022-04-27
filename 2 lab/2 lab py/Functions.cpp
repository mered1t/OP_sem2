import pickle
import os

def createFile(name):
    ans = input("Do you want to rewrite information (Y/N)? ")
    while ans != 'Y' and ans != 'y' and ans!= 'N' and ans!='n':
        ans = input("Wrong, enter 'Y' or 'N': ")

    if ans == 'Y' or 'y':file = open(name, 'wb')
    else: file = open(name, 'ab')

    numb = getNumOfTexts()
    composition = []
    for i in range (numb):
        text = {
            "name": getTextName(),
            "day": getDay(),
            "month": getMonth(),
            "wYear": "",
            "rYear": ""
            }
        wrYear = getYearWrite()
        text["wYear"] = wrYear
        text["rYear"] = getYearRelease(int(wrYear))
        composition.append(text)
        print("Info are now in the file\n")
    pickle.dump(composition, file)
    file.close()


def getNumOfTexts():
    numb = input("Enter the number of compositons: ")
    while not numb.isdigit() or not int(numb) > 0:
        numb = input("Enter correct number(positive): ")
    return int(numb)

def getTextName():
    name = input("Enter name of text: ")
    return name

def getDay():
    day = input("Enter the day from 1 to 31: ")
    while not day.isdigit or int(day) < 1 or int(day) > 31:
        day = input("Enter correct day: ")
    if len(day) != 2:
        day = '0'+ day
    day = day + '.'
    return day

def getMonth():
    month = input("Enter the month from 1 to 12: ")
    while not month.isdigit or int(month) < 1 or int(month) > 12:
        month = input("Enter correct month: ")
    if len(month) != 2:
        month = '0' + month
    month = month + '.'
    return month

def getYearWrite():
    year = input("Enter the year of writing, up to 2022: ")
    while not year.isdigit or int(year) < 1 or int(year) > 2022:
        year = input("Enter correct year: ")
    return int(year)

def getYearRelease(writeYear):
    yearRel = input("Enter the year of release(if not released enter 0): ")
    if yearRel == '0':
        return int(yearRel)
    else:
        while not yearRel.isdigit or int(yearRel) < writeYear or int(yearRel) > 2022 or int(yearRel) < 1:
            yearRel = input("Enter correct year: ")
    return int(yearRel)

def showList(name):
        Rel = ''
        file = open(name, 'rb')
        composition = pickle.load(file)
        for text in composition:
            Rel = str(text["rYear"])
            if str(text["rYear"]) == '0':
                Rel = 'Not Released'
            print('\nName: '+ text["name"] + '\nWritten date: ' + text["day"] + text["month"] + 
            str(text["wYear"]) + '\nRelease year: ' + Rel)
        file.close()

def changeList(inName, outName):
    inFile = open(inName, 'rb')
    outFile = open(outName, 'wb')
    composition = pickle.load(inFile)
    out = []
    for text in composition:
        if text["wYear"] > 2018:
            out.append(text)
    pickle.dump(out, outFile)
    inFile.close()
    outFile.close()


def outOther(name):
    file = open(name, 'rb')
    composition = pickle.load(file)
    for text in composition:
        if text["rYear"] - text["wYear"] > 5:
            print('\nName: '+ text["name"] + '\nWritten date: ' + text["day"] + text["month"] + 
            str(text["wYear"]) + '\nRelease year: ' + str(text["rYear"]+ '\n'))
    file.close()