/*
 * Copyright © 2005-2014 Rich Felker, et al.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "stdio_impl.h"
//#include "pthread_impl.h"

int __lockfile(FILE *f)
{
	//int owner, tid = __pthread_self()->tid;
	//if (f->lock == tid)
	//while ((owner = a_cas(&f->lock, 0, tid)))
	//	__wait(&f->lock, &f->waiters, owner, 1);
	f->lock = 1;
	return 0;
}

void __unlockfile(FILE *f)
{
	//a_store(&f->lock, 0);

	/* The following read is technically invalid under situations
	 * of self-synchronized destruction. Another thread may have
	 * called fclose as soon as the above store has completed.
	 * Nonetheless, since FILE objects always live in memory
	 * obtained by malloc from the heap, it's safe to assume
	 * the dereferences below will not fault. In the worst case,
	 * a spurious syscall will be made. If the implementation of
	 * malloc changes, this assumption needs revisiting. */

	//if (f->waiters) __wake(&f->lock, 1, 1);
	f->lock = 0;
}
