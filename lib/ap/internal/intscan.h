/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef INTSCAN_H
#define INTSCAN_H

#ifndef __C99
#define __C99
#endif

#include <stdio.h>

unsigned long long __intscan(FILE *, unsigned, int, unsigned long long);

#endif
