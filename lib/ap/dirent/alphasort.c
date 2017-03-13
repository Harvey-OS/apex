/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <string.h>
#include <dirent.h>
#include "libc.h"

int alphasort(const struct dirent **a, const struct dirent **b)
{
	return strcoll((*a)->d_name, (*b)->d_name);
}

LFS64(alphasort);
