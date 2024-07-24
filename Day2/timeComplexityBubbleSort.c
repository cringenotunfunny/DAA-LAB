#include <stdio.h>
#include <time.h>

// Bubble Sort Function
void bubbleSort(int arr[], int n){	
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }	
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
	
	clock_t start = clock(); 

    bubbleSort(arr, n);
	
	clock_t end = clock();
	
	double final = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Array after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The start time was : %ld clocks \n", (long)start);    
    printf("The end time was : %ld clocks \n", (long)end);
    printf("The time required was : %f seconds \n", final);

    return 0;
}

