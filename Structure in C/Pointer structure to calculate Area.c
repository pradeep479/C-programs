
// ********************Calculate area of Rectangle using Structures****************************
#include <stdio.h>

typedef struct 
{
    int l;
    int b;
}Rectangle;

int calculateArea(Rectangle* rect)
{
    return rect->l * rect->b;
}

void setValues(Rectangle* rect)
{
    printf("Enter Length and Breadth: ");
    scanf("%d %d",&rect->l,&rect->b);
}

int main()
{
    Rectangle myRect;
    
    setValues(&myRect);
    int area = calculateArea(&myRect);
    printf("Rectangle are is : %d\n",area);
    return 0;
}


O/P:

Enter Length and Breadth: 5 7
Rectangle are is : 35
