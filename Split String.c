#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *SplitString(char* str,char seperator,int index)
{
    int found=0;
    int strIndex[2] = {0,-1};
    int maxlen = strlen(str)-1;

    for(int i=0; i<=maxlen && found<=index;i++)
    {
        if(str[i]==seperator || i==maxlen)
        {
            found++;
            strIndex[0] = strIndex[1]+1;
            strIndex[1] = (i==maxlen)? i+1 : i;
        }
    }

    if(found > index)
    {
        int len = strIndex[1] - strIndex[0];
        char* retString = (char*)malloc((len+1)*sizeof(char));
        strncpy(retString,str+strIndex[0],len);
        retString[len] = '\0';
        return retString;
    }
    
    else
    {
        char* emptyString = '\0';
        return emptyString;
    }
    
}

void main()
{
    char enteredString[50];
    printf("Enter the String to seperate: ");
    scanf("%s",enteredString);
    
    printf("Value: %s\n",SplitString(enteredString,',',0));
    
}


O/P:

Enter the String to seperate: Pradeep,Sriram
Value: Pradeep
