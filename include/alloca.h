/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef	_ALLOCA_H
#define	_ALLOCA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

extern void *alloca(size_t);

#ifdef __GNUC__
#define alloca __builtin_alloca
#endif

#ifdef __cplusplus
}
#endif

#endif
