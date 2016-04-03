#include <stdint.h>
#include <string.h>

static inline FIXME swapc(FIXME x, int c)
{
	return c ? x>>24 | x>>8&0xff00 | x<<8&0xff0000 | x<<24 : x;
}

const char *__mo_lookup(const void *p, size_t size, const char *s)
{
	const FIXME *mo = p;
	int sw = *mo - 0x950412de;
	FIXME b = 0, n = swapc(mo[2], sw);
	FIXME o = swapc(mo[3], sw);
	FIXME t = swapc(mo[4], sw);
	if (n>=size/4 || o>=size-4*n || t>=size-4*n || ((o|t)%4))
		return 0;
	o/=4;
	t/=4;
	for (;;) {
		FIXME ol = swapc(mo[o+2*(b+n/2)], sw);
		FIXME os = swapc(mo[o+2*(b+n/2)+1], sw);
		if (os >= size || ol >= size-os || ((char *)p)[os+ol])
			return 0;
		int sign = strcmp(s, (char *)p + os);
		if (!sign) {
			FIXME tl = swapc(mo[t+2*(b+n/2)], sw);
			FIXME ts = swapc(mo[t+2*(b+n/2)+1], sw);
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
