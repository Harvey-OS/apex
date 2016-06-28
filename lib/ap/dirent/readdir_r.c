/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

/* TODO: posix threads */

#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "libc.h"

int readdir_r(DIR *restrict dir, struct dirent *restrict buf, struct dirent **restrict result)
{
	struct dirent *de;
	int errno_save = errno;
	int ret;

	//LOCK(dir->lock);
	errno = 0;
	de = readdir(dir);
	if ((ret = errno)) {
	//	UNLOCK(dir->lock);
		return ret;
	}
	errno = errno_save;
	if (de) memcpy(buf, de, de->d_reclen);
	else buf = NULL;

	//UNLOCK(dir->lock);
	*result = buf;
	return 0;
}

LFS64_2(readdir_r, readdir64_r);
