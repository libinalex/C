/*
Memory Allocation Functions:
defined under <stdlib.h> library

Malloc( )
Allocates requested number of bytes and returns a pointer pointing to the first byte of the allocated space.
Reserves a block of memory of specified size and returns a pointer of type void.
The return pointer can be assigned to any pointer type.
General format:
    ptr  =  (type *)  malloc (byte_size) ;
Example:
p  =  (int *)  malloc (100 * sizeof (int)) ;  -----> dynamic array of size 100 is created
A memory space equivalent to “100 times the size of an int” bytes is reserved.
The address of the first byte of the allocated memory is assigned to the pointer p of type int.
malloc always allocates a block of contiguous bytes.
The allocation can fail if sufficient contiguous memory space is not available.
If it fails, malloc returns NULL.
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, N;
    float *height;
    float sum = 0, avg;

    printf("Input the number of students. \n");
    scanf("%d", &N);

    height = (float *)malloc(N * sizeof(float));

    printf("Input heights for %d students \n",N);
    for(i=0;i<N;i++)
        scanf("%f",&height[i]);

    for(i=0;i<N;i++)
        sum+=height[i];

    avg=sum/(float) N;

    printf("Average height= %f \n", avg);

    return 0;
}

// Output:
Input the number of students.
5
Input heights for 5 students
23 24 25 26 27
Average height= 25.000000
*/

/*


Calloc( )
Allocates space for an array of elements, initializes them to zero and then returns a pointer to the memory.

Free( )
Frees previously allocated space.
When we no longer need the data stored in a block of memory, we may release the block for future use.
How?
By using the free() function.
General format:
        free (ptr) ;
where ptr is a pointer to a memory block which has been already created using malloc.


Realloc( )
Modifies the size of previously allocated space.
Sometimes we need to alter the size of some previously allocated memory block.
More memory needed or Memory allocated is larger than necessary.
How?
By using the realloc function.
If the original allocation is done by the statement
    ptr  =  malloc (size) ;

then reallocation of space may be done as
    ptr  =  realloc (ptr, newsize) ;

The new memory block may or may not begin at the same place as the old one.
If it does not find space, it will create it in an entirely different region and move the contents of the old block into the new block.
The function guarantees that the old data remains intact.
If it is unable to allocate, it returns NULL and frees the original block.


*/
/*
// Creating dynamic array using malloc
#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr, n;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    printf("Enter %d numbers of the array: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("\nThe array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);    // ----> we can also access value using *(ptr+i)
    }

    return 0;
}
*/

/*
// Creating dynamic array using calloc
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, n;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    printf("Enter %d numbers of the array: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("\nThe array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);
    }

    return 0;
}
*/

// Use of realloc()
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, n;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    printf("Enter %d numbers of the array: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("\nThe array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);
    }

// Till here we have created and printed the dynamic array using calloc

    printf("Enter the size of new array: ");
    scanf("%d", &n);

    ptr = (int *)realloc(ptr, n*sizeof(int));

    printf("Enter %d numbers of the array: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("\nThe new array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);
    }

    free(ptr);      // --->Frees the previously allocated space for ptr.

    return 0;
}