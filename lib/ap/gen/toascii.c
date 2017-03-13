/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <ctype.h>

/* nonsense function that should NEVER be used! */
int toascii(int c)
{
	return c & 0x7f;
}
