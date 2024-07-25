#include <stdio.h>

void printArr(int arr[], int size)
{
    for (int k = 0; k < size; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        printArr(arr, size);
    }
}

int main()
{
    int arr[] = {7, 4, 10, 8, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray before sorting: ");
    printArr(arr, size);

    SelectionSort(arr, size);

    printf("Array after sorting: ");
    printArr(arr, size);

    printf("\n");

    return 0;
}