#include "stdio_impl.h"
#include <wchar.h>

wint_t getwchar(void)
{
	return fgetwc(stdin);
}

