dnl
dnl $ Id: $
dnl

PHP_ARG_ENABLE(NSTest, whether to enable NSTest functions,
[  --enable-NSTest         Enable NSTest support])

if test "$PHP_NSTEST" != "no"; then
  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_NSTEST"

  AC_MSG_CHECKING(PHP version)
  AC_TRY_COMPILE([#include <php_version.h>], [
#if PHP_VERSION_ID < 50000
#error  this extension requires at least PHP version 5.0.0
#endif
],
[AC_MSG_RESULT(ok)],
[AC_MSG_ERROR([need at least PHP 5.0.0])])

  export CPPFLAGS="$OLD_CPPFLAGS"


  PHP_SUBST(NSTEST_SHARED_LIBADD)
  AC_DEFINE(HAVE_NSTEST, 1, [ ])

  PHP_NEW_EXTENSION(NSTest, NSTest.c , $ext_shared)

fi

