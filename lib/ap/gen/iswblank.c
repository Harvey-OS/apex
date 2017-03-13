/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <wctype.h>
#include <ctype.h>
#include "libc.h"

int iswblank(wint_t wc)
{
	return isblank(wc);
}

int __iswblank_l(wint_t c, locale_t l)
{
	return iswblank(c);
}

weak_alias(__iswblank_l, iswblank_l);
