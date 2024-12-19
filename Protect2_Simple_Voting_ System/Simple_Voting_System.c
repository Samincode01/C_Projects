#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5


struct Candidate {
    char name[50];
    int votes;
};

void displayCandidates(struct Candidate candidates[], int numCandidates);
void vote(struct Candidate candidates[], int numCandidates);
void displayResults(struct Candidate candidates[], int numCandidates);

int main() 
{
    struct Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"David", 0},
        {"Eve", 0}
    };
    int numCandidates = 5;
    int choice;

    while (1) {
        printf("\nVoting System\n");
        printf("1. Vote\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vote(candidates, numCandidates);
                break;
            case 2:
                displayResults(candidates, numCandidates);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display all candidates
void displayCandidates(struct Candidate candidates[], int numCandidates) {
    printf("\nCandidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// handle the voting process
void vote(struct Candidate candidates[], int numCandidates) {
    int choice;
    displayCandidates(candidates, numCandidates);

    printf("\nEnter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > numCandidates) {
        printf("Invalid candidate number.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Vote recorded for %s!\n", candidates[choice - 1].name);
    }
}

// display the voting results
void displayResults(struct Candidate candidates[], int numCandidates) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}
