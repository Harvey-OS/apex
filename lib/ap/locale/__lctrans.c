#include <locale.h>
#include <string.h>
#include <errno.h>
#include "locale_impl.h"
#include "libc.h"

extern const char *__lctrans_impl(const char*, const struct __locale_map*);

const char *__lctrans(const char *msg, const struct __locale_map *lm)
{
	return __lctrans_impl(msg, lm);
}

const char *__lctrans_cur(const char *msg)
{
	return __lctrans_impl(msg, 0);
}
