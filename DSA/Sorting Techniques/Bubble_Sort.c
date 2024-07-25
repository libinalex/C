#include<stdio.h>

void BubbleSort(int arr[], int size) {
    printf("\nPerforming Bubble sort...\n");
    for (int i = 0; i < size - 1; i++) // size-1 passes
    {
        for (int j = 0; j < size - 1; j++) // size-1 comparisons in one pass
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

            for (int k = 0; k < size; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\nArray after sort: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void ModifiedBubbleSort(int arr[], int size) {
    printf("\nPerforming Modified Bubble sort...\n");
    for (int i = 0; i < size - 1; i++) // size-1 passes
    {
        for (int j = 0; j < size - 1 - i; j++) // size-1-i comparisons in one pass to not perform unnecessary comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

            for (int k = 0; k < size; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("Array after sort: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void OptimisedBubbleSort(int arr[], int size) {
    printf("\nPerforming Modified Bubble sort...\n");
    int flag;
    for (int i = 0; i < size - 1; i++) // size-1 passes
    {
        for (int j = 0; j < size - 1 - i; j++) // size-1-i comparisons in one pass to not perform unnecessary comparisons
        {
            flag = 0;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }

            for (int k = 0; k < size; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        printf("\n");

        if(flag == 0)    // exit loop if no swapping took place, i.e. all numbers are already in sorted order
            break;
    }
    printf("Array after sort: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {1, 3, 4, 5, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sort: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // BubbleSort(arr, size);

    // After every pass the greatest element comest to its correct position, so need to compare it again.
    // ModifiedBubbleSort(arr, size);

    // If array is already sorted mostly:
    OptimisedBubbleSort(arr, size);
    return 0;
}

// 