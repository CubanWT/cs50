from cs50 import get_int

while True:
    input = get_int("Height: ")
    if (input > 0 & input < 9):
        break
    print("Height must be between 1 and 8 inclusive!")

for i in range(input):
    n = i + 1
    print(" " * (input - n), end="")
    print("#" * n)