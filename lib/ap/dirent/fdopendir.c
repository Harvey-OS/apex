/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

DIR *fdopendir(int fd)
{
	DIR *dir;
	struct stat st;

	if (fstat(fd, &st) < 0) {
		return 0;
	}
	if (!S_ISDIR(st.st_mode)) {
		errno = ENOTDIR;
		return 0;
	}
	if (!(dir = calloc(1, sizeof *dir))) {
		return 0;
	}

	fcntl(fd, F_SETFD, FD_CLOEXEC);
	dir->dd_fd = fd;
	return dir;
}
