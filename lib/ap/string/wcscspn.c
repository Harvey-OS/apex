/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>

size_t wcscspn(const wchar_t *s, const wchar_t *c)
{
	const wchar_t *a;
	if (!c[0]) return wcslen(s);
	if (!c[1]) return (s=wcschr(a=s, *c)) ? s-a : wcslen(a);
	for (a=s; *s && !wcschr(c, *s); s++);
	return s-a;
}
