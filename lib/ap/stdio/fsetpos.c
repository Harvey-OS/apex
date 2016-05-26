/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

int fsetpos(FILE *f, const fpos_t *pos)
{
	return fseeko(f, *(const off_t *)pos, SEEK_SET);
}
