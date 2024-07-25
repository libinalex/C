/*
Write C program by using array to select, sort  implement and display the output as  ascending order.
Find the minimum element in the array and swap it with the element in the 1st position.
Find the minimum element again in the remaining array[2, n] and swap it with the element at 2nd position, now we have two elements at their correct positions.
We have to do this n-1 times to sort the array.
Test Case 1:

10

12

8

-6

2

4

5

3

7

4

2

O/P

-6

2

2

3

4

4

5

7

8

12
*/

#include <stdio.h>
int main()
{
    int num, arr[50], temp;
    scanf("%d", &num); //input no. of elements in array
    
    for (int i=0; i<num; i++) { 
        scanf("%d", &arr[i]);     //input elements in array
    }
    
    for (int i=0; i<num; i++) {     // loop for sorting
        
        for (int j=i+1; j<num; j++) {
            
            if (arr[i] > arr[j]) {
                temp = arr[i];      // swaping elements
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i=0; i<num; i++)
        printf("%d\n",arr[i]);   // printing the output
    
    return 0;
}