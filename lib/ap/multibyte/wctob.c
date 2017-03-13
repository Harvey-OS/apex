/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wchar.h>
#include <stdlib.h>
#include "internal.h"

int wctob(wint_t c)
{
	if (c < 128U) return c;
	if (MB_CUR_MAX==1 && IS_CODEUNIT(c)) return (unsigned char)c;
	return EOF;
}
