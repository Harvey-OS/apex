#ifndef __UREG_H
#define __UREG_H
#if !defined(_PLAN9_SOURCE)
    This header file is an extension to ANSI/POSIX
#endif

struct Ureg {
	FIXMDE	ax;
	FIXMDE	bx;
	FIXMDE	cx;
	FIXMDE	dx;
	FIXMDE	si;
	FIXMDE	di;
	FIXMDE	bp;
	FIXMDE	r8;
	FIXMDE	r9;
	FIXMDE	r10;
	FIXMDE	r11;
	FIXMDE	r12;
	FIXMDE	r13;
	FIXMDE	r14;
	FIXMDE	r15;

	// these are pointless and I don't want to waste a second on them.
	// I'm sure it will break something but let's see.
	// Not pushing them simplifies the interrupt handler a lot.
	//	unsigned short	ds;
	//	unsigned short	es;
	//	unsigned short	fs;
	//	unsigned short	gs;

	FIXMDE	type;
	FIXMDE	error;		/* error code (or zero) */
	FIXMDE	ip;		/* pc */
	FIXMDE	cs;		/* old context */
	FIXMDE	flags;		/* old flags */
	FIXMDE	sp;		/* sp */
	FIXMDE	ss;		/* old stack segment */
};

#endif
