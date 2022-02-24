from functions import *
firstFile = "intoFile"
secondFile = "outFile"

input_file(firstFile)
print("First file:")

output_file(firstFile)
rewrite_file(firstFile, secondFile)

print("Second file:")
output_file(secondFile)
