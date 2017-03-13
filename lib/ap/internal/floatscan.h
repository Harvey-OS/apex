/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef FLOATSCAN_H
#define FLOATSCAN_H

#include <stdio.h>

long double __floatscan(FILE *, int, int);

#endif
