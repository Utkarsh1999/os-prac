#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
  pid_t pid;
  pid = fork(); /*fork a child process*/
  if(pid<0) /* Error Encountered*/
  {
    fprintf(stderr,"Fork Failed");
    return 1;
  }
  else if(pid==0) /*child process created*/
  {
    // printf("child called");
    execlp("/bin/ls","ls",NULL);
    //return;
  }
  else /* Parent Process*/
  { /* Parent will wait for child to terminate*/
    wait(NULL);
    printf("parent Process Completed \n");
  }
  return 0;
}