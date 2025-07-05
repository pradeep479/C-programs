// Program to seperate the string until ","
#include <string.h>
#include <stdio.h>

int main () 
{
   char str[80] = "hello,world,pradeep,sriram";
   const char s[2] = ",";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
  while( token != NULL ) 
  {
     printf( " %s\n", token );
     token = strtok(NULL, s);
  }
   
return(0);
}

/*
O/P :  
 hello
 world
 pradeep
 sriram
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Splitdata(const char* data, const char* s, int index )
{
    static char temp[256]; //remember to put static
    char* token;
    int count = 0;
    
    strncpy(temp, data, sizeof(temp));
    temp[sizeof(temp)-1] = '\0';
    
    token = strtok(temp, s);
    
    while(token != NULL)
    {
        if(index == count)
        {
            return token;
        }
        token = strtok(NULL, s);
        count++;
    }
return NULL;
}

void main()
{
    const char *buff = "Pradeep,Sriram,1"; //remember to put const char*
    const char *s = ",";
    int index = 2;
    
    char* data1 = Splitdata(buff, s, index);
    printf("splited data: %s\n",data1);
    
}