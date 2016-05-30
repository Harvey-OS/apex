/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef	_STRINGS_H
#define	_STRINGS_H

#ifndef __STDDEF_H
#include <stddef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


#define __NEED_size_t
#define __NEED_locale_t

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
extern int bcmp (const void *, const void *, size_t);
extern void bcopy (const void *, void *, size_t);
extern void bzero (void *, size_t);
extern char *index (const char *, int);
extern char *rindex (const char *, int);
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
extern int ffs (int);
extern int ffsl (long);
extern int ffsll (long long);
#endif

extern int strcasecmp (const char *, const char *);
extern int strncasecmp (const char *, const char *, size_t);

extern int strcasecmp_l (const char *, const char *, locale_t);
extern int strncasecmp_l (const char *, const char *, size_t, locale_t);

#ifdef __cplusplus
}
#endif

#endif
