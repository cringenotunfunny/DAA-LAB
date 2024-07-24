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

void countDuplicate(int arr[], int n){
    int i = 0, count, maxCount = 0, maxInteger;

    while (i < n){
        count = 1;
        int currentElement = arr[i];
        while (i + 1 < n && arr[i + 1] == currentElement){
            count++;
            i++;
        }
        if(count > 1){
        printf("The number %d occurs %d times\n", arr[i], count);
        }

        if (count > maxCount){
            maxCount = count;
            maxInteger = arr[i];
        }
        i++;
    }
    printf("The number that repeats for the most number of times is %d, which occurs %d times\n", maxInteger, maxCount);
}



int main(){
        int length;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &length);

    printf("\n");

    if(length ==0){
        printf("Empty array\n");
        return 1;
    }

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

    if(length == 1){
        printf("Insufficient array to find duplicate\n");
        return 1;
    }

    bubbleSort(arr, length);

    printf ("The sorted array is : ");
    for (int i = 0; i < length; i++){
        printf(" %d ", arr[i]);
    }

    printf("\n");

    countDuplicate(arr, length);

    return 0;
}




