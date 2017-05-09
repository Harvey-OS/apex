/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <signal.h>
#include <errno.h>
#include "lib.h"

sigset_t _psigblocked;

int
sigprocmask(int how, const sigset_t *set, sigset_t *oset)
{
	if(oset)
		*oset = _psigblocked;

	switch(how)
	{
		case SIG_BLOCK:
			_psigblocked |= *set;
			break;
		case SIG_UNBLOCK:
			_psigblocked &= ~*set;
			break;
		case SIG_SETMASK:
			_psigblocked = *set;
			break;
		default:
			errno = EINVAL;
			return -1;
	}

	return 0;
}
