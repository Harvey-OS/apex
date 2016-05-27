/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include "libc.h"

static size_t do_read(FILE *f, unsigned char *buf, size_t len)
{
	return __string_read(f, buf, len);
}

int vsscanf(const char *restrict s, const char *restrict fmt, va_list ap)
{
	FILE f = {
		.buf = (void *)s, .cookie = (void *)s,
		.read = do_read, .lock = -1
	};
	return vfscanf(&f, fmt, ap);
}
