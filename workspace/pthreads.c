#include<pthread.h>
#include<stdio.h>
int sum=0;
int sum1=1;
void *runner(void *param);
void *runner1(void *param);
int main(int argc, char *argv[])
{
    pthread_t tid,tid1;
    pthread_attr_t attr;
    if(argc!=3)
    {
        fprintf(stderr,"USAGE: a.out <integer value>\n");
        return -1;
    }
    if(atoi(argv[1])<0)
    {
        fprintf(stderr,"%d must be >=0\n", atoi(argv[1]));
        return -1;
    }
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_create(&tid1,&attr,runner1,argv[2]);
    pthread_join(tid,NULL);
    pthread_join(tid1,NULL);
    printf("sum = %d\n", sum);
    printf("multiplicative sum= %d\n",sum1);
}
void *runner(void *param)
{
    int i, upper= atoi(param);
    sum=0;
    for(i=0;i<=upper;i++)
        sum+=i;
    pthread_exit(0);
}
void *runner1(void *param)
{
    int i, upper= atoi(param);
    sum1=1;
    for(i=1;i<=upper;i++)
        sum1*=i;
    pthread_exit(0);
}
