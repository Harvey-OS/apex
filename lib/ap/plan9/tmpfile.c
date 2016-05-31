/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "stdio_impl.h"
#include <unistd.h>
#include <string.h>
#include "sys9.h"
#include "lib.h"
#include "dir.h"

FILE *
tmpfile(void){
	FILE *f;
	static char name[]="/tmp/tf0000000000000";
	char *p;
	int n;

	while(access(name, 0) >= 0){
		p = name+7;
		while(*p == '9')
			*p++ = '0';
		if(*p == '\0')
			return NULL;
		++*p;
	}
	n = create(name, 64|2, 0777); /* remove-on-close */
	if(n==-1){
		_syserrno();
		return NULL;
	}
	_fdinfo[n].flags = FD_ISOPEN;
	_fdinfo[n].oflags = 2;

	f = fdopen(n, "w+");
    if (!f) close(n);

	return f;
}
