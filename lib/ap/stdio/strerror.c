/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

/*
 * pANS stdio -- strerror
 */

#include <string.h>
#include <errno.h>

extern char _plan9err[];

#define E(a,b) ((unsigned char)a),
static const unsigned char errid[] = {
#include "__strerror.h"
};

#undef E
#define E(a,b) b "\0"
static const char errmsg[] =
#include "__strerror.h"
;

char *
strerror(int e)
{
	const char *s;
	int i;

	if(e == EPLAN9)
		return _plan9err;
	else
		/* mips has one error code outside of the 8-bit range due to a
		 * historical typo, so we just remap it. */
		if (EDQUOT==1133) {
			if (e==109) e=-1;
			else if (e==EDQUOT) e=109;
		}
		for (i=0; errid[i] && errid[i] != e; i++);
		for (s=errmsg; i; s++, i--) for (; *s; s++);
		return (char *)s;
}

char *
strerror_r(int e, char *buf, int len)
{
	strncpy(buf, strerror(e), len);
	buf[len-1] = 0;
	return buf;
}
