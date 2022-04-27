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

    for (int i = 0; i < candidate_count; i++)
    {

        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;

            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int min_value;
    int current_value_position;
    int min_value_position;
    candidate swap_container[1];

    for (int i = 0; i < candidate_count; i++)
    {

        min_value = candidates[i].votes;
        min_value_position = i;

        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[j].votes < min_value)
            {
                min_value = candidates[j].votes;
                min_value_position = j;

            }
        }

        swap_container[0].name = candidates[i].name;
        swap_container[0].votes = candidates[i].votes;

        candidates[i].name = candidates[min_value_position].name;
        candidates[i].votes = candidates[min_value_position].votes;

        candidates[min_value_position].name = swap_container[0].name;
        candidates[min_value_position].votes = swap_container[0].votes;

    }

    printf("%s\n", candidates[candidate_count - 1].name);

    for (int i = candidate_count - 2 ; i >= 0; i--)
    {
        if (candidates[i].votes == candidates[candidate_count - 1].votes)
        {
            printf("%s\n", candidates[i].name);
        }

    }

    return;
}

