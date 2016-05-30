/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 Álvaro Jurado et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdint.h>
#include <string.h>

static inline unsigned long swapc(unsigned long x, int c)
{
	return c ? x>>24 | x>>8&0xff00 | x<<8&0xff0000 | x<<24 : x;
}

const char *__mo_lookup(const void *p, size_t size, const char *s)
{
	const unsigned long *mo = p;
	int sw = *mo - 0x950412de;
	unsigned long b = 0, n = swapc(mo[2], sw);
	unsigned long o = swapc(mo[3], sw);
	unsigned long t = swapc(mo[4], sw);
	if (n>=size/4 || o>=size-4*n || t>=size-4*n || ((o|t)%4))
		return 0;
	o/=4;
	t/=4;
	for (;;) {
		unsigned long ol = swapc(mo[o+2*(b+n/2)], sw);
		unsigned long os = swapc(mo[o+2*(b+n/2)+1], sw);
		if (os >= size || ol >= size-os || ((char *)p)[os+ol])
			return 0;
		int sign = strcmp(s, (char *)p + os);
		if (!sign) {
			unsigned long tl = swapc(mo[t+2*(b+n/2)], sw);
			unsigned long ts = swapc(mo[t+2*(b+n/2)+1], sw);
			if (ts >= size || tl >= size-ts || ((char *)p)[ts+tl])
				return 0;
			return (char *)p + ts;
		}
		else if (n == 1) return 0;
		else if (sign < 0)
			n /= 2;
		else {
			b += n/2;
			n -= n/2;
		}
	}
	return 0;
}
