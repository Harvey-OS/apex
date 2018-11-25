#include "libc.h"
#include "sys9.h"

static void dummy(void) {}
weak_alias(dummy, _init);
__attribute__((__weak__, __visibility__("hidden")))
extern void (*const __init_array_start)(void), (*const __init_array_end)(void);

static void libc_start_init(void)
{
	_init();
	uintptr_t a = (uintptr_t)&__init_array_start;
	for (; a<(uintptr_t)&__init_array_end; a+=sizeof(void(*)()))
		(*(void (**)())a)();
}

weak_alias(libc_start_init, __libc_start_init);

int __libc_start_main(int (*main)(int,char **,char **), int argc, char **argv)
{
	_envsetup();
	__libc_start_init();

	/* Pass control to the application */
	exit(main(argc, argv, __environ));
	return 0;
}
