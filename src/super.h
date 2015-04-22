/*
sudosh - sudo shell that records sessions as if it were a VCR

Copyright 2004 and $Date: 2007/12/21 21:03:26 $
                Douglas Richard Hanks Jr.

Licensed under the Open Software License version 2.0

This program is free software; you can redistribute it
and/or modify it under the terms of the Open Software
License, version 2.0 by Lauwrence E. Rosen.

This program is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the Open Software License for details.
*/

#include "config.h"

#ifdef __STRICT_ANSI__
#ifdef HAVE_FEATURES_H
#include <features.h>
#endif				/* HAVE_FEATURES */
#define __USE_POSIX
#define __USE_BSD
#define __USE_MISC
#endif				/* __STRICT_ANSI__ */
#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif				/* HAVE_STDIO_H */
#ifdef HAVE_STDARG_H
#include <stdarg.h>
#endif				/* HAVE_STDARG_H */
#ifdef HAVE_STRING_H
#include <string.h>
#else
#  ifdef HAVE_STRINGS_H
#    include <strings.h>
#  endif			/* HAVE_STRINGS_H */
#endif				/* HAVE_STRING_H */
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif				/* HAVE_STDLIB_H */
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif				/* HAVE_ERRNO_H */
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif				/* HAVE_STDLIB_H */
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif				/* HAVE_UNISTD_H */
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif				/* HAVE_SYS_TYPES_H */
#ifdef TIME_WITH_SYS_TIME
#include <time.h>
#include <sys/time.h>
#else				/* TIME_WITH_SYS_TIME */
#ifdef HAVE_TIME_H
#include <time.h>
#endif				/* HAVE_TIME_H */
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif				/* HAVE_SYS_TIME_H */
#endif				/* TIME_WITH_SYS_TIME */
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif				/* HAVE_SYS_STAT_H */
#ifdef HAVE_TERMIOS_H
#include <termios.h>
#endif				/* HAVE_TERMIOS_H */
#ifdef HAVE_UTIL_H
#include <util.h>
#endif				/* HAVE_UTIL_H */
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif				/* HAVE_SYS_TYPES_H */
#ifdef HAVE_LIBUTIL_H
#include <libutil.h>
#endif				/* HAVE_LIBUTIL_H */
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif				/* HAVE_SYS_IOCTL_H */
#ifdef HAVE_STROPTS_H
#include <stropts.h>
#endif				/* HAVE_STROPTS_H */
#ifdef HAVE_SYS_TERMIO_H
#include <sys/termio.h>
#endif				/* HAVE_SYS_TERMIO_H */
#ifdef HAVE_PTY_H
#include <pty.h>
#endif				/* HAVE_PTY_H */
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif				/* HAVE_FCNTL_H */
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif				/* HAVE_SIGNAL_H */
#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif				/* HAVE_SYSLOG_H */
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif				/* HAVE_PWD_H */
#ifdef HAVE_USERSEC_H
#include <usersec.h>
#endif				/*  HAVE_USERSEC_H */
#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif				/*  HAVE_DIRENT_H */
#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif				/*  HAVE_CTYPE_H */

#ifndef SIGCHLD
#define SIGCHLD SIGCLD
#endif

#ifndef TRUE
#define TRUE (1==1)
#endif

#ifndef FALSE
#define FALSE (!TRUE)
#endif
