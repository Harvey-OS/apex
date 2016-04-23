#include "stdio_impl.h"
#include <unistd.h>

static int __aio_close(int fd)
{
	return fd;
}

int __stdio_close(FILE *f)
{
	return close(__aio_close(f->fd));
}
