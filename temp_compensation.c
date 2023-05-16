#include <stdio.h>
#include <math.h>

float temp;
float moist = 18.5;
float value;

int main()
{
    printf("enter the temp: ");
    scanf("%f",&temp);
    
    
    
    if(temp<25)
    {
        value = 25.0 - temp;
        printf("Actual Moist is %0.1f ",(round(value)*0.1)+moist);
    }
    else if(temp>25)
    {
       value =temp - 25.0;
       printf("Actual Moist is %0.1f ",moist-(round(value)*0.1));
    }
    else
    {
        printf("%f",moist);
    }
    return 0;

}