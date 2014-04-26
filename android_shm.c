

#include "android_shm.h"

#define ASHMEM_DEVICE	"/dev/ashmem"

int shmctl (int __shmid, int __cmd, struct shmid_ds *__buf)
{
	int ret=0;
	if (__cmd == IPC_RMID)
	{
		int length = ioctl(__shmid, ASHMEM_GET_SIZE, NULL);
		struct ashmem_pin pin = {0 , length};
		ret = ioctl(__shmid, ASHMEM_UNPIN, &pin);
		close(__shmid);
	}
	return ret;
}

int shmget (key_t __key, size_t __size, int __shmflg)
{
	int fd,ret;
	char key[11];
	
	fd = open(ASHMEM_DEVICE, O_RDWR);
	if (fd < 0)
		return fd;

	sprintf(key,"%d",__key);
	ret = ioctl(fd, ASHMEM_SET_NAME, key);
	if (ret < 0)
		goto error;

	ret = ioctl(fd, ASHMEM_SET_SIZE, __size);
	if (ret < 0)
		goto error;

	return fd;
	
error:
	close(fd);
	return ret;
}

void *shmat (int __shmid, const void *__shmaddr, int __shmflg)
{
	size_t *ptr, size = ioctl(__shmid, ASHMEM_GET_SIZE, NULL);
	ptr = mmap(NULL, size + sizeof(size_t), PROT_READ | PROT_WRITE, MAP_SHARED, __shmid, 0);
	*ptr = size;    //save size at beginning of buffer, for use with munmap
	return &ptr[1];
}

int shmdt (const void *__shmaddr)
{
	size_t *ptr, size;
	ptr = (size_t *)__shmaddr;
	ptr--;
	size = *ptr;    //find mmap size which we stored at the beginning of the buffer
	return munmap((void *)ptr, size + sizeof(size_t));
}

