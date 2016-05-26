/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>

wchar_t *wcscpy(wchar_t *restrict d, const wchar_t *restrict s)
{
	wchar_t *a = d;
	while ((*d++ = *s++));
	return a;
}
