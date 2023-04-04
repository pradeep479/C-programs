/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// SEARCH THE STRING USING strstr() func.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char word1[] = "Pradeep Sriram Firmware Developer";
    char word2[] = "Sriram";
    char*p;

    /*
    char *strstr (const char *s1, const char *s2);

    Parameters:
    s1: This is the main string to be examined.
    s2: This is the sub-string to be searched in s1 string.
    */
    p=strstr(word1,word2);

    if(p)
    printf("%s found!!\n",p);
    else
    printf("not found");
    

    return 0;
}

O/P:
Sriram Firmware Developer found!!

/*====================================================================================================================================*/

#include<stdio.h>

int main() {
    // storing multiple strings using pointer
    char *str[4] = {
        "String", 
        "Topics", 
        "Hello", 
        "World"
    };
    
    int i = 0;
    for (i = 0; i < 4; i++) 
    {
     // variable to iterate over ith string
     printf("%s\n", str[i]);
    }
    
    printf("3rd string is: %s\n",str[2]);
    return 0;
}

O/P:
String
Topics
Hello
World
3rd string is: Hello
