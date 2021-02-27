from cs50 import get_int
import sys

while True:
    height = get_int("Height: ")
    if (height >= 1 and height <= 8):
        break
# prints Mario Block
for i in range(height):
    # adds space
    for j in range(1, height - i):
        print(" ", end="")
    # adds # as per the block
    for k in range(i + 1):
        print("#", end="")

    print('\n', end="")
