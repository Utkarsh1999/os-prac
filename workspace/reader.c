#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
int main()
{
	const int size= 4096;
	const char *name="p1";
	int shm_fd;
	void *ptr;
	shm_fd= shm_open(name, O_RDONLY,0666);
	ptr= mmap(0, size,PROT_READ, MAP_SHARED, shm_fd,0);
	printf("%s",(char*)ptr);
	shm_unlink(name);
	return 0;
}