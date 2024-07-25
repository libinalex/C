
#include<stdio.h>

void printArr(int arr[], int size) {
    for (int k = 0; k < size; k++)
        printf("%d ", arr[k]);
    
    printf("\n");
}

void merge(int *a, int *b, int low, int pivot, int high)
{
    int h, i, j, k;
    h = low;
    i = low;
    j = pivot + 1;
    while ((h <= pivot) && (j <= high))  
    {
        if (a[h] <= a[j]) 
            b[i++] = a[h++];
            
        else 
            b[i++] = a[j++];  
    }

    if (h > pivot)  {
        for (k = j; k <= high; k++)
            b[i++] = a[k];
    }

    else {
        for (k = h; k <= pivot; k++)
            b[i++] = a[k];    
    }

    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void mergesort(int *a, int *b, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = (low + high) / 2;
        mergesort(a, b, low, pivot);
        mergesort(a, b, pivot + 1, high);
        merge(a, b, low, pivot, high);
    }
}

int main()
{
    int a[] = {12, 10, 43, 23, 78, 45, 56, 98, 41, 90, 24};
    int num = sizeof(a) / sizeof(int);
    int b[num];

    printf("\nArray before sorting: ");
    printArr(a, num);
    mergesort(a, b, 0, num - 1);

    printf("Array after sorting: ");
    printArr(a, num);

    return 0;
}
