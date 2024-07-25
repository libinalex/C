/*
A record contains the name of the Player, his age, the number of test matches that he has played and the average runs that he has scored in each test match. Define a structure to create the records. Create an array of structures to hold records of 20 such players and write a C program to read these records and arrange them in ascending order by average runs.
*/
/*
#include <stdio.h>
#define SIZE 50
int main()
{
    char str[SIZE];
    fgets(str, sizeof str, stdin);
    while (str[0] != '#')
    {
        printf("%s\n", str);
        fgets(str, sizeof str, stdin);
    }
}
*/

/*
C program to store the player name , runs scored  , wickets taken of a cricket player using structure and sort the players in order of minimum runs to maximum runs
*/

#include <stdio.h>
struct cricketer
{
    int runs, wickets;
    char name[25];
} player[100], t;

void main()
{
    int i, j, n;
    printf("Enter the no of cricket players\n");
    scanf("%d", &n);
    printf("Enter player info as name , wickets taken , runs scored\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d", player[i].name, &player[i].wickets, &player[i].runs);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (player[j].runs > player[j + 1].runs)
            {
                t = player[j];
                player[j] = player[j + 1];
                player[j + 1] = t;
            }
        }
    }

    printf("\nCricketer info in terms of runs scored from lowest to highest\n");
    printf("\nNAME\t\tWICKETS\t\tRUNS_SCORED\n");
    printf("---------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%d\n", player[i].name, player[i].wickets, player[i].runs);
    }
}