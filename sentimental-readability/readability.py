from cs50 import get_string

# Get user input
input = get_string("Text: ")

s = 0
l = 0
w = 0

for c in input.lower().lstrip():
    if c >= "a" and c <= "z":
        l += 1
    elif c == " ":
        w += 1
    elif c == "." or "?" or "!":
        s += 1

# Calculate readability index and print
l = l / w * 100
s = s / w * 100
index = int(0.0588 * l - 0.296 * s - 15.8)


if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")