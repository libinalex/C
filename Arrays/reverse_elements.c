/*
Write a C Program to Reverse a list of  Array without Using another list of Array
Note : The logic of reversing an array without using another array is to swap elements of the first half with elements of the second half i.e. the first element with the last element, then the second element with the second last element, and so on, till the middle element of the array.

Sample Input: 12345

Sample Output :54321

-----

Sample Input 2:15 8 27 28 10 5 30

Sample Output 2:30 5 10 28 27 8 15
*/

#include <stdio.h>
 
int main() {
    int array[100], n, c, t, last;

    printf("Enter the no. of elements in the array:\n");
    scanf("%d", &n);
    last = n - 1;
 
    printf("Enter the elements of array: \n");
   for (c = 0; c < n; c++) {
    scanf("%d", &array[c]);
   }
 
   for (c = 0; c < n/2; c++) {
    t          = array[c];
    array[c]   = array[last];
    array[last] = t;
 
    last--;
  }
 
   printf("Reversed array elements are:\n");
 
   for (c = 0; c < n; c++) {
        printf("%d ", array[c]);
  }
 
   return 0;
}

