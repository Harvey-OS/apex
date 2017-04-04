/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "lib.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include "sys9.h"

extern char **environ;

int
execve(const char *name, char *const argv[], char *const envp[])
{
	int n, f, i;
	char **e, *ss, *se;
	Fdinfo *fi;
	uint32_t flags;
	char buf[1024];

	rfork(RFCENVG);
	/*
	 * To pass _fdinfo[] across exec, put lines like
	 *   fd flags oflags
	 * in $_fdinfo (for open fd's)
	 */

	f = create("/env/_fdinfo", OWRITE, 0666);
	ss = buf;
	for(i = 0; i<OPEN_MAX; i++){
		if(i == f)
			continue;
		fi = &_fdinfo[i];
		flags = fi->flags;
		if(flags&FD_CLOEXEC){
			__sys_close(i);
			fi->flags = 0;
			fi->oflags = 0;
		}else if(flags&FD_ISOPEN){
			if(f < 0)
				continue;
			ss = _ultoa(ss, i);
			*ss++ = ' ';
			ss = _ultoa(ss, flags);
			*ss++ = ' ';
			ss = _ultoa(ss, fi->oflags);
			*ss++ = '\n';
			n = ss-buf;
			if(n > sizeof(buf)-50){
				if(__sys_write(f, buf, n) != n)
					break;
				ss = buf;
			}
		}
	}
	if(f >= 0){
		if(ss > buf)
			__sys_write(f, buf, ss-buf);
		__sys_close(f);
	}
	/*
	 * To pass _sighdlr[] across exec, set $_sighdlr
	 * to list of blank separated fd's that have
	 * SIG_IGN (the rest will be SIG_DFL).
	 * We write the variable, even if no signals
	 * are ignored, in case the current value of the
	 * variable ignored some.
	 */
	f = create("/env/_sighdlr", OWRITE, 0666);
	if(f >= 0){
		ss = buf;
		for(i = 0; i <=MAXSIG; i++) {
			if(_sighdlr[i] == SIG_IGN) {
				ss = _ultoa(ss, i);
				*ss++ = ' ';
				n = ss-buf;
				if(n > sizeof(buf)-20){
					if(__sys_write(f, buf, n) != n)
						break;
					ss = buf;
				}
			}
		}
		if(ss > buf)
			__sys_write(f, buf, ss-buf);
		__sys_close(f);
	}
	if(envp){
		for(e = (char **)envp; (ss = *e); e++) {
			se = strchr(ss, '=');
			if(!se || ss==se)
				continue;	/* what is name? value? */
			n = se-ss;
			if(n >= sizeof(buf)-5)
				continue;	/* name too long */
			strcpy(buf, "/env/");
			memcpy(buf+5, ss, n);
			buf[5+n] = 0;
			f = create(buf, OWRITE, 0666);
			if(f < 0)
				continue;
			ss = ++se;	/* past = */
			se += strlen(ss);
			while((n = (se - ss)) > 0){
				if(n > sizeof(buf))
					n = sizeof(buf);
				/* decode nulls (see _envsetup()) */
				for(i=0; i<n; i++)
					if((buf[i] = ss[i]) == 1)
						buf[i] = 0;
				if(__sys_write(f, buf, n) != n)
					break;
				ss += n;
			}
			__sys_close(f);
		}
	}
	n = exec(name, argv);
	_syserrno();
	return n;
}
