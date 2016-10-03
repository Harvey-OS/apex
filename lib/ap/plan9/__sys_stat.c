/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "sys9.h"

/* syscalls in libc */
extern	int	stat(const char*, unsigned char*, int);
extern	int	fstat(int, unsigned char*, int);

int
__sys_stat(const char *c, unsigned char *a, int i)
{
	return stat(c, a, i);
}

int
__sys_fstat(int i, unsigned char *c, int n)
{
	return fstat(i, c, n);
}
