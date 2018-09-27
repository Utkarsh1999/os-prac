#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define BUFFER_SIZE 50
#define READ_END 0
#define WRITE_END 1
int main()
{
        char read_msg[BUFFER_SIZE];
        char write_msg[BUFFER_SIZE]="alisha";
        int fd[2];
        pid_t pid;
        if(pipe(fd)== -1)
        {
            fprintf(stderr,"PIPE FAILED");
            return 1;
        }
        pid= fork();
        if(pid<0)
        {
            fprintf(stderr,"FORK FAILED");
            return 1;
        }
        else if(pid>0)
        {
            /*PARENT PROCESS*/
            /*CLOSE THE UNUSED END OF THE PIPE (READ END)*/
            close(fd[READ_END]);
            /*WRITE TO THE PIPE*/
            write(fd[WRITE_END],write_msg,strlen(write_msg));
            close(fd[WRITE_END]);
        }
        else
        {
            /*CHILD PROCESS*/
            /*CLOSE THE UNUSED END OF THE PIPE (WRITE END)*/
            close(fd[WRITE_END]);
            read(fd[READ_END],read_msg,BUFFER_SIZE);
            printf("read %s",read_msg);
            close(fd[READ_END]);
        }

    return 0;
}
