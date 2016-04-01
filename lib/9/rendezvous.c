/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <lib9.h>

extern	uint32_t	_RENDEZVOUS(uint32_t, uint32_t);

uint32_t
rendezvous(uint32_t tag, uint32_t value)
{
	return _RENDEZVOUS(tag, value);
}
