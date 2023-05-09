**********Program to calculate the sum of n numbers entered by the user using memory allocation*********
#include <stdio.h>
#include<stdlib.h>
int a,*ptr,sum=0;

int main()
{
    printf("enter num: ");
    scanf("%d",&a);
    
    ptr=(int*)malloc(a*sizeof(int));
    for(int i=0;i<a;i++)
    {
        scanf("%d",ptr+i); // stores the numbers from base address of memory  
         sum+= *(ptr+i);  // here *(ptr + i) is same as ptr[i]  
    }
printf("sum is %d",sum);
    free(ptr);

    return 0;
}

O/P: enter num: 3    1 2 3
sum is :6

---------------------------------------------------------------------------------------------------------------------------
*********
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main()
	{
	    char* ptr;
	    char array[] ="Pradeep Sriram";
	    int len = strlen(array);
	    
	    ptr = (char*)malloc(len * sizeof(char));
	    
	    strcpy(ptr,array); // (or) puts(ptr);
	    
	    printf("%s",ptr);
	   
	   	return 0;
	}
	
	O/P: Pradeep Sriram
	=================================================================================================================================
	
	************************* MULTIPLE ARRAYS USING MALLOC************************
	
	// STORES IN DIFFERENT ADDRESS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main()
	{
	    int i;
	    char* ptr[3];
	    char *array[3] ={"hello","Pradeep","Sriram"};
	    
	    int len = strlen(array[0])+strlen(array[1])+strlen(array[2]);
	    	    
	    for(i=0;i<3;i++)
	    {
	    ptr[i] = (char*)malloc(3* sizeof(char));
	    strcpy(ptr[i],array[i]); 
	    printf("%s\t",ptr[i]);
	    printf("%p\n",ptr[i]);
	    }
	    
	    printf("My name is: %s",ptr[1]);
	   // free(ptr); // free the allocated memory
	   	return 0;
	}
	O/P: hello	 0x5636fb01c2a0
		 Pradeep 0x5636fb01c6d0
		 Sriram	 0x5636fb01c6f0
		 My name is: Pradeep


******************* STORES IN SAME ADDRES ****************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main()
	{
	    int i;
	    char* ptr;
	    char *array[3] ={"hello","Pradeep","Sriram"};
	    
	    int len = strlen(array[0])+strlen(array[1])+strlen(array[2]);
	    
	    ptr = (char*)malloc(len * sizeof(char));
	    
	    for(i=0;i<3;i++)
	    {
	    strcpy(ptr,array[i]);  // If u put ptr[i] it won't work
	    printf("%s\t",ptr);
	    printf("%p\n",ptr);
	    }
	    free(ptr); // free the allocated memory
	   	return 0;
	}
	O/P: hello	 	0x55bcd97542a0
		 Pradeep	0x55bcd97542a0
		 Sriram		0x55bcd97542a0
===================================================================================================================