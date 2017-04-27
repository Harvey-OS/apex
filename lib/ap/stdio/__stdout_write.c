/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include <sys/ioctl.h>

/*
 * In original, it was calling ioctl for checking TIOCGWINSZ
 * Harvey hasn't any implementation of terminal devices in that way.
 * The purpose is checking if there is any data and proper flags,
 * and then setting f->lbf to -1 for sending it to stdio_write.
 * FIONREAD is the only one ioctl emulation for Harvey due to sockets
 * implementation in lib/ap/bsd.
 */
static int dummy(FILE *f)
{
	if (ioctl(f->fd, FIONREAD, &f->buf_size) == 0)
		return 0;
	return -1;

}

size_t __stdout_write(FILE *f, const unsigned char *buf, size_t len)
{
	//struct winsize wsz;
	f->write = __stdio_write;
	if (!(f->flags & F_SVB) && dummy(f))
		f->lbf = -1;
	return __stdio_write(f, buf, len);
}
