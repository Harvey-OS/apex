/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include "libc.h"

int fwscanf(FILE *restrict f, const wchar_t *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vfwscanf(f, fmt, ap);
	va_end(ap);
	return ret;
}

weak_alias(fwscanf,__isoc99_fwscanf);
