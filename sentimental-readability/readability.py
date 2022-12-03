from cs50 import get_string

# Get user input
input = get_string("Text: ")

s = 0
l = 0
w = 0

for c in input.lower:
    if c >= "a" and c <= "z":
        l += 1
    elif c == " ":
        w += 1
    else
        s += 1