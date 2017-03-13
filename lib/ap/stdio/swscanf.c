/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdarg.h>
#include <wchar.h>
#include "libc.h"

int swscanf(const wchar_t *restrict s, const wchar_t *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vswscanf(s, fmt, ap);
	va_end(ap);
	return ret;
}

weak_alias(swscanf,__isoc99_swscanf);
