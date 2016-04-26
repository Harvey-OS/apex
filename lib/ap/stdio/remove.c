#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int remove(const char *path)
{
	int r = unlink(path);
	if (r==-EISDIR) r = rmdir(path);
	return r;
}
