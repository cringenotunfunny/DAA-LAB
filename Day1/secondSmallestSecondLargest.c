// Program to find the 2nd largest and 2nd smallest number in a given array

#include<stdio.h>

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

int main(){

    int length;

    do {
        printf("Enter the number of elements in the array : ");
        scanf("%d", &length);
        
        if (length < 3) {
            printf("Please enter at least 3 numbers.\n");
        }
    } while (length < 3);

    printf("\n");

    int arr[length];

    printf("Enter the elements in the array : \n");
    for (int i = 0; i < length; i++){
        scanf("%d", &arr[i]);
        }

    printf("\n");

    printf ("The entered array is : ");
    for (int i = 0; i < length; i++){
        printf(" %d ", arr[i]);
    }

    printf("\n");

    bubbleSort(arr, length);

    printf ("The sorted array is : ");
    for (int i = 0; i < length; i++){
        printf(" %d ", arr[i]);
    }

    printf("\n");

    if (length == 3) {
        printf("The second smallest and the second largest number is the same: %d\n", arr[1]);
    } else {
        printf("The 2nd smallest number is: %d\n", arr[1]);
        printf("The 2nd largest number is: %d\n", arr[length - 2]);
    }

    return 0;
}