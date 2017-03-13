/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

int fgetpos(FILE *restrict f, fpos_t *restrict pos)
{
	off_t off = ftello(f);
	if (off < 0) return -1;
	*(off_t *)pos = off;
	return 0;
}
