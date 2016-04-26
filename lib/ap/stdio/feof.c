#include "stdio_impl.h"

#undef feof

int feof(FILE *f)
{
	FLOCK(f);
	int ret = !!(f->flags & F_EOF);
	FUNLOCK(f);
	return ret;
}
