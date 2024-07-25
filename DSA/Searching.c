#include<stdio.h>

int LinearSearch(int arr[], int size, int key) {
    printf("Performing Linear Search...\n");

    for (int i = 0; i < size; i++)
    {
        if(arr[i] == key) {
            return i + 1;           // +1 to return position instead of index
        }
    }
    
    return 0;
}

int BinarySearch(int arr[], int size, int key) {
    int low, mid, high;
    low = 0;
    high = size - 1;
    printf("Performing Binary Search...\n");

    while (low<=high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return (mid + 1);       // +1 to return position instead of index

        if(arr[mid] > key) 
            high = mid-1;
        
        else 
            low = mid + 1;
    }
    
    return 0;
}


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
    printf("\nYou want to perform: \n1. Linear Search\n2. Binary Search\n");
    scanf("%d", &option);

    int key;
    printf("\nThe given Array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter the key element to search in the Array: ");
    scanf("%d", &key);

    int Search_position;

    switch (option)
    {
    case 1:
        // Linear Search:
        Search_position = LinearSearch(arr, n, key);
        break;
    
    case 2:
        // Binary search:
        // Note that for Binary Search, the array must be sorted.

        Search_position = BinarySearch(arr, n, key);
        break;

    default:
        printf("You entered a wrong option!\n");
        break;
    }

    if (Search_position)
        printf("The key element %d is present at %dth position in the array!", key, Search_position);

    else
        printf("The key element %d is NOT present in the array!", key);

    return 0;
}