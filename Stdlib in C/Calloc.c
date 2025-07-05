/*
SYNTAX: int* variable = (int*)calloc(n,sizeof(int))
* calloc() initializes the memory to zero
* calloc() adds some extra memory overhead
*/

// ******************* CALLOC USING STRUCTURE ******************

#include <stdio.h>
#include <stdlib.h>
int i=0;
int n;

struct student
{
    int num[3];
    char name[100];
};
void main()
{
    struct student *sptr; //pointer to store the return calloc value
    struct student *tmp;
    
    printf("How many students: ");
    scanf("%d",&n);
    sptr = (struct student*)calloc(n,sizeof(struct student));
    
    for(i=0,tmp=sptr;i<n;i++,tmp++) //If u miss the tmp++ you will get last value you entered n times
    {
        printf("Student number:#%d\n",i+1);
        printf("Enter roll number: ");
        scanf("%d",&tmp->num[i]);
        printf("Enter name :");
        scanf("%s",tmp->name);
    }
    
    printf("\nEntered details are:\n"); 
    for(i=0,tmp=sptr;i<n;i++,tmp++) //If u miss the tmp++ you will get last value you entered n times
    {
        printf("Student number:#%d\n",i+1);
        printf("Roll number: %d\n",tmp->num[i]);
        printf("Name: %s\n",tmp->name);
    }
    
}

O/P:
How many students: 2

Student number:#1
Enter roll number: 63
Enter name :Pradeep
Student number:#2
Enter roll number: 90
Enter name : Sriram

Entered details are:
Student number:#1
Roll number: 63
Name: Pradeep
Student number:#2
Roll number: 90
Name: Sriram

/*************************** REMOVE DUPLICATE IN UNSORTED ARRAY ************************/

#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100000

int arr[] = {2455,2000,3500,5562,4532,1212,1212,1212,8500,8500,1,1,1};

int RemoveDuplicate(int arr[],int n)
{
    int *hashset = (int*)calloc(MAX_SIZE,sizeof(int));
    
    if(hashset == NULL)
    {
        printf("memory allocation failed");
    }
    
    for(int i=0;i<n;i++)
    {
        if(hashset[arr[i]] == 0)
        {
            hashset[arr[i]] = 1;
        }
    }
    
    for(int i=0;i<MAX_SIZE;i++)
    {
        if(hashset[i] == 1)
        {
           printf("%d ",i);
        }
    }
    free(hashset);
    
}

int main()
{
RemoveDuplicate(arr,13);
    return 0;
}


O/P:
1 1212 2000 2455 3500 4532 5562 8500 