/* 
Print the numbers in the following format upto a given number entered by the keyboard:
2 4 6 8 …………………….. up to that given number 

#include<stdio.h>

int main()
{
    int num,i;
    printf("Enter the number:");
    scanf("%d",&num);
    for(i=2 ; i<=num ; i+=1)
    {
        if (i%2==0)
            printf("%d ",i);
        else if ( i==num )
            printf("%d ",i);
    }
    return 0;
}
*/

/* Write a C programe to print a pattern like a christmas tree
