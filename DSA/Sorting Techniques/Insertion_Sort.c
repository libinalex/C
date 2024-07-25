#include<stdio.h>

void printArr(int arr[], int size) {
    for (int k = 0; k < size; k++)
        {
            printf("%d ", arr[k]);
        }
    printf("\n");
}


void InsertionSort(int arr[], int size) {
    printf("Performing Insertion sort...\n");
    for (int i = 1; i < size; i++)      // Unsorted array
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;

        printArr(arr, size);
    }
}

int main()
{
    int arr[] = {8, 5, 10, 3, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray before sort: ");
    printArr(arr, size);

    InsertionSort(arr, size);

    printf("Array after sorting: ");
    printArr(arr, size);

    printf("\n");

    return 0;
}