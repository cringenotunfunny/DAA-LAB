#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partitionIndex(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j){
        while (arr[i] <= pivot && i <= high - 1){       //Looking for a number that is greater than pivot
            i++;                                        //Incrementing the value of i till the pointer reaches a bigger number
        }
        while (arr[j] >= pivot && j >= low + 1){
            j--;      
    }
    if (i < j){
        swap(arr, i, j);
    }
    swap(arr, low, j);
    return j;
    }
}

void quickSort(int arr[], int low, int high){
    if (low < high){                                            //Ensure that there are more than 2 numbers in the array
        int index = partitionIndex(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

int main(){

    int low, high, size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    int arr[size];

    printf("\nEnter the lowerbound index and upperbound index : ");
    scanf("%d %d", &low, &high);

    if(low < 0 || high >= size || low > high){
        printf("Invalid indices\n");
        return 1;
    }

    printf("\nEnter the numbers into the array : ");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe entered array is : ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    quickSort(arr, low, high);

    printf("\nThe sorted array is : ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    return 0;
}