// ***************************** Enter StudentInfo using Struct Pointer *******************************
#include <stdio.h>

typedef struct 
{
    char name[20];
    int  rollno;
    int  grade;
}Student;

void EnterStudentInfo(Student* s)
{
    printf("Enter Student name: ");
    scanf("%s",s->name);
    printf("Enter Student rollno: ");
    scanf("%d",&s->rollno);
    printf("Enter Student grade: ");
    scanf("%d",&s->grade);
    printf("\n");
}

void printStudentInfo(Student* s)
{
    printf("Roll No: %d\n",s->rollno);
    printf("Name: %s\n",s->name);
    printf("Grade: %d\n",s->grade);
    printf("\n");
}
int main()
{
    Student stud1,stud2;
    
    EnterStudentInfo(&stud1);
    EnterStudentInfo(&stud2);
    
    printStudentInfo(&stud1);
    printStudentInfo(&stud2);
    
    return 0;
}

/*
O/P:

Enter Student name: Pradeep
Enter Student rollno: 63
Enter Student grade: 1

Enter Student name: Sriram
Enter Student rollno: 90
Enter Student grade: 2

Roll No: 63
Name: Pradeep
Grade: 1

Roll No: 90
Name: Sriram
Grade: 2
*/
