/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/limits.h>

extern char **environ;

int execlp(const char *file, const char *argv0, ...)
{
	int argc, n;
	char buf[PATH_MAX]; // old bug
	va_list ap;
	va_start(ap, argv0);
	for (argc=1; va_arg(ap, const char *); argc++);
	va_end(ap);
	argc = argc + 2; // Allocating space for environ pointer
	{
		int i;
		char *argv[argc+1];
		va_start(ap, argv0);
		argv[0] = (char *)argv0;
		for (i=1; i<argc; i++) {
			argv[i] = va_arg(ap, char *);
			if(i == argc - 1)
				argv[i] = (char *)environ;
		}
		argv[i] = NULL;
		va_end(ap);
		/*
 		 * BUG: instead of looking at PATH env variable,
 	 	 * just try prepending /bin/ if name fails...
 	 	 */
		if((n = execvp(file, argv)) < 0) {
			strcpy(buf, "/bin/");
			strcpy(buf+5, file);
			n = execvp(file, argv);
		}
		return n;
	}
}
