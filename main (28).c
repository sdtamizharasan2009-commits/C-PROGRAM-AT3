#include <stdio.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 5000

struct Candidate {
    int number;
    int votes;
};

int main(void) {
    int candidates = 5;

    int votes[20] = {
        1, 2, 3, 1, 2,
        4, 1, 3, 5, 2,
        1, 4, 2, 3, 1,
        5, 2, 0, 6, -1
    };

    int count[MAX_CANDIDATES + 1] = {0};
    int valid = 0, invalid = 0;

    struct Candidate result[MAX_CANDIDATES];

    for (int i = 0; i < 20; i++) {
        if (votes[i] >= 1 && votes[i] <= candidates) {
            count[votes[i]]++;
            valid++;
        } else {
            invalid++;
        }
    }

    for (int i = 0; i < candidates; i++) {
        result[i].number = i + 1;
        result[i].votes = count[i + 1];
    }

    for (int i = 0; i < candidates - 1; i++) {
        for (int j = i + 1; j < candidates; j++) {
            if (result[i].votes < result[j].votes) {
                struct Candidate temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    printf("Total Votes: 20\n");
    printf("Valid Votes: %d\n", valid);
    printf("Invalid Votes: %d\n", invalid);

    printf("\nCandidate Results\n");

    for (int i = 0; i < candidates; i++) {
        printf("Candidate %d: %d votes\n",
               result[i].number, result[i].votes);
    }

    printf("\nWinner: Candidate %d\n", result[0].number);

    if (result[0].votes == result[1].votes)
        printf("Election Result: Tie\n");
    else
        printf("Election Result: No Tie\n");

    return 0;
}