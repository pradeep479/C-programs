/******************** VOID POINTER ****************/
/*Void Pointer: It is a form of pointer which is used to point another variable of any data type.
 So, it can store the address of a variable of any data type.*/
 #include<stdio.h>
 int main() 
{ 
    int x = 4; 
    float y = 5.5; 
    void *ptr; 
    ptr = &x; 
    printf("Integer variable is = %d", *( (int*) ptr) );  // If you use *(ptr) -> error: invalid use of void expression
    ptr = &y;  
    printf("\nFloat variable is= %f", *( (float*) ptr) ); 
    return 0; 
} 
/*
O/P: Integer variable is = 4
Float variable is = 5.500000
*/

//============================================================================================================================
//******************** ARRAY OF POINTERS****************
#include<stdio.h>
int main() 
{ 
int array[10];     
int *ptr1 = array;   // no need to mention & operator in arrays
ptr1[0] = 1;        
*(array + 1) = 2;   // all are same 
*(1 + array) = 2;   // *(array) means array[0]
array[2] = 4; 

printf("%d\n",ptr1[0]);                      // O/P: 1 2 2 4
printf("%d\n",*(array + 1));
printf("%d\n",*(1 + array));
printf("%d",array[2]);
} 
