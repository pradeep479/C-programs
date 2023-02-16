/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    char word1[] = "Pradeep Sriram";
    char word2[] = "sriram";
    
    char*p;
    
    p=strstr(word1,word2);
    if(p)
    printf("%s found!!\n",p);
    else
    printf("not found");
    

    return 0;
}


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
 =====================================================================================================================================================
 
 /* MACROS DEF*/
 
 #include <stdio.h>

#define two_name(a,b) \
        printf(#a" "#b )
int main()
{
    two_name(Pradeep, Sriram);
}

 O/P :  Pradeep Sriram
 
 ----------------------------------------------------------------
 // 
 #include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void) {
   printf("Max between 20 and 10 is %d\n", MAX(10, 20));  
   return 0;
}

O/P: max is 20
 ====================================================================================================================================================