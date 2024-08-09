#include<stdio.h>

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

int main(){

    int number;
    
    printf("Enter the number of elements in the array : ");
    scanf("\n%d", &number);

    int arr[number];

    printf("\nEnter the numbers into the array : ");
    for (int i = 0; i < number; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe entered array is : ");
    for (int i = 0; i < number; i++){
        printf("%d ", arr[i]);
    }

    insertionSort(arr, number);

    printf("\nSorted array : ");
    for (int i = 0; i < number; i++){
        printf("%d ", arr[i]);
    }
}