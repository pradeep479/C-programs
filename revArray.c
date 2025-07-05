#include <stdio.h>

void revArr(int *arr, int size)
{
    for(int i=0; i<size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

int main()
{
    
    int num_arr[] = {1,2,3,4,5,6,7,8};
    int arr_size = sizeof(num_arr)/sizeof(num_arr[0]);
    
    printf("Before swap: ");
    for(int i=0;i<arr_size; i++)
    {
        printf("%d, ",num_arr[i]);
    }
    printf("\n");
    
    revArr(num_arr, arr_size);

    printf("After swap : ");
    for(int i=0;i<arr_size; i++)
    {
        printf("%d, ",num_arr[i]);
    }
    printf("\n");
    return 0;
}

/*
| Step | i | arr\[i] | arr\[n-1-i] | After Swap                 |
| ---- | - | ------- | ----------- | -------------------------- |
| 1    | 0 | 10      | 50          | {50, 20, 30, 40, 10}       |
| 2    | 1 | 20      | 40          | {50, 40, 30, 20, 10}       |
| 3    | 2 | 30      | 30          | No change (center element) |
*/
