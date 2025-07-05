#include "bday.h"
#include "string.h"

void printName(Person *person)
{
    printf("Bday boy name is: %s\n",person->name);
}

void celebrateBday(Person *person)
{
    
    person->age++;
    printf("\n!!!Happy %dth Bday %s!!!\n",person->age,person->name);
}