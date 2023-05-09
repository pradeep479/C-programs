
/* A C program to demonstrate working of memcpy */
#include <stdio.h>
#include <string.h>

int main ()
{
int data1 = 123456;
int data2 = 456;

printf("before memcpy: %d\n",data2);

/* Copies contents of str2 to str1 */
memcpy (&data2, &data1, sizeof(data1)); // For int we need to pass address of that variable

printf("After memcpy: %d\n",data2);

return 0;
}

O/P:

before memcpy: 456
After memcpy: 123456


// ********************************** MEMCPY EXAMPLE 2 ************************* //

/* memcpy example */
#include <stdio.h>
#include <string.h>

struct {
  char name[40];
  int age;
} person, person_copy;

int main ()
{
  char myname[] = "Pradeep Sriram";

  /* using memcpy to copy string: */
  memcpy ( person.name, myname, strlen(myname)+1 );
  person.age = 24;

  /* using memcpy to copy structure: */
  memcpy ( &person_copy, &person, sizeof(person) );

  printf ("Name: %s\nAge:  %d\n", person_copy.name, person_copy.age );

  return 0;
}

O/P:
Name: Pradeep Sriram
Age:  24
