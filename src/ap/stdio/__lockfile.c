/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include <sys/wait.h>
//#include "pthread_impl.h"

/* Crappy, awaiting pthreads implementation */

int __lockfile(FILE *f)
{
	//ORIG
	//int owner, tid = __pthread_self()->tid;
	//if (f->lock == tid)
	//while ((owner = a_cas(&f->lock, 0, tid)))
	//	__wait(&f->lock, &f->waiters, owner, 1);
	//return 1;
	pid_t pid = getpid();
	if (f->lock == pid)
		return 0;
	else
		f->waiters = 1;
	return 1;
}

void __unlockfile(FILE *f)
{
	//a_store(&f->lock, 0);
	f->lock = 0;

	/* The following read is technically invalid under situations
	 * of self-synchronized destruction. Another thread may have
	 * called fclose as soon as the above store has completed.
	 * Nonetheless, since FILE objects always live in memory
	 * obtained by malloc from the heap, it's safe to assume
	 * the dereferences below will not fault. In the worst case,
	 * a spurious syscall will be made. If the implementation of
	 * malloc changes, this assumption needs revisiting. */

	//if (f->waiters) __wake(&f->lock, 1, 1);
	if (f->waiters)
		f->lock = 1;
}
