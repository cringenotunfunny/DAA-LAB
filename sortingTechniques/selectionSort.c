#include<stdio.h>

int selectionSort(int arr[], int range){
    for (int i = 0; i <= range - 2; i++){
        int minimum = i;
        for (int j = i; j <= range; j++){
            if (arr[j] < arr[minimum]) minimum = j;
        }
    int temp = arr[minimum];
    arr[minimum] = arr[i];
    arr[i] = temp;
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

    selectionSort(arr, number);

    printf("\nSorted array : ");
    for (int i = 0; i < number; i++){
        printf("%d ", arr[i]);
    }


}