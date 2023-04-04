/*==================================================================================================================================*/
 
 /* MACROS DEF*/
 // Program to add two strings using MACROS
 #include <stdio.h>

#define TWO_NAME(a,b) \
        printf(#a" "#b )
int main()
{
    TWO_NAME(Pradeep, Sriram); // No need to use "Pradeep" in macros or it'll print "Pradeep"Sriram
}

 O/P :  Pradeep Sriram
 

 /*=====================================================================================================*/

 // Program to compare two no using macros
 #include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void) {
   printf("Max between 20 and 10 is %d\n", MAX(10, 20));  
   return 0;
}

O/P:
Max between 20 and 10 is 20


 /*========================================================================================================*/

// PROGRAM TO ADD TWO NUM USING MACROS

#include <stdio.h>

#define NAME(a,b) (a+b)

int main()
{
    printf("sum of two num is: %d",NAME(550,450));
}

O/P: 
sum of two num is: 1000