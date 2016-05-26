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
#include "libc.h"
#include <wchar.h>

static size_t wstring_read(FILE *f, unsigned char *buf, size_t len)
{
	const wchar_t *src = f->cookie;
	size_t k;

	if (!src) return 0;

	k = wcsrtombs((void *)f->buf, &src, f->buf_size, 0);
	if (k==(size_t)-1) {
		f->rpos = f->rend = 0;
		return 0;
	}

	f->rpos = f->buf;
	f->rend = f->buf + k;
	f->cookie = (void *)src;

	if (!len || !k) return 0;

	*buf = *f->rpos++;
	return 1;
}

int vswscanf(const wchar_t *restrict s, const wchar_t *restrict fmt, va_list ap)
{
	unsigned char buf[256];
	FILE f = {
		.buf = buf, .buf_size = sizeof buf,
		.cookie = (void *)s,
		.read = wstring_read, .lock = -1
	};
	return vfwscanf(&f, fmt, ap);
}

weak_alias(vswscanf,__isoc99_vswscanf);
