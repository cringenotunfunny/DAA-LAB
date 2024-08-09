#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
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
    selectionSort(arr, n);
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
    //printArray(arr, elements);
    printf("Time taken for best case: %lf seconds\n", measureTimeComplexity(arr, elements));
    
    // Worst case: Reversed array
    printf("\nWorst case: Reversed array\n");
    for (int i = 0; i < elements; i++) {
        arr[i] = elements - i;  // Reversed order
    }
    printf("Array: ");
    //printArray(arr, elements);
    printf("Time taken for worst case: %lf seconds\n", measureTimeComplexity(arr, elements));
    
    // Average case: Random array
    printf("\nAverage case: Random array\n");
    srand(time(NULL));
    for (int i = 0; i < elements; i++) {
        arr[i] = rand() % 1000;  // Random integers between 0 and 999
    }
    printf("Array: ");
    //printArray(arr, elements);
    printf("Time taken for average case: %lf seconds\n", measureTimeComplexity(arr, elements));

    free(arr);  // Free allocated memory
    return 0;
}

