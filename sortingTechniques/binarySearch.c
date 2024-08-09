#include <stdio.h>

int binarySearch(int arr[], int lb, int ub, int key){
    if (lb <= ub){
        int mid = (lb + ub)/2;
        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid] > key){
            binarySearch(arr, lb, mid - 1, key);
        }        
        else{
            binarySearch(arr, mid + 1, ub, key);
            }
    }
    return -1;
}


int main(){

    int number;
    
    printf("Enter the number of elements in the array : ");
    scanf("\n%d", &number);

    int arr[number], lb, ub, key;

    printf("\nEnter the numbers into the array : ");
    for (int i = 0; i < number; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the lowebound, upperbound and the key to be found in order : ");

    scanf("%d", &lb);
    scanf("%d", &ub);
    scanf("%d", &key);

    printf("\nThe entered array is : ");
    for (int i = 0; i < number; i++){
        printf("%d ", arr[i]);
    }

    binarySearch(arr, lb, ub, key);

return 0;
}