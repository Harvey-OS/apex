/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int remove(const char *path)
{
	int r = unlink(path);
	if (r==-EISDIR) r = rmdir(path);
	return r;
}
