import csv
import sys


print(sys.argv[1])

teams = []

with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        row['rating'] = int(row['rating'])
        teams.append(row)

print(teams)


