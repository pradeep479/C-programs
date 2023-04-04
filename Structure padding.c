
#include <stdio.h> 
struct student  
{  
  
  int c; // 4 bytes  
  char a; // 1 byte  
  char b; // 1 byte  
}stud;
int main()
{
    printf("%ld",sizeof(stud));

    return 0;
}

O/P: 8

/*===================================================================================================================================*/
									***USING PRAGMA***

#include <stdio.h>
#pragma pack(1)  
struct student  
{  
  
  int c; // 4 bytes  
  char a; // 1 byte  
  char b; // 1 byte  
}stud;
int main()
{
    printf("%ld",sizeof(stud));

    return 0;
}

O/P: 6