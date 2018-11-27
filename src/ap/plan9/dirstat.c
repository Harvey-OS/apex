/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "lib.h"
#include <string.h>
#include <stdlib.h>
#include "sys9.h"
#include "dir.h"

enum
{
	DIRSIZE	= STATFIXLEN + 16 * 4		/* enough for encoded stat buf + some reasonable strings */
};

Dir*
_dirstat(const char *name)
{
	Dir *d;
	unsigned char *buf;
	int n, nd, i;

	nd = DIRSIZE;
	for(i=0; i<2; i++){	/* should work by the second try */
		d = malloc(sizeof(Dir) + BIT16SZ +nd);
		if(d == nil)
			return nil;
		buf = (unsigned char*)&d[1];
		n = __sys_stat(name, buf, BIT16SZ+nd);
		if(n < BIT16SZ){
			free(d);
			return nil;
		}
		nd = GBIT16((unsigned char*)buf);	/* size needed to store whole stat buffer */
		if(nd <= n){
			convM2D(buf, n, d, (char*)&d[1]);
			return d;
		}
		/* else sizeof(Dir)+BIT16SZ+nd is plenty */
		free(d);
	}
	return nil;
}

int
_dirwstat(const char *name, Dir *d)
{
	unsigned char *buf;
	int r;

	r = sizeD2M(d);
	buf = malloc(r);
	if(buf == nil)
		return -1;
	convD2M(d, buf, r);
	r = wstat(name, buf, r);
	free(buf);
	return r;
}

Dir*
_dirfstat(int fd)
{
	Dir *d;
	unsigned char *buf;
	int n, nd, i;

	nd = DIRSIZE;
	for(i=0; i<2; i++){	/* should work by the second try */
		d = malloc(sizeof(Dir) + nd);
		if(d == nil)
			return nil;
		buf = (unsigned char*)&d[1];
		n = __sys_fstat(fd, buf, nd);
		if(n < BIT16SZ){
			free(d);
			return nil;
		}
		nd = GBIT16(buf);	/* size needed to store whole stat buffer */
		if(nd <= n){
			convM2D(buf, n, d, (char*)&d[1]);
			return d;
		}
		/* else sizeof(Dir)+nd is plenty */
		free(d);
	}
	return nil;
}

int
_dirfwstat(int fd, Dir *d)
{
	unsigned char *buf;
	int r;

	r = sizeD2M(d);
	buf = malloc(r);
	if(buf == nil)
		return -1;
	convD2M(d, buf, r);
	r = fwstat(fd, buf, r);
	free(buf);
	return r;
}

void
_nulldir(Dir *d)
{
	memset(d, ~0, sizeof(Dir));
	d->name = d->uid = d->gid = d->muid = "";
}
