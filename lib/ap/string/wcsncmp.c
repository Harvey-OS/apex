/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>

int wcsncmp(const wchar_t *l, const wchar_t *r, size_t n)
{
	for (; n && *l==*r && *l && *r; n--, l++, r++);
	return n ? *l - *r : 0;
}
