/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <sys/stat.h> /* for dirtostat */
#include <stdint.h> /* for types */

#define	GBIT8(p)	((p)[0])
#define	GBIT16(p)	((p)[0]|((p)[1]<<8))
#define	GBIT32(p)	((p)[0]|((p)[1]<<8)|((p)[2]<<16)|((p)[3]<<24))
#define	GBIT64(p)	((int64_t)((p)[0]|((p)[1]<<8)|((p)[2]<<16)|((p)[3]<<24)) |\
				((int64_t)((p)[4]|((p)[5]<<8)|((p)[6]<<16)|((p)[7]<<24)) << 32))

#define	PBIT8(p,v)	(p)[0]=(v)
#define	PBIT16(p,v)	(p)[0]=(v);(p)[1]=(v)>>8
#define	PBIT32(p,v)	(p)[0]=(v);(p)[1]=(v)>>8;(p)[2]=(v)>>16;(p)[3]=(v)>>24
#define	PBIT64(p,v)	(p)[0]=(v);(p)[1]=(v)>>8;(p)[2]=(v)>>16;(p)[3]=(v)>>24;\
			(p)[4]=(v)>>32;(p)[5]=(v)>>40;(p)[6]=(v)>>48;(p)[7]=(v)>>56

#define	BIT8SZ		1
#define	BIT16SZ		2
#define	BIT32SZ		4
#define	BIT64SZ		8
#define	QIDSZ	(BIT8SZ+BIT32SZ+BIT64SZ)

/* STATFIXLEN includes leading 16-bit count */
/* The count, however, excludes itself; total size is BIT16SZ+count */
#define STATFIXLEN	(BIT16SZ+QIDSZ+5*BIT16SZ+4*BIT32SZ+1*BIT64SZ)	/* amount of fixed length data in a stat buffer */

typedef union
{
	char	clength[8];
	int64_t	vlength;
	struct
	{
		int32_t	hlength;
		int32_t	length;
	};
} Length;

typedef
struct Qid
{
	uint64_t	path;
	uint32_t	vers;
	unsigned char	type;
} Qid;

typedef
struct Dir {
	/* system-modified data */
	uint16_t	type;	/* server type */
	uint32_t	dev;	/* server subtype */
	/* file data */
	Qid	qid;	/* unique id from server */
	uint32_t	mode;	/* permissions */
	uint32_t	atime;	/* last read time */
	uint32_t	mtime;	/* last write time */
	int64_t	length;	/* file length: see <u.h> */
	char	*name;	/* last element of path */
	char	*uid;	/* owner name */
	char	*gid;	/* group name */
	char	*muid;	/* last modifier name */
} Dir;

void	dirtostat(struct stat *, Dir*, Fdinfo*);
uint32_t	convM2D(unsigned char*, uint32_t, Dir*, char*);
uint32_t	convD2M(Dir*, unsigned char*, uint32_t);
Dir	*_dirstat(const char*);
int	_dirwstat(const char*, Dir*);
Dir	*_dirfstat(int);
int	_dirfwstat(int, Dir*);
int32_t	_dirread(int, Dir**);
int32_t _dirreadall(int, Dir**);
void _nulldir(Dir*);
uint32_t sizeD2M(Dir*);

#ifndef nil
#define nil ((void*)0)
#endif
