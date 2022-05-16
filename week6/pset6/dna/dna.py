import csv
import sys

STR1 = ['AGATC', 'AATG', 'TATC']

STR2 = ['AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']


def main():

    # Verificar que se haya proporcionado el número de argumentos correctos:

    if len(sys.argv) != 3:

        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Cargar el archivo csv en memoria

    database = []

    with open(sys.argv[1], "r") as file:

        reader = csv.DictReader(file)

        if sys.argv[1] == 'databases/small.csv':

            for row in reader:

                row['AGATC'] = int(row['AGATC'])

                row['AATG'] = int(row['AATG'])

                row['TATC'] = int(row['TATC'])

                database.append(row)

        elif sys.argv[1] == 'databases/large.csv':

            for row in reader:

                row['AGATC'] = int(row['AGATC'])

                row['TTTTTTCT'] = int(row['TTTTTTCT'])

                row['AATG'] = int(row['AATG'])

                row['TCTAG'] = int(row['TCTAG'])

                row['GATA'] = int(row['GATA'])

                row['TATC'] = int(row['TATC'])

                row['GAAA'] = int(row['GAAA'])

                row['TCTG'] = int(row['TCTG'])

                database.append(row)

        else:

            sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Cargar el archivo txt en memoria

    with open(sys.argv[2], "r") as file:

        reader = file.read()

        sequence = reader

    # Verificar numero de STR:

    if sys.argv[1] == 'databases/small.csv':

        sample = find_dna_sequences_small(sequence)

        name = compare_sample_small(sample, database)

    if sys.argv[1] == 'databases/large.csv':

        sample = find_dna_sequences_large(sequence)

        name = compare_sample_large(sample, database)

    # Imprimir resultados

    print(name)


def find_dna_sequences_small(sequence):

    sample = {'AGATC': 0, 'AATG': 0, 'TATC': 0}

    for i in range(len(sequence) - 4):

        j = i + 4

        if sequence[i:j] in STR1:

            sample[sequence[i:j]] += 1

    for i in range(len(sequence) - 5):

        k = i + 5

        if sequence[i:k] in STR1:

            sample[sequence[i:k]] += 1

    return sample


def find_dna_sequences_large(sequence):

    sample = {'AGATC': 0, 'TTTTTTCT': 0, 'AATG': 0, 'TCTAG': 0, 'GATA': 0, 'TATC': 0, 'GAAA': 0, 'TCTG': 0}

    for i in range(len(sequence) - 4):

        j = i + 4

        if sequence[i:j] in STR2 and sequence[(i + 4):(j + 4)] == sequence[i:j]:

            sample[sequence[i:j]] += 1

        else:

            if sequence[i:j] in STR2 and sequence[(i - 4):(j - 4)] == sequence[i:j]:

                sample[sequence[i:j]] += 1

    for i in range(len(sequence) - 5):

        k = i + 5

        if sequence[i:k] in STR2 and sequence[(i + 5):(k + 5)] == sequence[i:k]:

            sample[sequence[i:k]] += 1

        else:

            if sequence[i:k] in STR2 and sequence[(i - 5):(k - 5)] == sequence[i:k]:

                sample[sequence[i:k]] += 1

    for i in range(len(sequence) - 8):

        l = i + 8

        if sequence[i:l] in STR2 and sequence[(i + 8):(l + 8)] == sequence[i:l]:

            sample[sequence[i:l]] += 1

        else:

            if sequence[i:l] in STR2 and sequence[(i - 8):(l - 8)] == sequence[i:l]:

                sample[sequence[i:l]] += 1

    return sample


def compare_sample_small(sample, database):

    for i in range(len(database)):

        if database[i]['AGATC'] == sample['AGATC'] and database[i]['AATG'] == sample['AATG'] and database[i]['TATC'] == sample['TATC']:

            name = database[i]['name']

            return name

    name = 'No match'

    return name


def compare_sample_large(sample, database):

    for i in range(len(database)):

        if database[i]['AGATC'] == sample['AGATC'] and database[i]['TTTTTTCT'] == sample['TTTTTTCT'] and database[i]['AATG'] == sample['AATG'] and database[i]['TCTAG'] == sample['TCTAG'] and database[i]['GATA'] == sample['GATA'] and database[i]['TATC'] == sample['TATC'] and database[i]['GAAA'] == sample['GAAA'] and database[i]['TCTG'] == sample['TCTG']:

            name = database[i]['name']

            return name

    name = 'No match'

    return name


if __name__ == "__main__":

    main()