// stops input as soon as user gives # as input

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

// input with scanf with space
scanf("%[^\n]%*c");
