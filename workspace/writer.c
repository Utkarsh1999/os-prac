#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include <sys/mman.h>
#include<sys/stat.h>
int main()
{
	const int size= 4096;
	const char *name = "p1";
	const char *msg = "ALISHA";
	int shm_fd;
	void *ptr;
	shm_fd= shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, size);
	ptr= mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	sprintf(ptr, "%s", msg);
	// sprintf(buffer, "Sum of %d and %d is %d", a, b, c);
	return 0;
}