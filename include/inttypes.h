/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef _SUSV2_SOURCE
#error "inttypes.h is SUSV2"
#endif

#ifndef _INTTYPES_H_
#define _INTTYPES_H_ 1

typedef long _intptr_t;
typedef unsigned long  _uintptr_t;

typedef _intptr_t intptr_t;
typedef _uintptr_t uintptr_t;
typedef long	intmax_t;
typedef unsigned long	uintmax_t;

#endif
