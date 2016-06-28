/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <dirent.h>
#include <unistd.h>
#include "libc.h"

void seekdir(DIR *dir, long off)
{
	LOCK(dir->lock);
	dir->dd_loc = lseek(dir->dd_fd, off, SEEK_SET);
	dir->dd_buf = 0;
	UNLOCK(dir->lock);
}
