/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <sys/pty.h>
#include "lib.h"
#include "sys9.h"
#include "dir.h"

/*
 * return the name of the slave
 */
char*
ptsname(int fd)
{
	Dir *d;
	static char buf[32];

	if((d = _dirfstat(fd)) == nil || strlen(d->name) < 4){
		free(d);
		_syserrno();
		return 0;
	}
	snprintf(buf, sizeof buf, "/dev/ptty%d", atoi(d->name+4));
	free(d);
	return buf;
}

/*
 * return the name of the master
 */
char*
ptmname(int fd)
{
	Dir *d;
	static char buf[32];

	if((d = _dirfstat(fd)) == nil || strlen(d->name) < 4){
		free(d);
		_syserrno();
		return 0;
	}

	snprintf(buf, sizeof buf, "/dev/ttym%d", atoi(d->name+4));
	return buf;
}

static char ptycl[] = "/dev/ptyclone";
static char fssrv[] = "/srv/ptyfs";

static void
mkserver(void)
{
	int fd, i;
	char * const argv[3]={"ptyfs", 0};

	fd = open(fssrv, O_RDWR);
	if(_mount(fd, -1, "/dev", MAFTER, "") < 0) {
		/*
		 * remove fssrv here, if it exists, to avoid a race
		 * between the loop in the default case below and the
		 * new ptyfs removing fssrv when it starts.
		 * we otherwise might be unlucky enough to open the old
		 * (hung channel) fssrv before ptyfs removes it and break
		 * out of the loop with an open fd to a hung channel?
		 */
		close(fd);
		remove(fssrv);
		switch(rfork(RFPROC|RFFDG)) {
		case -1:
			return;
		case 0:
			exec("/bin/ape/ptyfs", argv);
			exits(0);
		default:
			for(i = 0; i < 3; i++) {
				fd = open(fssrv, O_RDWR);
				if(fd >= 0)
					break;
				sleep(1000);
			}
		}
		if(fd < 0)
			return;
		if(_mount(fd, -1, "/dev", MAFTER, "") < 0)
			close(fd);
	}
	/* successful _MOUNT closes fd */
}

/*
 * allocate a new pty
 */
int
_getpty(void)
{
	struct stat sb;

	if(stat(ptycl, &sb) < 0)
		mkserver();

	return open(ptycl, O_RDWR);
}
