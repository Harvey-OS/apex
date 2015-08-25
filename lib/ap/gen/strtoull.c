/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define UVLONG_MAX	(1LL<<63)

unsigned long long
strtoull(const char *nptr, char **endptr, int base)
{
	unsigned long long n, nn, m;
	int c, ovfl, v, neg, ndig;

	neg = 0;
	n = 0;
	ndig = 0;
	ovfl = 0;

	/*
	 * White space
	 */
	for(;; nptr++) {
		switch(*nptr) {
		case ' ':
		case '\t':
		case '\n':
		case '\f':
		case '\r':
		case '\v':
			continue;
		}
		break;
	}

	/*
	 * Sign
	 */
	if(*nptr == '-' || *nptr == '+')
		if(*nptr++ == '-')
			neg = 1;

	/*
	 * Base
	 */
	if(base == 0) {
		base = 10;
		if(*nptr == '0') {
			base = 8;
			if(nptr[1] == 'x' || nptr[1] == 'X'){
				nptr += 2;
				base = 16;
			}
		}
	} else
	if(base == 16 && *nptr == '0') {
		if(nptr[1] == 'x' || nptr[1] == 'X')
			nptr += 2;
	} else
	if(base < 0 || 36 < base)
		goto Return;

	/*
	 * Non-empty sequence of digits
	 */
	m = UVLONG_MAX/base;
	for(;; nptr++,ndig++) {
		c = *nptr;
		v = base;
		if('0' <= c && c <= '9')
			v = c - '0';
		else
		if('a' <= c && c <= 'z')
			v = c - 'a' + 10;
		else
		if('A' <= c && c <= 'Z')
			v = c - 'A' + 10;
		if(v >= base)
			break;
		if(n > m)
			ovfl = 1;
		nn = n*base + v;
		if(nn < n)
			ovfl = 1;
		n = nn;
	}

Return:
	if(ovfl){
		errno = ERANGE;
		return UVLONG_MAX;
	}
	if(neg)
		return -n;
	return n;
}
