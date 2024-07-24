#include<stdio.h>

void prefixSum(int arr[], int index){
    int sum = 0;
    for (int i = 0; i <= index; i++){
        sum += arr[i];
    }
    printf("The prefix sum of the given array is : %d\n", sum);
}

int main(){
    
    int length, index;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &length);


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

    printf("Enter the index till which calculation needs to be done:");
    scanf("%d", &index);

    printf("\n");
    
    if (index >= length){
        printf("Index does not exist");
        return 1;
    }
    else{
        prefixSum(arr, index);
    }

    return 0;
}