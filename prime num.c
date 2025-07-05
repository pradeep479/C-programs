#include <stdio.h>

int checkPrime(int n)
{
    if(n < 1)
    {
        return 0;
    }
    
    for(int i = 2; i <= n/2; i++)
    {
        if(n%2 == 0)
        {
            return 0;
        }
    }
return 1;
}

int main()
{
    if(checkPrime(7))
    {
        printf("Given num is Prime!");
    }
    else
    {
        printf("Given num is not a Prime!");

    }

    return 0;
}