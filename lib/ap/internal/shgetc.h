/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

void __shlim(FILE *, off_t);
int __shgetc(FILE *);

#define shcnt(f) ((f)->shcnt + ((f)->rpos - (f)->rend))
#define shlim(f, lim) __shlim((f), (lim))
#define shgetc(f) (((f)->rpos < (f)->shend) ? *(f)->rpos++ : __shgetc(f))
#define shunget(f) ((f)->shend ? (void)(f)->rpos-- : (void)0)
