#include <stdio.h>

//Rotate Right
void rotateArrayRight(int arr[], int index){	
    int *left = arr;            
    int *right = arr + index;  
    
    while (left < right) {

        int temp = *left;
        *left = *right;
        *right = temp;
        
        left++;
        right--;
    }
}

int main() {
    int n, i, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf ("Enter the index where you want the change to appear: ");
    scanf ("%d", &index);

    printf("Array before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
	
	rotateArrayRight(arr, index);
	
    printf("Array after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}





