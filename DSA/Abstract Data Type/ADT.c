
// Abstract Data Type - Details of operations are abstracted (hidden)

/*
#include<stdio.h>

int maximum( int arr[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int minimum(int arr[], int n)
{
    int min = 999999;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int arr[5] = {3, 10, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = maximum(arr, n);
    int min = minimum(arr, n);
    printf("The maximum element in the given array is: %d\n",max );
    printf("The minimum element in the given array is: %d\n",min );
    return 0;
}
*/


// Array as an Abstract data type in Data Structure

#include<stdio.h>
#include<stdlib.h>

struct MyArray
{
    int total_size;        //  ---->    memory to be reserved
    int used_size;         //  ---->    memory to be used
    int *ptr;
};

void createArray(struct MyArray *a, int tSize, int uSize) {
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int*)malloc(tSize*sizeof(int));

        // alternate way to write this:

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize*sizeof(int));
    // The memory created on stack gets destroyed after function terminates, that's why we are creating memory in heap using dynamic memory allocation.
}

void setValue(struct MyArray *a) {
    printf("Enter the marks of %d Students:\n", a->used_size);
    for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d", &(a->ptr[i]));
    }
}

void showValue(struct MyArray *a) {

    for (int i = 0; i < a->used_size; i++)
    {
        printf("The marks scored by student %d are: %d\n", i + 1, (a->ptr[i])); // can also be accessed by: (a->ptr)[i] or *(a->ptr+i)
    }

}

int main() {
    struct MyArray marks;
    createArray(&marks, 10, 5);
    setValue(&marks);
    showValue(&marks);
    return 0;
}


/*
// Operations on Arrays:
Traversal (Visiting every element of the array)
Insertion (Insert an element at a given index and shift the following elements to right)
Deletion (Delete an element at a given index and shift the following elements to left)
Searching (Searching for an element in the array: Linear and Binary search)
Sorting (Sort in ascending or descending order: Selection, Insertion, Bubble, Merge, Quick)
*/