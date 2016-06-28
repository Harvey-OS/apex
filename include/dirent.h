/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef	__DIRENT_H
#define	__DIRENT_H
/*
 * this must be a power of 2 and a multiple of all the ones in the system
 */
#define MAXNAMLEN 255

#include <sys/types.h>

typedef size_t d_ino;

struct	dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char	d_name[MAXNAMLEN + 1];
};

typedef struct _dirdesc {
	int	dd_fd;		/* file descriptor */
	long	dd_loc;		/* buf offset of entry from last readdir() */
	long	dd_size;	/* amount of valid data in buffer */
	char	*dd_buf;	/* directory data buffer */
	void *dirs;
	int	dirsize;
	int	dirloc;
	volatile int lock[2];
} DIR;


#ifdef __cplusplus
extern "C" {
#endif

/*
 * functions defined on directories
 */
DIR		*opendir(const char *);
struct dirent	*readdir(DIR *);
int            readdir_r(DIR *__restrict, struct dirent *__restrict, struct dirent **__restrict);
void		rewinddir(DIR *);
int		closedir(DIR *);

#ifdef __cplusplus
}
#endif

#endif
