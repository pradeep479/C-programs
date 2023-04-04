/* Swap two variables without using temp variable */

#include <stdio.h>
int num1=50, num2=100;
int main()
{
    printf("Before swapping num1 = %d num2 = %d\n",num1,num2);
    num1 = num1 + num2; //150
    num2 = num1 - num2; //150-100
    num1 = num1 - num2; //150-50
    printf("After swapping num1 = %d num2 = %d",num1,num2);

    return 0;
}
