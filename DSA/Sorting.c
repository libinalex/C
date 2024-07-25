#include <stdio.h>






int main() {
    int n;
    printf("Enter the no. of elements in Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int option;
    printf("\nYou want to perform: \n1. Bubble Sort\n2. Selection Sort\n3. Insertion sort \n4. Counting sort \n5. Quick sort,\n6. Merge sort\n");
    scanf("%d", &option);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    switch (option)
    {
    case 1:
        BubbleSort();
        break;

    case 2:
        SelectionSort();
        break;

    case 3:
        InsertionSort();
        break;

    case 4:
        CountingSort();
        break;

    case 5:
        QuickSort();
        break;

     case 6:
        MergeSort();
        break;

    default:
        printf("You entered a wrong option!\n");
        break;
    }

    return 0;
}