/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __SETJMP_H
#define __SETJMP_H
/*
 * jmp_buf contains the following:
 * rbx - 8 bytes
 * r12 to r15 - 24 bytes
 * rbp - 8 bytes
 * rsp - 8 bytes
 * return address - 8 bytes
 * 2 function arguments - 16 bytes
 * total = 72 bytes
 */

typedef unsigned char jmp_buf[72];
#ifdef _POSIX_SOURCE
typedef unsigned char sigjmp_buf[72];
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int);

#ifdef _POSIX_SOURCE
extern int sigsetjmp(sigjmp_buf, int);
extern void siglongjmp(sigjmp_buf, int);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __SETJMP_H */
