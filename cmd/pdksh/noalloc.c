/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

/*
 * area-based allocation built on malloc/free
 */

#include "sh.h"


/* create empty Area */
Area *
ainit(  Area *ap)
{
	return ap;
}

/* free all object in Area */
void
afreeall(  Area *ap)
{
}

/* allocate object from Area */
void *
alloc( size_t size,  Area *ap)
{
	return malloc(size);
}

/* change size of object -- like realloc */
void *
aresize(  void *ptr, size_t size, Area *ap)
{
	return realloc(ptr, size);
}

void
afree( void *ptr, Area *ap)
{
	free(ptr);
}

void
acheck( Area *ap)
{
}

void
aprint( Area *ap, void *ptr, size_t size)
{
}
