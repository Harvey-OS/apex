/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>

wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n)
{
	for (; n && *s != c; n--, s++);
	return n ? (wchar_t *)s : 0;
}
