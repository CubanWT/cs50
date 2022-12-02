from cs50 import get_int

while True:
    input = get_int("Height: ")
    if (input > 0):
        break

for i in range(input):
    n = i + 1
    print(" " * (input - n))
    print("#" * (n))