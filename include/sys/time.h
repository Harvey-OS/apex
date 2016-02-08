/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __SYSTIME_H
#define __SYSTIME_H
#pragma lib "/$M/lib/ape/libap.a"

#include <sys/types.h>

#ifndef __TIMEVAL__
#define __TIMEVAL__
struct timeval {
	time_t	tv_sec;
	long int	tv_usec;
};

#ifdef _BSD_EXTENSION
struct timezone {
	int	tz_minuteswest;
	int	tz_dsttime;
};

extern int gettimeofday(struct timeval *, struct timezone *);

#endif
#endif /* __TIMEVAL__ */

#endif /* __SYSTIME_H */
