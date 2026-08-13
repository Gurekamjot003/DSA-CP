def count_first_choices(ballots):
    # Complete the function
    freq = {}
    for row in ballots:
        if(len(row) == 0):
            continue
        if row[0] in freq:
            freq[row[0]]+= 1
        else:
            freq[row[0]] = 1

    return freq
            




def main():
    ballots = [
        ["A", "B"],
        ["A", "B"],
        ["B", "A"],
        ["C", "A"],
        ["C", "B"]
    ]

    result = count_first_choices(ballots)
    print("First choice counts:")
    for candidate, count in result.items():
        print(f"{candidate}: {count}")


if __name__ == "__main__":
    main()
