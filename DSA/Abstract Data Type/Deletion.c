#include<stdio.h>

void delete(int *ptr, int size, int index) {
    for (int i = index; i < size-1; i++)
    {
        ptr[i] = ptr[i + 1];
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int size, capacity = 50, arr[capacity], element, index, *ptr;
    printf("Enter the number of elements in array: ");
    scanf("%d", &size);

    printf("Enter the Array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    printf("\nOriginal Array: \n");
    display(arr, size);

    printf("\n\nEnter the index from which you want to delete the element from Array: ");
    scanf("%d", &index);

    delete (ptr, size, index);
    size--;

    printf("\nThe array after deletion of element from index %d is: \n", index);
    display(arr, size);

    return 0;
}