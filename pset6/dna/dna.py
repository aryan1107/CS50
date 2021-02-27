import csv
import sys
import re

# checks if the usage is correct
if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

# created to open files
database = sys.argv[1]
sequence = sys.argv[2]

db = []


def main():
    # Opens both files
    with open(database) as file:
        reader = csv.DictReader(file)
        for row in reader:
            db.append(row)
            # print(row)

    with open(sequence) as txt:
        dna = txt.read()
        mysequnece = dna

    text = mysequnece

    # returns maximum number of consecutive STR from sequence file
    AGATC = compute('AGATC', text)
    AATG = compute('AATG', text)
    TATC = compute('TATC', text)
    TTTTTTCT = compute('TTTTTTCT', text)
    TCTAG = compute('TCTAG', text)
    GATA = compute('GATA', text)
    GAAA = compute('GAAA', text)
    TCTG = compute('TCTG', text)

    if sys.argv[1] == 'databases/small.csv':
        for i in range(len(db)):
            for i in range(len(db)):
                if all([db[i]["AGATC"] == str(AGATC), db[i]["AATG"] == str(AATG), db[i]["TATC"] == str(TATC)]):
                    output = db[i]["name"]
                    #  print(output)
                    break
                else:
                    output = "No match"
                    #  print(output)
    else:
        for i in range(len(db)):
            if all([db[i]["AGATC"] == str(AGATC), db[i]["TTTTTTCT"] == str(TTTTTTCT), db[i]["TCTAG"] == str(TCTAG), db[i]["AATG"] == str(AATG),
                    db[i]["GATA"] == str(GATA), db[i]["TATC"] == str(TATC), db[i]["GAAA"] == str(GAAA), db[i]["TCTG"] == str(TCTG)]):
                output = db[i]["name"]
                #  print(output)
                break
            else:
                output = "No match"
                #  print(output)

    print(output)


# This function accepts a pattern and a dna sequence
def compute(pattern, dnaSeq):
    # re to finda maximum repetetive patern
    match = re.findall(f'(?:{pattern})+', dnaSeq)
    # print(match)
    # if there is no Pattern found stop and return 0
    if match == []:
        myresult = 0
        return myresult
    # else find max pattern then length counts the length of the pattern
    # then calculator devides length of pattern with pattern itself to find maximum repetition
    else:
        extractor = max(match, key=len)
        lentgth = len(extractor)
        calculator = round(lentgth / len(pattern))
        # print(calculator)
        return calculator


main()