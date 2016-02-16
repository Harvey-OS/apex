/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef _BSD_EXTENSION
    This header file is an extension to ANSI/POSIX
#endif

#ifndef __BSD_H_
#define __BSD_H_

#include <sys/types.h>
#include <string.h>
#include <strings.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;
#endif

extern void	bhappy(void*);
extern int	rresvport(int*);
extern int	rcmd(char**, int, char*, char*, char*, int*);
extern int 	putenv(char*);

extern int	getopt(int, char* const*, const char*);
extern int	opterr;
extern int	optind;
extern int	optopt;
extern char	*optarg;
extern char	*mktemp(char *);
extern char	*sys_errlist[];
extern int		sys_nerr;

#ifdef __cplusplus
}
#endif

#endif
