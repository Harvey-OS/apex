/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __LIMITS
#define __LIMITS
/* 8 bit chars (signed), 16 bit shorts, 32 bit ints/longs */

#if '\0'-1 > 0
#define CHAR_MIN 0
#define CHAR_MAX 255
#else
#define CHAR_MIN (-128)
#define CHAR_MAX 127
#endif

/* Some universal constants... */

#define CHAR_BIT 8
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127
#define UCHAR_MAX 255
#define SHRT_MIN  (-1-0x7fff)
#define SHRT_MAX  0x7fff
#define USHRT_MAX 0xffff
#define INT_MIN  (-1-0x7fffffff)
#define INT_MAX  0x7fffffff
#define UINT_MAX 0xffffffffU
#define LONG_MIN (-LONG_MAX-1)
#define ULONG_MAX (2UL*LONG_MAX+1)
#define LLONG_MIN (-LLONG_MAX-1)
#define ULLONG_MAX (2ULL*LLONG_MAX+1)

#define MB_LEN_MAX 4

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

#define PIPE_BUF 8192
#ifdef PAGE_SIZE
#define PAGESIZE PAGE_SIZE
#endif
#define FILESIZEBITS 64
#define NAME_MAX 255
#define SYMLINK_MAX 255
//#define PATH_MAX 4096
#define NZERO 20
#define NGROUPS_MAX 32
#define ARG_MAX 131072
#define IOV_MAX 1024
#define SYMLOOP_MAX 40
#define WORD_BIT 32
#define SSIZE_MAX LONG_MAX
#define TZNAME_MAX 6
#define TTY_NAME_MAX 32
#define HOST_NAME_MAX 255

/* Implementation choices... */

#define PTHREAD_KEYS_MAX 128
#define PTHREAD_STACK_MIN 2048
#define PTHREAD_DESTRUCTOR_ITERATIONS 4
#define SEM_VALUE_MAX 0x7fffffff
#define SEM_NSEMS_MAX 256
#define DELAYTIMER_MAX 0x7fffffff
#define MQ_PRIO_MAX 32768
#define LOGIN_NAME_MAX 256

/* Arbitrary numbers... */

#define BC_BASE_MAX 99
#define BC_DIM_MAX 2048
#define BC_SCALE_MAX 99
#define BC_STRING_MAX 1000
#define CHARCLASS_NAME_MAX 14
#define COLL_WEIGHTS_MAX 2
#define EXPR_NEST_MAX 32
#define LINE_MAX 4096
#define RE_DUP_MAX 255

#define NL_ARGMAX 9
#define NL_LANGMAX 32
#define NL_MSGMAX 32767
#define NL_SETMAX 255
#define NL_TEXTMAX 2048

#define _POSIX_AIO_LISTIO_MAX	2
#define _POSIX_AIO_MAX			1
#define _POSIX_ARG_MAX			4096
#define _POSIX_CHILD_MAX		6
#define	_POSIX_CLOCKRES_MIN		20000000
#define	_POSIX_DELAYTIMER_MAX	32
#define _POSIX_LINK_MAX			8
#define _POSIX_MAX_CANON		255
#define _POSIX_MAX_INPUT		255
#define _POSIX_MQ_OPEN_MAX		8
#define	_POSIX_MQ_PRIO_MAX		32
#define _POSIX_NAME_MAX			14
#define _POSIX_NGROUPS_MAX		0
#define _POSIX_OPEN_MAX			16
#define _POSIX_PATH_MAX			255
#define _POSIX_PIPE_BUF			512
#define	_POSIX_RTSIG_MAX		8
#define	_POSIX_SEM_NSEMS_MAX	256
#define	_POSIX_SEM_VALUE_MAX	32767
#define	_POSIX_SIGQUEUE_MAX		32
#define _POSIX_SSIZE_MAX		32767
#define _POSIX_STREAM_MAX		8
#define	_POSIX_TIMER_MAX		32
#define _POSIX_TZNAME_MAX		3


/* pedagogy: those that standard allows omitting are commented out */
/*#define AIO_LIST_MAX _POSIX_AIO_LIST_MAX */
/*#define AIO_MAX _POSIX_AIO_MAX */
/*#define AIO_PRIO_DELTA_MAX 0 */
/*#define ARG_MAX _POSIX_ARG_MAX */
/*#define CHILD_MAX _POSIX_CHILD_MAX */
/*#define DELAYTIMER_MAX _POSIX_DELAYTIMER_MAX */
/*#define LINK_MAX _POSIX_LINK_MAX */
/*#define MAX_CANON _POSIX_MAX_CANON */
/*#define MAX_INPUT _POSIX_MAX_INPUT */
/*#define MQ_OPEN_MAX _POSIX_MQ_OPEN_MAX */
/*#define MQ_PRIO_MAX _POSIX_MQ_PRIO_MAX */
/*#define NAME_MAX _POSIX_NAME_MAX */
/*#define NGROUPS_MAX 10 */
/*#define NL_ARGMAX 9 */
/*#define OPEN_MAX _POSIX_OPEN_MAX */
/*#define PAGESIZE 1 */
#define PASS_MAX	64
/*#define PATH_MAX _POSIX_PATH_MAX */
/*#define PIPE_BUF _POSIX_PIPE_BUF */
/*#define RTSIG_MAX _POSIX_RTSIG_MAX */
/*#define SEM_NSEMS_MAX _POSIX_SEM_NSEMS_MAX */
/*#define SEM_VALUE_MAX _POSIX_SEM_VALUE_MAX */
/*#define SIGQUEUE_MAX _POSIX_SIGQUEUE_MAX */
/* #define SSIZE_MAX LONG_MAX */
/*#define STREAM_MAX _POSIX_STREAM_MAX */
/*#define TIMER_MAX _POSIX_TIMER_MAX */
/*#define TZNAME_MAX _POSIX_TZNAME_MAX*/

/* Bits from musl */
#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define LONG_BIT 64
#endif

#define LONG_MAX  0x7fffffffffffffffL

/* C99 */
/* Some universal constants... */
#define LLONG_MAX  0x7fffffffffffffffLL
#define LLONG_MIN (-LLONG_MAX-1)
#define ULLONG_MAX (2ULL*LLONG_MAX+1)

#ifdef _LIMITS_EXTENSION
/* some things are just too big for pedagogy (X!) */
#include <sys/limits.h>
#endif
#endif /* _POSIX_SOURCE */

#endif /* __LIMITS */
