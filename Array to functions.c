//********************************** PASSING ARRAY TO FUNCTIONS*****************************************
#include <stdio.h>

int arr[]={1,2,3,4};
char *name[3] = {"name","hello","world"};

void numbers(int a[],int n)
{
printf("Numbers:\n");
for(int i=0;i<n;i++)
    printf(" %d\n",a[i]);
}

void characters(char *b[],int m)
{
    printf("Names:\n");
    for(int i=0;i<m;i++)
    {
        printf(" %s\n",*(b+i)); // b[i] & *(b+i) are same
    }
}
int main()
{
   numbers(arr,sizeof(arr)/sizeof(arr[0])); // If we don't know the array count we can use this instead of 4
   characters(&name[0],3);  // name & &name[0] are same
    return 0;
}

/*
O/P:
Numbers:
 1
 2
 3
 4
Names:
 name
 hello
 world
*/