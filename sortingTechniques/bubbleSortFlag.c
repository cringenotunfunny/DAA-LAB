// 15   16   6   8   5
// 15   16   6   8   5
// 15   6   16  8   5
// 15   6   8   16  5
// 15   6   8   5   16 
// This is Pass 1 => largest element goes to the last

#include<stdio.h>
#include "sortFuncUtils.h"

int bubbleSortFlag(int arr[], int length){
    for (int i = 0; i < length - 1; i++){       //Total number of passes : if length = n => loop runs for n-1 times
        int flag = 0;
        for (int j = 0; j < length - i - 1; j++){       //Total number of comparisions in each pass
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag =  1;
            }
        }
        if (flag == 0){
        break;
    }    
}
}

int main(){
    
    int lowerBound, upperBound, totalNumbers;

    printf("Enter lower bound: ");
    scanf("%d", &lowerBound);
    printf("Enter upper bound: ");
    scanf("%d", &upperBound);
    printf("Enter total number of random numbers: ");
    scanf("%d", &totalNumbers);

    int numbers[totalNumbers];


    generateRandomNumbers(lowerBound, upperBound, totalNumbers, numbers);

    printf("\n");

    bubbleSortFlag(numbers, totalNumbers);

    printf("The sorted array is : \n");
    for (int i = 0; i < totalNumbers; i++){
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}