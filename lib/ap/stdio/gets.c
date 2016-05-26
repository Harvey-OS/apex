/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include <limits.h>
#include <string.h>

char *gets(char *s)
{
	char *ret = fgets(s, INT_MAX, stdin);
	if (ret && s[strlen(s)-1] == '\n') s[strlen(s)-1] = 0;
	return ret;
}
