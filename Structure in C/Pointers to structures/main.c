// **************** Pointers to structures in C  ***********************//

#include <stdio.h>
#include "bday.h"

Person person;

int main()
{
   printf("\tBDAY CELEBRATION!!\n");
   
   printf("Enter Name: ");
   scanf("%s",person.name);
   
   printf("Enter age: ");
   scanf("%d",&person.age);
   
   printName(&person);
   celebrateBday(&person);

    return 0;
}

/*
O/P:

	BDAY CELEBRATION!!
Enter Name: Pradeep
Enter age: 23
Bday boy name is: Pradeep

!!!Happy 24th Bday Pradeep!!!
*/
