from cs50 import get_int

# Prompt user for imput

Height = 0

while Height < 1 or Height > 8:

    Height = get_int("Please, enter the number of bricks (between 1 and 8):")

# Building the pyramid

for i in range(Height):

    # Prints left blank space

    for j in range(Height - (i + 1)):

        print(" ", end="")

    # Prints left blocks

    for k in range(i + 1):

        print("#", end="")

    print()

