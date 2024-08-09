#include<stdio.h>

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

    mergeSort(arr, low, high);

    printf("\nThe sorted array is : ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    return 0;
}