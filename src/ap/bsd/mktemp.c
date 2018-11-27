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
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>

char*
mktemp(char *template)
{
	int n;
	long x;
	char *p;
	int c;
	struct stat stbuf;

	n = strlen(template);
	p = template+n-6;
	if (n < 6 || strcmp(p, "XXXXXX") != 0) {
		*template = 0;
	} else {
		x = getpid() % 100000;
		sprintf(p, "%05d", x);
		p += 5;
		for(c = 'a'; c <= 'z'; c++) {
			*p = c;
			if (stat(template, &stbuf) < 0)
				return template;
		}
		*template = 0;
	}
	return template;
}

/*
 * Replacement for a missing mkstemp.
 *
 * Provides the same functionality as the library function mkstemp for those
 * systems that don't have it.
 *
 * The canonical version of this file is maintained in the rra-c-util package,
 * which can be found at <http://www.eyrie.org/~eagle/software/rra-c-util/>.
 *
 * Written by Russ Allbery <rra@stanford.edu>
 *
 * The authors hereby relinquish any claim to any copyright that they may have
 * in this work, whether granted under contract or by operation of law or
 * international treaty, and hereby commit to the public, at large, that they
 * shall not, at any time in the future, seek to enforce any copyright in this
 * work against any person or entity, or prevent any person or entity from
 * copying, publishing, distributing or creating derivative works of this
 * work.
 */

/*
 * If we're running the test suite, rename mkstemp to avoid conflicts with the
 * system version.  #undef it first because some systems may define it to
 * another name.
 */

int
mkstemp(char *template)
{
    static const char letters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    size_t length;
    char *XXXXXX;
    struct timeval tv;
    unsigned long long randnum, working;
    int i, tries, fd;

    /*
     * Make sure we have a valid template and initialize p to point at the
     * beginning of the template portion of the string.
     */
    length = strlen(template);
    if (length < 6) {
        errno = EINVAL;
        return -1;
    }
    XXXXXX = template + length - 6;
    if (strcmp(XXXXXX, "XXXXXX") != 0) {
        errno = EINVAL;
        return -1;
    }

    /* Get some more-or-less random information. */
    gettimeofday(&tv, NULL);
    randnum = ((unsigned long long) tv.tv_usec << 16) ^ tv.tv_sec ^ getpid();

    /*
     * Now, try to find a working file name.  We try no more than TMP_MAX file
     * names.
     */
    for (tries = 0; tries < TMP_MAX; tries++) {
        for (working = randnum, i = 0; i < 6; i++) {
            XXXXXX[i] = letters[working % 62];
            working /= 62;
        }
        fd = open(template, O_RDWR | O_CREAT | O_EXCL, 0600);
        if (fd >= 0 || (errno != EEXIST && errno != EISDIR))
            return fd;

        /*
         * This is a relatively random increment.  Cut off the tail end of
         * tv_usec since it's often predictable.
         */
        randnum += (tv.tv_usec >> 10) & 0xfff;
    }
    errno = EEXIST;
    return -1;
}
