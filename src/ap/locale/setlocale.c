/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
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
