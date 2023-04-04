
#include <stdio.h>
int num1,num2;
int *power;
void power_value(int a, int b, int *pow);
int main()
{
    printf("enter power of value a and b:");
    scanf("%d %d",&num1,&num2);
    power_value(num1,num2,&power); // without passing address to func it won't work
    printf("%d power %d value is: %d",num1,num2,power);// If you pass *power -> it won't Run
                                                       // If you pass &power -> It'll return address
    return 0;
}

void power_value(int a, int b, int *pow)
{
    int no=1;
    for(int i=1; i<=b; i++)
        no*=a;
    *pow = no;
}

O/P:
enter power of value a and b:2 3
2 power 3 value is: 8
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int a,b,c,d,e;
void sumnavg();
    int sum;
    float avg;
int main()
{

    printf("print 5 numbers: ");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    sumnavg(a,b,c,d,e,&sum,&avg);
    printf("sum value is: %d\n",sum);
    printf("avg value is: %f\n",avg);
    return 0;
}
void sumnavg(int p, int q,int r, int s,int t,int *sum, float* avg)
{
    *sum = p+q+r+s+t;
    *avg =*sum/5;
}

O/P:
print 5 numbers: 1 2 3 4 5
sum value is: 15
avg value is: 3.000000


=============================================================================================================================
  *******PASSING POINTERS TO FUNCTIONS************

#include <stdio.h>

void func(int *ptr)
{
    (*ptr)++; // *(ptr++) it will not work
}
int main()
{
    int i=10,*p;
    p=&i;
    func(p);
    printf("%d ",*p);
    printf("%d",i);
    return 0;
}

O/P: 11 11