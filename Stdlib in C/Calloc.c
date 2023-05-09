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
