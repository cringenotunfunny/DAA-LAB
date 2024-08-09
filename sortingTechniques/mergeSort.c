#include<stdio.h>

int merge(int arr[], int low, int mid, int high){
    int temp[high - low];
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
        temp[i] = arr[high];
        i++;
        right++;
    }
    for(int i = low; i < high; i++){
        arr[i] = temp[i - low];
    }
    for(int i = low; i < high; i++){
        printf("%d ", arr[i]);
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
    printf("Enter the lowerbound index, upperbound index and the size of the array : ");
    scanf("%d %d %d", &low, &high, &size);
    int arr[size];


    printf("\nEnter the numbers into the array : ");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe entered array is : ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    mergeSort(arr, low, high);

    return 0;
}