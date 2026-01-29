import matplotlib.pyplot as plt
import csv

def main():
    matchX , matchY = [], []

    with open("matchingTime.csv", "r") as f:
        reader = csv.reader(f)
        for row in reader:
            xi , yi = map(float, row)
            matchX.append(xi)
            matchY.append(yi)
    plt.figure()
    plt.plot(matchX, matchY)
    plt.title("Matcher running time vs N")
    plt.xlabel("n")
    plt.ylabel("Running time (seconds)")

    checkX , checkY = [] ,[]
    with open("checkTime.csv", "r") as f:
        reader = csv.reader(f)
        for row in reader:
            xi , yi = map(float, row)
            checkX.append(xi)
            checkY.append(yi)
    plt.figure()
    plt.plot(checkX, checkY)
    plt.title("Verifier running time vs N")
    plt.xlabel("n")
    plt.ylabel("Running time (seconds)")


    plt.show()
if __name__ == "__main__":
    main()