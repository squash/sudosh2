#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.5)
AC_INIT(sudosh2, [1.0.6], [josh@shortcutsolutions.net])
AC_CONFIG_SRCDIR([src/])
AC_CANONICAL_SYSTEM

# Override default
test "$sysconfdir" = '${prefix}/etc' && sysconfdir='/etc'

AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE(sudosh2, 1.0.6)
AC_PROG_CC

recordinput=0
AC_MSG_CHECKING(to see if you want to log input too)
AC_ARG_ENABLE(recordinput,
[  --enable-recordinput   Enable recording of input keystrokes, default off],
[recordinput=1])
if test $recordinput = "1"; then
  AC_MSG_RESULT(yes)
AC_DEFINE_UNQUOTED(RECORDINPUT,"$recordinput",[input will be recorded])
else
  AC_MSG_RESULT(no)
fi

logdir=
AC_MSG_CHECKING(for logdir)
AC_ARG_WITH(logdir,
[  --with-logdir=PATH      specify path where logfiles will be written],
[
  if test "x$withval" != "x" ; then
    logdir=$withval
  fi
])
if test "x$logdir" = "x" ; then
  case "$host_os" in
    *linux*)
      logdir="/var/log/sudosh"
      ;;
    *solaris*)
      logdir="/var/adm/sudosh"
      ;;
    *hp*)
      logdir="/var/adm/sudosh"
      ;;
    *aix*)
      logdir="/var/adm/sudosh"
      ;;
    *)
      logdir="/tmp/sudosh"
      ;;
  esac
fi
AC_MSG_RESULT($logdir)
AC_DEFINE_UNQUOTED(LOGDIR,"$logdir",[directory for session output])

# Check for /etc/shells
etcshells=
AC_MSG_CHECKING(for /etc/shells)
if test -f /etc/shells; then
  AC_MSG_RESULT(found)
  AC_DEFINE(HAS_ETC_SHELLS, 1,[have /etc/shells])
else
  AC_MSG_RESULT(not found)
  AC_DEFINE(HAS_ETC_SHELLS, 0,[does not have /etc/shells])
fi


# Checks for libraries.
if test "x$prefix" = "xNONE" ; then
    prefix="/usr/local"
    prefix_nondefault="NONE"
fi

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC

AC_CHECK_HEADERS(unistd.h stdlib.h string.h errno.h stdarg.h stdio.h)
AC_CHECK_HEADERS(sgtty.h pty.h signal.h time.h sys/time.h fcntl.h stropts.h)
AC_CHECK_HEADERS(util.h termios.h sys/termios.h sys/types.h libutil.h)
AC_CHECK_HEADERS(features.h sys/ioctl.h pwd.h syslog.h usersec.h)
AC_CHECK_HEADERS(limits.h sys/stat.h sys/param.h dirent.h ctype.h strings.h)

AC_CHECK_FUNCS(openpty, openpty=1, openpty=0)
AC_CHECK_FUNCS([getusershell gettimeofday])
AC_CHECK_FUNCS([mkdir rmdir])
AC_CHECK_FUNCS([setpenv])
AC_CHECK_FUNCS([atoi sscanf open read close fflush fclose fopen fread fputs fprintf])
AC_CHECK_FUNCS([strncpy snprintf strcmp strlen strftime isspace localtime])
AC_CHECK_FUNCS([opendir readdir closedir])
AC_CHECK_FUNCS([memchr memmove memset select strrchr bzero])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_FORK
AC_PROG_GCC_TRADITIONAL
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL

VLOGDIR=$logdir
VFDL=$filedelimit
PREFIX=$prefix
RECORDINPUT=$recordinput
AC_SUBST([RECORDINPUT])
AC_SUBST([VLOGDIR])
AC_SUBST([VFDL])
AC_SUBST([PREFIX])

AC_DEFINE_UNQUOTED(SYSCONFDIR,"$sysconfdir", [directory to place sudosh.conf])
AC_CONFIG_FILES([Makefile src/Makefile src/sudosh.conf sudosh.1 sudosh-replay.8 sudosh.conf.5])
CFLAGS="$CFLAGS -Werror"
AC_OUTPUT

temp_mandir=`eval echo $mandir` ; temp_mandir=`eval echo $temp_mandir`

echo "Configuration summary:"
echo "======================"
echo ""
echo "  Host type................: $target"
echo "  CC.......................: $CC"
echo "  CFLAGS...................: $CFLAGS"
echo ""
echo "  Package..................: $PACKAGE_NAME"
echo "  Version..................: $VERSION"
echo ""
echo "  Installation prefix......: $prefix"
echo "  Man directory............: $temp_mandir"
echo "  sysconfdir...............: $sysconfdir"
echo -n "  recording input..........: "
if test $recordinput = "1"; then
echo "yes"
else
echo "no"
fi
echo ""
echo "If this summary looks good, type 'make' or 'gmake' to compile"
echo "then 'make install' or 'gmake install' as root to install the"
echo "programs to the above installation prefix."
