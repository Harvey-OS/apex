/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __STDDEF_H
#define __STDDEF_H

#if defined (__STDDEF_H) || defined (__need_NULL)
#ifndef NULL		/* in case <stdio.h> has defined it. */
#ifdef __GNUG__
#define NULL __null
#else   /* G++ */
#ifndef __cplusplus
#define NULL ((void *)0)
#else   /* C++ */
#define NULL 0L
#endif  /* C++ */
#endif  /* G++ */
#endif	/* ifndef NULL */
#endif	/* NULL not defined and <stddef.h> or need NULL.  */
#undef	__need_NULL

#ifndef offsetof
#define offsetof(ty,mem) ((size_t) &(((ty *)0)->mem))
#endif

typedef long ptrdiff_t;
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long size_t;
#endif
#ifndef _WCHAR_T
#define _WCHAR_T
typedef int wchar_t;
#endif
#ifndef _MBSTATE_T
#define _MBSTATE_T
typedef int mbstate_t;
#endif
#ifndef _WINT_T
#define _WINT_T
typedef unsigned int	wint_t;
#endif
#ifndef _LOCALE_T
#define _LOCALE_T
typedef long locale_t;
#endif
#ifndef _WCTYPE_T
#define _WCTYPE_T
typedef int	wctype_t;
#endif
#ifndef _FLOAT_T
#define _FLOAT_T
typedef long double float_t;
#endif
#ifndef _DOUBLE_T
#define _DOUBLE_T
typedef long double double_t;
#endif

#endif /* __STDDEF_H */
