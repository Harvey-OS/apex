/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

size_t __freadahead(FILE *f)
{
	return f->rend - f->rpos;
}

const char *__freadptr(FILE *f, size_t *sizep)
{
	size_t size = f->rend - f->rpos;
	if (!size) return 0;
	*sizep = size;
	return (const char *)f->rpos;
}

void __freadptrinc(FILE *f, size_t inc)
{
	f->rpos += inc;
}

void __fseterr(FILE *f)
{
	f->flags |= F_ERR;
}
