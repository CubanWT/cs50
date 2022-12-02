from cs50 import get_int

while (input <= 0):
    input = get_int("Height: ")

for i in range(input):
    print("#" * (i + 1))