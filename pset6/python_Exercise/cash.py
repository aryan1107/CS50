from cs50 import get_float
import sys

while True:
    dollars = get_float("Change owed: ")
    if(dollars > 0):
        break

cents = round(dollars * 100)

counter = 0

# according to greedy algorithm counter if change is 25 or more
while cents >= 25:
    cents = cents - 25
    counter += 1
# according to greedy algorithm counter if change is 10 or more
while cents >= 10:
    cents = cents - 10
    counter += 1
# according to greedy algorithm counter if change is 5 or more
while cents >= 5:
    cents = cents - 5
    counter += 1
# according to greedy algorithm counter if change is 1 or more
while cents >= 1:
    cents = cents - 1
    counter += 1
# Prints total counter or lowest change owned
print(counter)