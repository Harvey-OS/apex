/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>

wchar_t *wcsrchr(const wchar_t *s, wchar_t c)
{
	const wchar_t *p;
	for (p=s+wcslen(s); p>=s && *p!=c; p--);
	return p>=s ? (wchar_t *)p : 0;
}
