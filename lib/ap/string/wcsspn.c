/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>

size_t wcsspn(const wchar_t *s, const wchar_t *c)
{
	const wchar_t *a;
	for (a=s; *s && wcschr(c, *s); s++);
	return s-a;
}
