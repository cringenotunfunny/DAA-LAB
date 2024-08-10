#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int arr[], int n){
    for (int i = 0; i <= n - 1; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            j--;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double measureTimeComplexity(int arr[], int n)
{
    clock_t start, end;
    double time_taken;

    start = clock();
    insertionSort(arr, n);
    end = clock();
    
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time_taken;
}

int main()
{
    int elements;
    printf("Enter the number of elements: ");
    scanf("%d", &elements);

    int *arr = (int*)malloc(elements * sizeof(int));
    
    // Best case: Sorted array
    printf("\nBest case: Sorted array\n");
    for (int i = 0; i < elements; i++) {
        arr[i] = i + 1;  // Already sorted
    }
    printf("Array: ");
    printArray(arr, elements);
    printf("Time taken for best case: %lf seconds\n", measureTimeComplexity(arr, elements));
    
    // Worst case: Reversed array
    printf("\nWorst case: Reversed array\n");
    for (int i = 0; i < elements; i++) {
        arr[i] = elements - i;  // Reversed order
    }
    printf("Array: ");
    printArray(arr, elements);
    printf("Time taken for worst case: %lf seconds\n", measureTimeComplexity(arr, elements));
    
    // Average case: Random array
    printf("\nAverage case: Random array\n");
    srand(time(NULL));
    for (int i = 0; i < elements; i++) {
        arr[i] = rand() % 1000;  // Random integers between 0 and 999
    }
    printf("Array: ");
    printArray(arr, elements);
    printf("Time taken for average case: %lf seconds\n", measureTimeComplexity(arr, elements));

    free(arr);  // Free allocated memory
    return 0;
}

