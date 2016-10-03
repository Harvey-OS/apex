/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/* bsd extensions */
#include <sys/uio.h>
#include <sys/socket.h>

#include "priv.h"

ssize_t
writev(int fd, const struct iovec *iov, int iovcnt)
{
	ssize_t tot = 0;
	int i, n;
	char *buf, *t, *e, *f;

	for(i = 0; i < iovcnt; ++i)
		tot += iov[i].iov_len;
	buf = malloc(tot);

	t = buf;
	e = buf+sizeof(buf);
	for(;iovcnt ; iov++, iovcnt--){
		n = iov->iov_len;
		f = iov->iov_base;
		while(n > 0){
			i = e-t;
			if(n < i){
				memmove(t, f, n);
				t += n;
				break;
			}
			memmove(t, f, i);
			n -= i;
			f += i;
			i = write(fd, buf, sizeof(buf));
			if(i < 0){
				if(tot > 0){
					return tot;
				}else{
					_syserrno();
					return -1;
				}
			}
			tot += i;
			if(i != sizeof(buf)) {
				return tot;
			}
			t = buf;
		}
	}
	i = t - buf;
	if(i > 0){
		n = write(fd, buf, i);
		if(n < 0){
			if(tot == 0){
				_syserrno();
				return -1;
			}
		} else
			tot += n;
	}
	free(buf);
	return tot;
}
