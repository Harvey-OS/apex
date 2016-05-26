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
#include "locale_impl.h"
#include <wchar.h>
#include <errno.h>

static wint_t __fgetwc_unlocked_internal(FILE *f)
{
	mbstate_t st = { 0 };
	wchar_t wc;
	int c;
	unsigned char b;
	size_t l;

	/* Convert character from buffer if possible */
	if (f->rpos < f->rend) {
		l = mbrtowc(&wc, (void *)f->rpos, f->rend - f->rpos, &st);
		if (l+2 >= 2) {
			f->rpos += l + !l; /* l==0 means 1 byte, null */
			return wc;
		}
		if (l == -1) {
			f->rpos++;
			return WEOF;
		}
	} else l = -2;

	/* Convert character byte-by-byte */
	while (l == -2) {
		b = c = getc_unlocked(f);
		if (c < 0) {
			if (!mbsinit(&st)) errno = EILSEQ;
			return WEOF;
		}
		l = mbrtowc(&wc, (void *)&b, 1, &st);
		if (l == -1) return WEOF;
	}

	return wc;
}

wint_t __fgetwc_unlocked(FILE *f)
{
	if (f->mode <= 0) fwide(f, 1);
	wchar_t wc = __fgetwc_unlocked_internal(f);
	return wc;
}

wint_t fgetwc(FILE *f)
{
	wint_t c;
	FLOCK(f);
	c = __fgetwc_unlocked(f);
	FUNLOCK(f);
	return c;
}

weak_alias(__fgetwc_unlocked, fgetwc_unlocked);
weak_alias(__fgetwc_unlocked, getwc_unlocked);
