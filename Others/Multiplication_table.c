/*
Print multiplication table of a number entered by the user in proper format.

Example:

Input
Enter the number you want multiplication table of:
6

Output:
Table of 6:
6 X 1 = 6
6 X 2 = 12
.
.
.
6 X 10 = 60

*/

/*  // Without using loops!
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number you want multiplication of:\n");
    scanf("%d", &n);
    printf("Multiplication table of %d is:\n",n);
    printf("%d X 1 = %d\n", n, n*1);
    printf("%d X 2 = %d\n", n, n*2);
    printf("%d X 3 = %d\n", n, n*3);
    printf("%d X 4 = %d\n", n, n*4);
    printf("%d X 5 = %d\n", n, n*5);
    printf("%d X 6 = %d\n", n, n*6);
    printf("%d X 7 = %d\n", n, n*7);
    printf("%d X 8 = %d\n", n, n*8);
    printf("%d X 9 = %d\n", n, n*9);
    printf("%d X 10 = %d\n", n, n*10);

    return 0;
}

*/
         // Using loops
#include <stdio.h>
int main()
{
    int num,n=1;
    printf("Enter the number for which you want the multiplication table: \n");
    scanf("%d",&num);
    do{
        printf("%d X %d = %d\n", num, n, num*n);
        n+=1;
    } while(n<=10);

    return 0;
}