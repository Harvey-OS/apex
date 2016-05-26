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
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

static size_t sn_write(FILE *f, const unsigned char *s, size_t l)
{
	size_t k = f->wend - f->wpos;
	if (k > l) k = l;
	memcpy(f->wpos, s, k);
	f->wpos += k;
	/* pretend to succeed, but discard extra data */
	return l;
}

int vsnprintf(char *restrict s, size_t n, const char *restrict fmt, va_list ap)
{
	int r;
	char b;
	FILE f = { .lbf = EOF, .write = sn_write, .lock = -1 };

	if (n-1 > INT_MAX-1) {
		if (n) {
			errno = EOVERFLOW;
			return -1;
		}
		s = &b;
		n = 1;
	}

	/* Ensure pointers don't wrap if "infinite" n is passed in */
	if (n > (char *)0+SIZE_MAX-s-1) n = (char *)0+SIZE_MAX-s-1;
	f.buf_size = n;
	f.buf = f.wpos = (void *)s;
	f.wbase = f.wend = (void *)(s+n);
	r = vfprintf(&f, fmt, ap);

	/* Null-terminate, overwriting last char if dest buffer is full */
	if (n) f.wpos[-(f.wpos == f.wend)] = 0;
	return r;
}
