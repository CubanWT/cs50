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
    //iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //compare voter input to candidate name for match
        if (strcmp(name, candidates[i].name) == 0)
        {
            //save index of candidate in respective voter's ranking.
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //iterate through voters
    for (int i = 0; i < voter_count - 1; i++)
    {
        //iterate through rankings
        for (int j = 0; j < candidate_count; j++)
        {
            //check if candidate in current ranking is eliminated
            if (!candidates[preferences[i][j]].eliminated)
            {
                //add vote to candidate
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //check if has over 50% of votes
        if (candidates[i].votes > voter_count / 2)
        {
            //prints winner
            printf("%s", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    //keep track of lowest candidate
    int lowest = 0;

    //iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //check if candidate is eliminated
        if (!candidates[i].eliminated)
        {
            //check if candidate vote total is lower than known lowest
            if (candidates[i].votes < candidates[lowest].votes)
                lowest = i;
        }
    }

    return candidates[lowest].votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    //iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //checks if current candidate vote count is greater than min
        if(candidates[i].votes > min)
            return false;
    }

    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    //iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
            candidates[i].eliminated = true;
    }
    return;
}