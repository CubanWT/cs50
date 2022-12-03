from cs50 import get_int

# Keep prompting user for correct input
while True:
    input = get_int("Height: ")
    if (input > 0 and input < 9):
        break
    print("Height must be between 1 and 8 inclusive!")

# print blocks and spaces
for i in range(input):
    n = i + 1
    print(" " * (input - n), end="")
    print("#" * n)