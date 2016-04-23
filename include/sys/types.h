/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __TYPES_H
#define __TYPES_H

typedef	unsigned short	ino_t;
typedef	unsigned short	dev_t;
typedef	long long		off_t;
typedef unsigned short	mode_t;
typedef short		uid_t;
typedef short		gid_t;
typedef short		nlink_t;
typedef int		pid_t;

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;
#endif
#ifndef _SSIZE_T
#define _SSIZE_T
typedef long ssize_t;
#endif

#ifndef _TIME_T
#define _TIME_T
typedef long int time_t;
#endif

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long int clock_t;
#endif

#ifndef __TIMEVAL__
#define __TIMEVAL__
struct timeval {
	time_t	tv_sec;
	long int	tv_usec;
};
#endif

#ifndef __TIMESPEC__
#define __TIMESPEC__
struct timespec {
	time_t tv_sec;
	long tv_nsec;
};
#endif

#ifdef _BSD_EXTENSION
struct timezone {
	int	tz_minuteswest;
	int	tz_dsttime;
};

#ifndef _CADDR_T
#define _CADDR_T
typedef char * caddr_t;
#endif
#endif

#endif /* __TYPES_H */
