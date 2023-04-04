#include <stdio.h>
#define PIE
float a =0;
int main ()  
{  
#ifdef PIE
a = 3.14;
#else
printf("enter pie value: ");
scanf("%f",&a);
#endif
printf("value is= %f",a);
return 0;
}

O/P: value is= 3.14

---------------------------------------------
#include <stdio.h>
//#define PIE
float a =0;
int main ()  
{  
#ifdef PIE
a = 3.14;
#else
printf("enter pie value: ");
scanf("%f",&a);
#endif
printf("value is= %f",a);
return 0;
}
O/P: enter pie value: 2
value is= 2

=========================================================================================================================

#include<stdio.h>  
#ifndef __MATH_H  
#error First include then compile  
#else  
void main(){  
    float a;  
    a=sqrt(7);  
    printf("%f",a);  
}  
#endif 

O/P: error: #error First include then compile
   11 | #error First include then compile
      |  ^~~~~