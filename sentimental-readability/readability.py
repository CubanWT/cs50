from cs50 import get_string

# Get user input
input = get_string("Text: ")

sentences = 0
letters = 0
words = 1

# Parse string for letters, words, and sentences
for c in input.lower():
    if c >= "a" and c <= "z":
        letters += 1
    elif c == " ":
        words += 1
    elif c == "." or c == "?" or c == "!":
        sentences += 1

# Calculate readability index
l = letters / words * 100
s = sentences / words * 100
index = round(0.0588 * l - 0.296 * s - 15.8)

#print index
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")