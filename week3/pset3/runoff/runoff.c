#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO voter for i - rank for j - name candidate.name

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {

            preferences[voter][rank] = i;

            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

    // recorrer el array preferences sumando cada voto en la estructura candidates

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int cand = preferences[i][j];

            bool cand_condition = candidates[cand].eliminated;

            if (cand_condition == false)
            {
                candidates[cand].votes += 1;

                break;
            }

        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
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
        swap_container[0].eliminated = candidates[i].eliminated;

        candidates[i].name = candidates[min_value_position].name;
        candidates[i].votes = candidates[min_value_position].votes;
        candidates[i].eliminated = candidates[min_value_position].eliminated;

        candidates[min_value_position].name = swap_container[0].name;
        candidates[min_value_position].votes = swap_container[0].votes;
        candidates[min_value_position].eliminated = swap_container[0].eliminated;

    }

    int win_condition = voter_count / 2;

    if (candidates[candidate_count - 1].votes > win_condition)
    {
        printf("%s\n", candidates[candidate_count - 1].name);

        return true;
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = candidates[0].votes;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            min_votes = candidates[i].votes;

            break;
        }
    }

    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{

    bool tie = false;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            tie = true;
        }
        else
        {
            tie = false;
        }
    }

    return tie;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }

    return;
}
