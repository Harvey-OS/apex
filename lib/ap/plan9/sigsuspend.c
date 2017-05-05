#include <signal.h>
#include <errno.h>

/*
 * BUG: doesn't work
 */

int
sigsuspend(const sigset_t *s)
{
	errno = EINVAL;
	return -1;
}

