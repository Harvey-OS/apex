#ifndef __STDARG
#define __STDARG
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
typedef va_list __isoc_va_list; /* wchar.h */

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#define va_copy(v,l)	__builtin_va_copy(v,l)

#endif /* __STDARG */
