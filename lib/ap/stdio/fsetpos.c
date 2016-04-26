#include "stdio_impl.h"

int fsetpos(FILE *f, const fpos_t *pos)
{
	return fseeko(f, *(const off_t *)pos, SEEK_SET);
}
