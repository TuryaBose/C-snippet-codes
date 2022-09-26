/*
The main purpose of this snippet is to create one parent with three children processes using the fork() function.
Each process id is checked and using functions displayed.
*/


//Author: Turya Bose
//Version: 1.0
//Date: 25.09.22


#include <unistd.h>
#include <stdio.h>

int main()
{
    // Creating first child
    int n1 = fork();

    // Creating second child. First child also executes this line and creates grandchild.
    int n2 = fork();

    if (n1 > 0 && n2 > 0)
    {
        printf("parent\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }
    else if (n1 == 0 && n2 > 0)
    {
        printf("\nFirst child\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d  \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }
    else if (n1 > 0 && n2 == 0)
    {
        printf("\nsecond child\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d  \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }
    else {
        printf("\nthird child\n");
        printf("%d %d \n", n1, n2);
        printf("   my id is %d \n", getpid());
        printf("   my parentid is %d \n", getppid());
    }

    return 0;
}




