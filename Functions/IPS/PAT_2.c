/*
write a program in C such that it calculates the sum and average of elements of an array using pointers.

Input 

Please Enter the Array size = 9

Enter the Array Items = 21 31 41 51 61 71 81 91 121

Output

The Sum of Array Items     = 569

The Average of Array Items = 63.22
*/

#include<stdio.h>

int main()
{
    int arr[50], num, *ptr;
    scanf("%d", &num);          // input no. of elements in array
    for (int i=0; i<num; i++){
        scanf("%d",&arr[i]);
    }
    ptr=arr;        //assigning pointer
    int sum=0;
    float avg;
    for (int i=0; i<num; i++){  // loop for calculating the sum 
        sum += *(ptr+i);        // using pointer
    }
    avg=(float)sum/num;         // calculating the average 
    printf("%d\n", sum);
    printf("%.2f", avg);
    return 0;


}