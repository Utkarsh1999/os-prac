#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    pid= fork();
    printf("VALUE OF PID: %d\n", pid);
    if(pid<0)
    {
        fprintf(stderr,"FORK FAILED");
        return -1;
    }
    else if (pid==0)
    {
        printf("HEY I'M THE CHILD PROCESS \n");
        printf("\n Parent Process Id: %d\n",getppid());
        printf("\n Child process Id : %d\n",getpid());
    }
    else
    {
        wait(NULL);
        printf("HEY I'M THE PARENT PROCESS \n");
        printf("\n Parent Process Id: %d\n",getpid());
        printf("\n Child process Id : %d\n",pid);
    }
    return 0;
}
