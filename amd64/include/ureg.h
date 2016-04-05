#ifndef __UREG_H
#define __UREG_H
#if !defined(_PLAN9_SOURCE)
    This header file is an extension to ANSI/POSIX
#endif

struct Ureg {
	uint64_t	ax;
	uint64_t	bx;
	uint64_t	cx;
	uint64_t	dx;
	uint64_t	si;
	uint64_t	di;
	uint64_t	bp;
	uint64_t	r8;
	uint64_t	r9;
	uint64_t	r10;
	uint64_t	r11;
	uint64_t	r12;
	uint64_t	r13;
	uint64_t	r14;
	uint64_t	r15;

	// these are pointless and I don't want to waste a second on them.
	// I'm sure it will break something but let's see.
	// Not pushing them simplifies the interrupt handler a lot.
	//	unsigned short	ds;
	//	unsigned short	es;
	//	unsigned short	fs;
	//	unsigned short	gs;

	uint64_t	type;
	uint64_t	error;		/* error code (or zero) */
	uint64_t	ip;		/* pc */
	uint64_t	cs;		/* old context */
	uint64_t	flags;		/* old flags */
	uint64_t	sp;		/* sp */
	uint64_t	ss;		/* old stack segment */
};

#endif
