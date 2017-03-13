/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include "libc.h"

static FILE *ofl_head;
//static volatile int ofl_lock[2];

FILE **__ofl_lock()
{
	//LOCK(ofl_lock);
	return &ofl_head;
}

void __ofl_unlock()
{
	//UNLOCK(ofl_lock);
}
