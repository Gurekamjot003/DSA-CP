def calculate_rcv_winner(ballots):
    # Write your code here
    indices = {}
    freq = {}
    
    for i in range(len(ballots)):
        row = ballots[i]
        if len(row) == 0:
            continue
        if row[0] in indices:
            indices[row[0]].append(i)
            freq[row[0]] += 1
        else:
            indices[row[0]] = [i]
            freq[row[0]] = 1

    total = len(ballots)
    majority = total//2 + 1 
    remaining = total
    while remaining>0:
        min_votes = 1e9
        for candidate, votes in freq.items():
            if votes<min_votes:
                min_votes = votes
            if votes>=majority:
                return candidate
        
        new_freq = {}

        for candidate, votes in freq.items():
            if(votes == min_votes):
                for index in indices[candidate]:
                    remaining -= 1
                    for i in range(1, len(ballots[index])):
                        vote = ballots[index][i]
                        if vote in new_freq:
                            new_freq[vote] += 1
                        else:
                            new_freq[vote] = 1
            else:
                if candidate in new_freq:
                    new_freq[candidate] += votes
                else:
                    new_freq[candidate] = votes

        freq = new_freq


def main():
    ballots = [
            ["A", "B"],
            ["A", "B"],
            ["B", "A"],
            ["C", "A"],
            ["C", "B"]
        ]
    winner = calculate_rcv_winner(ballots)

    if winner is not None:
        print("\n🎉 The winner is:", winner)
    else:
        print("\nNo winner could be determined.")

if __name__ == "__main__":
    main()