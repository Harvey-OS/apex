/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

int fileno(FILE *f)
{
	/* f->fd never changes, but the lock must be obtained and released
	 * anyway since this function cannot return while another thread
	 * holds the lock. */
	FLOCK(f);
	FUNLOCK(f);
	return f->fd;
}
