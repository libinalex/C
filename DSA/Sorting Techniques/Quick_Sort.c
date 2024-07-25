#include <stdio.h>

void printArr(int arr[], int size)
{
    for (int k = 0; k < size; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;
        
        while(arr[j] > pivot)
            j--;

        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } 
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int piv = Partition(arr, low, high);
        QuickSort(arr, low, piv);
        QuickSort(arr, piv+1, high);
    }
}

int main()
{
    int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray before sorting: ");
    printArr(arr, size);

    QuickSort(arr, 0, size-1);

    printf("Array after sorting: ");
    printArr(arr, size);

    printf("\n");

    return 0;
}