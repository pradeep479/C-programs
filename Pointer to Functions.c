#include <stdio.h>
void display();

int main()
{
    /**
     * If we forget to put bracket between void *dis();  
     * warning: dereferencing ‘void *’ pointer 
     * 
     * should put like these void (*dis)(); 
     */
    void (*dis)(); 
    dis = display; //assign address of function
    (*dis)(); //call the function display
    display();

    return 0;
}

void display()
{
    printf("HELLO!!\n");
}
