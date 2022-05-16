from cs50 import get_float

quarter = 25
dime = 10
nickel = 5
penny = 1

change_d = 0
counter = 0

# Promp for imput

while change_d <= 0:

    change_d = get_float("Change Owed: ")

# Convert Dollar to Cents

change_c = round(change_d * 100, 2)

# Computing coins

counter = int(change_c / 25)

change_c = change_c - (25 * counter)

while change_c > 0:

    if change_c >= dime:

        change_c = change_c - dime
        counter += 1

    elif change_c >= nickel:

        change_c = change_c - nickel
        counter += 1

    else:

        change_c = change_c - penny
        counter += 1

print(counter)
