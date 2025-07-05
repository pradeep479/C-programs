#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    float Value1;
    float Value2;
}Division;


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


/**
 * @brief: Convert string to float format and save it to struct
 * @param: To store in Structure
 * @param: str format 1
 * @param: str format 2
 **/
void strtofloat(Division* d,char *dat1, char *dat2)
{
    d->Value1 = strtof(dat1,NULL);
    d->Value2 = strtof(dat2,NULL);
}

void main()
{
    Division divi;
    char enteredString[50];
    
    printf("Enter the String to seperate: ");
    scanf("%s",enteredString);
    
    char* data1=SplitString(enteredString,',',0); 
    char* data2=SplitString(enteredString,',',1); 
    
    strtofloat(&divi,data1,data2); //store the val to struct
    free(data1);
    free(data2);
    printf("Divided value : %0.2f\n",divi.Value1/divi.Value2);
    
}

O/P:

Enter the String to seperate: 57,4
data1: 57
data2: 4
Divided value : 14.25
