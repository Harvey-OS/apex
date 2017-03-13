/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>

wchar_t *wcsncpy(wchar_t *restrict d, const wchar_t *restrict s, size_t n)
{
	wchar_t *a = d;
	while (n && *s) n--, *d++ = *s++;
	wmemset(d, 0, n);
	return a;
}
