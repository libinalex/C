/*
We have seen that an integer value can be added to or subtracted from a pointer variable.
int    *p1,  *p2 ;
int    i,  j;
:
p1  =  p1  +  1 ;
p2  =  p1  +  j ;
p2++ ;
p2  =  p2  –  (i + j) ;
In reality, it is not the integer value which is added/subtracted, but rather the scale factor times the value.



p = x;    and    p = &x[0];  are equivalent.
We can access successive values of x by using p++ or p- - to move from one element to another.

p    =   &x[0]   =   2500
p+1  =   &x[1]   =   2504
p+2  =   &x[2]   =   2508
p+3  =   &x[3]   =   2512
p+4  =   &x[4]   =   2516


*(p+i) gives the value of x[i]
*/

// 1. Using pointers to swap two numbers 
/*
#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int m = 10, n = 20;
    printf("Before Swapping:\n");
    printf("m = %d\n", m);
    printf("n = %d\n\n", n);

    swap(&m, &n); // passing address of m and n to the swap function
    printf("After Swapping:\n");
    printf("m = %d\n", m);
    printf("n = %d", n);
    return 0;
}

// pointer 'a' and 'b' holds and points to the address of 'm' and 'n'

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
*/

/*
// 2. Function to find average
#include <stdio.h>
float avg(int array[], int size);

int main()
{
    int arr[100], k, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }
    printf("Average is % f", avg(arr, n));
}

float avg(int array[], int size)
{
    int *p, i, sum = 0;
    p = array;
    for (i = 0; i < size; i++)
        sum = sum + *(p + i);
    return ((float)sum / size);
}
*/

#include<stdio.h>

double average(int *arr, int size) {
    double avg;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + *(arr + i);
    }
    avg = (double) sum / size;
    return avg;
}

int main() {
    int arr[] = {1, 2,3,4,5,6};
    int size = sizeof(arr) / sizeof(int);
    double avg = average(arr, size);
    printf("The average of numbers in teh array is %f", avg);
}