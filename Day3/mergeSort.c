//Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high){
    int arrlen = high - low + 1;
    int temp[arrlen];
    int i = 0;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[i] = arr[left];
            i++;
            left++;
        }
        else{
            temp[i] = arr[right];
            i++;
            right++;
        }
    }
    while(left <= mid){
        temp[i] = arr[left];
        i++;
        left++;
    }
    while(right <= high){
        temp[i] = arr[right];
        i++;
        right++;
    }
    for(int i = 0; i < arrlen; i++){
        arr[low + i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high){
    if (low >= high) return;
    int mid = (low + high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

