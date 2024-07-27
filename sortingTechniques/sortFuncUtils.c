// sorting_utils.c

#include "sortFuncUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int lowerBound, int upperBound, int totalNumbers, int arr[])
{
    printf("The random numbers are: \n");
    srand(time(NULL));
    for (int i = 0; i < totalNumbers; i++)
    {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
        printf ("%d ", arr[i]);
    }

}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}