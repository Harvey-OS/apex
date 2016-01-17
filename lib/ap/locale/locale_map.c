#include <locale.h>
#include <string.h>
#include <errno.h>
#include "locale_impl.h"
#include "libc.h"

const char *__lctrans_impl(const char *msg, const struct __locale_map *lm)
{
	const char *trans = 0;
	if (lm) trans = __mo_lookup(lm->map, lm->map_size, msg);
	return trans ? trans : msg;
}

const unsigned char *__map_file(const char *, size_t *);
int __munmap(void *, size_t);
char *__strchrnul(const char *, int);

static const char envvars[][12] = {
	"LC_CTYPE",
	"LC_NUMERIC",
	"LC_TIME",
	"LC_COLLATE",
	"LC_MONETARY",
	"LC_MESSAGES",
};

const struct __locale_map *__get_locale(int cat, const char *val)
{

	struct __locale_map *new = 0;
	size_t n;

	if (!*val) {
		(val = getenv("LC_ALL")) && *val ||
		(val = getenv(envvars[cat])) && *val ||
		(val = getenv("LANG")) && *val ||
		(val = "C.UTF-8");
	}

	/* Limit name length and forbid leading dot or any slashes. */
	for (n=0; n<LOCALE_NAME_MAX && val[n] && val[n]!='/'; n++);
	if (val[0]=='.' || val[n]) val = "C.UTF-8";
	int builtin = (val[0]=='C' && !val[1])
		|| !strcmp(val, "C.UTF-8")
		|| !strcmp(val, "POSIX");

	if (builtin) {
		if (cat == LC_CTYPE && val[1]=='.')
			return (void *)&__c_dot_utf8;
		return 0;
	}

	/* For LC_CTYPE, never return a null pointer unless the
	 * requested name was "C" or "POSIX". */
	if (!new && cat == LC_CTYPE) new = (void *)&__c_dot_utf8;

	return new;
}
