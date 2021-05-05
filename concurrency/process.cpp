#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
using namespace std;

int main(int argn, char **argv)
{
    cout << argn << endl;
    for (int n = 0; n < argn; ++n)
    {
        cout << *argv++ << endl;
    }
    
    pid_t child_pid;
    cout << "=======Started =========" << endl;

    if (argn == 3)
    {
        child_pid = fork(); // Create a new child process;
        if (child_pid < 0)
        {
            printf("fork failed");
            return 1;
        }
        else if (child_pid == 0)
        {
            printf("child process successfully created!\n");
            printf("child_PID = %d,parent_PID = %d\n",
                   getpid(), getppid());
        }
        else
        {
            wait(NULL);
            printf("parent process successfully created!\n");
            printf("child_PID = %d, parent_PID = %d\n", getpid(), getppid());
        }
    }

    else if (argn == 2)
        {
            execl("a.out", "d", "f", "f");
        }
    else if (argn==3)
        system("./a.out ofof fosfs odfs ggggg");

    cout << "==========End - process =======" << endl;
     

    cout << "==========End ========= process =======" << endl;
    return 0;
}