// 1. Program to print Numbers from 1 to n
/*
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    // for (int i = 1; i<=n; i++) {       // for loop
    //     printf("%d ",i);
    // }

    // int i=1;                          // while loop
    // while (i<=n){
    //     printf("%d ",i);
    //     i++;
    // }

    // int i=1;                         // do while loop
    // do{
    //     printf("%d ",i);
    //     i++;
    // } while(i<=n);
    
    return 0;
}
*/
// 2. Sum of first n natural numbers.

#include <stdio.h>
int main()
{
    int n,sum;
    printf("Enter the number: ");
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        sum += i;
    }
    printf("The sum of first %d natural numbers is: %d",n,sum);
    return 0;
}

3. Multiplication Table of a number.

4. Factorial of a number.

5. Program to check if a number is Prime or not.
