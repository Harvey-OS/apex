/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

#undef ferror

int ferror(FILE *f)
{
	FLOCK(f);
	int ret = !!(f->flags & F_ERR);
	FUNLOCK(f);
	return ret;
}
