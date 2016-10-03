/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "sys9.h"

/* syscall in libc */
extern	int32_t	read(int, void*, int32_t);

int
__sys_read(int fd, void* buf, int32_t nbytes)
{
	return read(fd, buf, nbytes);
}
