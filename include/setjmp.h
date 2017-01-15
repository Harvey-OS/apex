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
#include <stdint.h>
/*
 * jmp_buf contains the following:
 * rbx - 1 uintptr_t
 * r12 to r15 - 4 uintptr_t
 * rbp - 1 uintptr_t
 * rsp - 1 uintptr_t
 * return address - 1 uintptr_t
 * 2 function arguments - 2 uintptr_t
 * total = 10 uintptr_t
 */

typedef uintptr_t jmp_buf[10];
#ifdef _POSIX_SOURCE
typedef uintptr_t sigjmp_buf[10];
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
