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

#include "shgetc.h"

void __shlim(FILE *f, off_t lim)
{
	f->shlim = lim;
	f->shcnt = f->rend - f->rpos;
	if (lim && f->shcnt > lim)
		f->shend = f->rpos + lim;
	else
		f->shend = f->rend;
}

int __shgetc(FILE *f)
{
	int c;
	if (f->shlim && f->shcnt >= f->shlim || (c=__uflow(f)) < 0) {
		f->shend = 0;
		return EOF;
	}
	if (f->shlim && f->rend - f->rpos > f->shlim - f->shcnt - 1)
		f->shend = f->rpos + (f->shlim - f->shcnt - 1);
	else
		f->shend = f->rend;
	if (f->rend) f->shcnt += f->rend - f->rpos + 1;
	if (f->rpos[-1] != c) f->rpos[-1] = c;
	return c;
}
