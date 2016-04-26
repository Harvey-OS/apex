#include "stdio_impl.h"

#undef ferror

int ferror(FILE *f)
{
	FLOCK(f);
	int ret = !!(f->flags & F_ERR);
	FUNLOCK(f);
	return ret;
}
