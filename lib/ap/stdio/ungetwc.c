/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include "locale_impl.h"
#include <wchar.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

wint_t ungetwc(wint_t c, FILE *f)
{
	unsigned char mbc[MB_LEN_MAX];
	int l=1;

	FLOCK(f);

	if (f->mode <= 0) fwide(f, 1);

	if (!f->rpos) __toread(f);
	if (!f->rpos || f->rpos < f->buf - UNGET + l || c == WEOF ||
	    (!isascii(c) && (l = wctomb((void *)mbc, c)) < 0)) {
		FUNLOCK(f);
		return WEOF;
	}

	if (isascii(c)) *--f->rpos = c;
	else memcpy(f->rpos -= l, mbc, l);

	f->flags &= ~F_EOF;

	FUNLOCK(f);
	return c;
}
