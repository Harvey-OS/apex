/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "internal.h"

wint_t btowc(int c)
{
	int b = (unsigned char)c;
	return b<128U ? b : (MB_CUR_MAX==1 && c!=EOF) ? CODEUNIT(c) : WEOF;
}
