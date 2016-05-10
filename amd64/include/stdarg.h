#ifndef _STDARG_H
#define _STDARG_H


#ifdef __cplusplus
extern "C" {
#endif

/*
typedef char *va_list;

#define va_start(list, start) list = (sizeof(start)<8 ? (char *)((long long *)&(start)+1) : \
(char *)(&(start)+1))
#define va_end(list)
#define va_arg(list, mode)\
	((sizeof(mode) == 1)?\
		((mode*)(list += 8))[-8]:\
	(sizeof(mode) == 2)?\
		((mode*)(list += 8))[-4]:\
	(sizeof(mode) == 4)?\
		((mode*)(list += 8))[-2]:\
		((mode*)(list += sizeof(mode)))[-1])
*/

typedef __builtin_va_list va_list;
typedef __builtin_va_list __isoc_va_list; /* wchar.h */

#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)

#ifdef __cplusplus
}
#endif

#endif