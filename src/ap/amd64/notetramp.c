#include <signal.h>
#include <setjmp.h>
#include "lib.h"
#include "sys9.h"

/* A stack to hold pcs when signals nest */
#define MAXSIGSTACK 20
typedef struct Pcstack Pcstack;
static struct Pcstack {
	int sig;
	void (*hdlr)(int, char*, Ureg*);
	uint64_t restorepc;
	Ureg *u;
} pcstack[MAXSIGSTACK];
static int nstack = 0;

static void notecont(Ureg*, char*);

void
_notetramp(int sig, void (*hdlr)(int, char*, Ureg*), Ureg *u)
{
	Pcstack *p;

	if(nstack >= MAXSIGSTACK)
		noted(NDFLT);	/* nesting too deep; just do system default */
	p = &pcstack[nstack];
	p->restorepc = u->ip;
	p->sig = sig;
	p->hdlr = hdlr;
	p->u = u;
	nstack++;
	u->ip = (uint64_t) notecont;
	noted(NSAVE);	/* clear note but hold state */
}

static void
notecont(Ureg *u, char *s)
{
	Pcstack *p;
	void(*f)(int, char*, Ureg*);

	p = &pcstack[nstack-1];
	f = p->hdlr;
	u->ip = p->restorepc;
	nstack--;
	(*f)(p->sig, s, u);
	noted(NRSTR);
}

#define JMPBUFPC 1
#define JMPBUFSP 0

extern sigset_t	_psigblocked;

void
siglongjmp(sigjmp_buf j, int ret)
{
	struct Ureg *u;

	if(j[0])
		_psigblocked = j[1];
	if(nstack == 0 || pcstack[nstack-1].u->sp > j[2+JMPBUFSP])
		longjmp(j+2, ret);
	u = pcstack[nstack-1].u;
	nstack--;
	u->ax = ret;
	if(ret == 0)
		u->ax = 1;
	u->ip = j[2+JMPBUFPC];
	u->sp = j[2+JMPBUFSP] + 8;
	noted(NRSTR);
}
