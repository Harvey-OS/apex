/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "locale_impl.h"
#include <stdint.h>

static const unsigned long empty_mo[] = { 0x950412de, 0, -1, -1, -1 };

const struct __locale_map __c_dot_utf8 = {
	.map = empty_mo,
	.map_size = sizeof empty_mo,
	.name = "C.UTF-8"
};

const struct __locale_struct __c_locale = { 0 };
const struct __locale_struct __c_dot_utf8_locale = {
	.cat[LC_CTYPE] = &__c_dot_utf8
};
