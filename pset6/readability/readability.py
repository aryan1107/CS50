from cs50 import get_string
import sys

text = get_string("Text: ")
n = len(text)
letters = 0
words = 1
sentence = 0

# Counter Part
for i in range(n):
    if text[i].isalpha():
        letters += 1
    if text[i] == ' ':
        words += 1
    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentence += 1
    else:
        i += 1

# print(f"{letters} letter(s)")
# print(f"{words} word(s)")
# print(f"{sentence} sentence(s)")

# Average
L = letters / words * 100
S = sentence / words * 100

myfloatL = float(L)
myfloatS = float(S)
# Coleman-Liau Formula
index = 0.0588 * myfloatL - 0.296 * myfloatS - 15.8

grade = round(index)

if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")