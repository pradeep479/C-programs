#ifndef __BDAY__
#define __BDAY__

#include<stdio.h>

typedef struct {
    char name[20];
    int age;
}Person;

void printName(Person* person);
void celebrateBday(Person* person);

#endif