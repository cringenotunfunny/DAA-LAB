#include <stdio.h>
#include "sortFuncUtils.h" 

int main() {
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

    bubbleSort(numbers, totalNumbers);

    printf("The sorted array is : \n");
    for (int i = 0; i < totalNumbers; i++){
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}
