
#include<stdio.h>

void insert(int *ptr, int size, int element, int index) {
    for (int i = size-1; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[index] = element;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main() {
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

    printf("\n\nEnter the element to insert in the array: ");
    scanf("%d", &element);

    printf("Enter the index where you want to insert the array: ");
    scanf("%d", &index);

    insert(ptr, size, element, index);
    size++;

    printf("\nThe array after insertion of element %d at index %d is: \n", element, index);
    display(arr, size);

    return 0;
}