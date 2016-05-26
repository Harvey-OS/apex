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

#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "locale_impl.h"
#include "libc.h"

static char buf[LC_ALL*(LOCALE_NAME_MAX+1)];

static char *setlocale_one_unlocked(int cat, const char *name)
{
	const struct __locale_map *lm;

	if (name) lm = __get_locale(cat, name);
	else lm = 0;

	return lm ? (char *)lm->name : "C";
}

char *__strchrnul(const char *, int);

char *setlocale(int cat, const char *name)
{
	if ((unsigned)cat > LC_ALL) return 0;

	/* For LC_ALL, setlocale is required to return a string which
	 * encodes the current setting for all categories. The format of
	 * this string is unspecified, and only the following code, which
	 * performs both the serialization and deserialization, depends
	 * on the format, so it can easily be changed if needed. */
	if (cat == LC_ALL) {
		int i;
		if (name) {
			char part[LOCALE_NAME_MAX+1] = "C.UTF-8";
			const char *p = name;
			for (i=0; i<LC_ALL; i++) {
				const char *z = __strchrnul(p, ';');
				if (z-p <= LOCALE_NAME_MAX) {
					memcpy(part, p, z-p);
					part[z-p] = 0;
					if (*z) p = z+1;
				}
				setlocale_one_unlocked(i, part);
			}
		}
		char *s = buf;
		for (i=0; i<LC_ALL; i++) {
			const struct __locale_map *lm =
				0;
			const char *part = lm ? lm->name : "C";
			size_t l = strlen(part);
			memcpy(s, part, l);
			s[l] = ';';
			s += l+1;
		}
		*--s = 0;
		return buf;
	}

	char *ret = setlocale_one_unlocked(cat, name);

	return ret;
}
