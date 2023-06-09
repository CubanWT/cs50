import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorrect usage! use dna.py {CSV data} {DNA text file}")

    # TODO: Read database file into a variable
    db = []

    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)

        for row in reader:
            db.append(row)

        for sub in db:
            for key in sub:
                if key != 'name':
                    sub[key] = int(sub[key])

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        sqc = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    STRs = list(db[0].keys())
    STRs.remove('name')
    STRs = dict.fromkeys(STRs, 0)

    for keys in STRs.keys():
        STRs[keys] = longest_match(sqc, keys)

    # TODO: Check database for matching profiles
    matchFound = False

    # Iterate through every person in database
    for person in db:

        # Keep track of matches
        matches = 0

        # Iterate through every STR in STR dict
        for key in STRs.keys():
            if STRs[key] == person[key]:
                matches += 1

        # If all STRs match, then print person's name
        if matches == len(STRs):
            matchFound = True
            print(person['name'])

    # If no matches were found then print no match
    if matchFound == False:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
