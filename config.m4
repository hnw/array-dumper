dnl $Id$
dnl config.m4 for extension arraydumper

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(arraydumper, for arraydumper support,
dnl Make sure that the comment is aligned:
dnl [  --with-arraydumper             Include arraydumper support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(arraydumper, whether to enable arraydumper support,
Make sure that the comment is aligned:
[  --enable-arraydumper           Enable arraydumper support])

if test "$PHP_ARRAYDUMPER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-arraydumper -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/arraydumper.h"  # you most likely want to change this
  dnl if test -r $PHP_ARRAYDUMPER/$SEARCH_FOR; then # path given as parameter
  dnl   ARRAYDUMPER_DIR=$PHP_ARRAYDUMPER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for arraydumper files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       ARRAYDUMPER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$ARRAYDUMPER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the arraydumper distribution])
  dnl fi

  dnl # --with-arraydumper -> add include path
  dnl PHP_ADD_INCLUDE($ARRAYDUMPER_DIR/include)

  dnl # --with-arraydumper -> check for lib and symbol presence
  dnl LIBNAME=arraydumper # you may want to change this
  dnl LIBSYMBOL=arraydumper # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ARRAYDUMPER_DIR/$PHP_LIBDIR, ARRAYDUMPER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_ARRAYDUMPERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong arraydumper lib version or lib not found])
  dnl ],[
  dnl   -L$ARRAYDUMPER_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(ARRAYDUMPER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(arraydumper, arraydumper.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
