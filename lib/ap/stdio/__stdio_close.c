/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

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
