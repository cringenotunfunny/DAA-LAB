//Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
    mergeSort(arr, 0, n - 1);
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

