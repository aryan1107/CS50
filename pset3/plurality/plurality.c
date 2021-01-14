// Aryan Chaurasia
// Pset 3 Plurality CS50 | 2021
// Jan 5 2021
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        // compares if two stings are same and if it is
        // then adds one vote to the candidate
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            // printf("Added Votes\n");
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    typedef struct
    {
        string name;
        int votes;
    }
    tempcandidate;
    tempcandidate tempcandidates[MAX];

    // prints winnwer by searching for largest votes amongst candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < candidates[i + 1].votes)
        {
            // printf("running\n");
            tempcandidates[i].votes = candidates[i].votes;
            tempcandidates[i].name = candidates[i].name;

            candidates[i].votes = candidates[i + 1].votes;
            candidates[i].name = candidates[i + 1].name;

            candidates[i + 1].votes = tempcandidates[i].votes;
            candidates[i + 1].name = tempcandidates[i].name;

            printf("%s\n", candidates[i].name);
        }
        else if (candidates[i].votes == candidates[i + 1].votes)
        {
            printf("%s\n", candidates[i].name);
            printf("%s\n", candidates[i + 1].name);

        }
        else if (candidates[i].votes > candidates[i + 1].votes)
        {
            printf("%s\n", candidates[i].name);
            return;
        }

    }
    return;
}

